/**
 * @file RenderManager.cpp
 * @author "Melvin van Bree"
 * @brief Manager for rendering game objects
 * @version 0.1
 * @date 14/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "render_manager.hpp"
#include "animator.hpp"
#include "box_collider.hpp"
#include "circle.hpp"
#include "circle_collider.hpp"
#include "core/engine.hpp"
#include "game_object.hpp"
#include "game_object_utility.hpp"
#include "graphics_facade.hpp"
#include "managers/scene_manager.hpp"
#include "shape_component.hpp"
#include "shape_renderer.hpp"
#include "text.hpp"
#include <map>
#include <sprite.hpp>

RenderManager::RenderManager() = default;
RenderManager::~RenderManager() = default;

void RenderManager::Render()
{
    auto engine = Engine::GetInstance();
    auto sceneManager = engine->Get<SceneManager>();
    auto graphicsFacade = engine->Get<IOFacade>();
    auto shapeRenderer = std::make_shared<ShapeRenderer>(graphicsFacade);

    if (!sceneManager->HasScene())
        return;

    // During the process, we might want to take temp partial ownership
    auto scene = sceneManager->GetScene().lock();
    if (!scene)
        return;

    auto layers = std::map<int, std::vector<std::weak_ptr<GameObject>>>();

    for (auto &gameObjectPtr : scene->GetAllByType<GameObject>())
    {
        auto gameObject = gameObjectPtr.lock();
        GameObjectUtility::TraverseActiveGameObjects(
            gameObject,
            [&layers](const std::shared_ptr<GameObject> &gameObject)
            {
                int layer = gameObject->GetLayer();
                layers[layer].emplace_back(gameObject);
            });
    }

    // Make sure we have a render point regardless of whether we have a camera (menu might not
    // always have a camera)
    Point renderPoint = Point(0, 0);

    // Prepare camera
    auto camera = scene->GetCamera();
    if (camera)
    {
        // Apply camera transform
        auto transform = camera->GetTransform();
        renderPoint.x = transform.position.x;
        renderPoint.y = transform.position.y;
        renderPoint.x -= camera->GetAspectWidth() / 2;
        renderPoint.y -= camera->GetAspectHeight() / 2;
    }

    // Go through layers in-order (lowest to highest)
    for (const auto &layer : layers)
    {
        int layerIndex = layer.first;
        auto &gameObjects = layer.second;

        for (auto &gameObject : gameObjects)
        {
            auto gameObjectPtr = gameObject.lock();
            if (!gameObjectPtr || !gameObjectPtr->IsActive())
                continue;
            // Delegate to private render method
            Render(*graphicsFacade, *shapeRenderer, renderPoint, gameObjectPtr);
        }
    }
}

void RenderManager::Render(IOFacade &gfx, ShapeRenderer &shapeRenderer, const Point &cameraPoint,
                           const std::weak_ptr<GameObject> &gameObjectPointer)
{

    auto gameObject = gameObjectPointer.lock();
    if (!gameObject)
    {
        return; // GameObject is no longer valid
    }

    // Determine final position and scale based on parent (if any)
    Transform finalTransform = gameObject->GetTransform();
    if (auto parent = gameObject->GetParent())
    {
        finalTransform = finalTransform.operator+(parent->GetTransform());
    }

    // Calculate relative camera position
    auto relCamPos = finalTransform.position - cameraPoint;
    double scale = gameObject->GetTransform().scale;

    // TODO: Don't try to draw objects that are out of bounds? Purely for efficiency, shouldn't
    //  really matter for now

    // Draw sprites
    auto spriteComponent = gameObject->GetComponent<Sprite>();
    if (spriteComponent)
    {
        auto animatorComponent = gameObject->GetComponent<Animator>();

        // Adjust sprite size to match parent's dimensions (if parent has a collider)
        Size parentSize;
        if (auto boxCollider = gameObject->GetComponent<BoxCollider>())
        {
            parentSize = Size(boxCollider->Width(), boxCollider->Height());
        }
        else if (auto circleCollider = gameObject->GetComponent<CircleCollider>())
        {
            double radius = circleCollider->Radius();
            parentSize = Size(radius * 2, radius * 2);
        }
        // Check if gameobject is a UIObject
        else if (std::shared_ptr<UIObject> uiObj = std::dynamic_pointer_cast<UIObject>(gameObject))
        {
            parentSize = Size(uiObj->GetWidth(), uiObj->GetHeight());
        }
        else
        {
            Size spriteSize = spriteComponent->GetTexture()->GetSize();
            // if spriteSize is not set, use the sprite's own size
            if (spriteSize.height == 0 && spriteSize.width == 0)
                spriteSize = gfx.GetSpriteSize(spriteComponent->GetSprite());
            else
                parentSize = Size(spriteSize.height, spriteSize.width);

        }

        // Create a Rectangle object representing the position and size of the sprite
        Rectangle spriteRect(Vector2D(relCamPos.x, relCamPos.y), parentSize.height,
                             parentSize.width);

        if (std::shared_ptr<UIObject> uiObj = std::dynamic_pointer_cast<UIObject>(gameObject))
        {
            if (!uiObj->GetUseRelativePosition())
            {
                auto transform = gameObject->GetTransform().position;
                spriteRect = Rectangle(Vector2D(transform.x, transform.y), parentSize.height,
                                       parentSize.width);
            }
        }

        if (animatorComponent)
        {
            // Handling sprite sheets with Animator
            int currentFrameIndex = animatorComponent->GetCurrentFrameIndex();
            int totalColumns = animatorComponent->GetTotalColumns();
            int totalRows = animatorComponent->GetTotalRows();

            gfx.DrawSpriteSheetFrame(spriteComponent->GetSprite(), spriteRect, currentFrameIndex,
                                     totalColumns, totalRows,
                                     gameObjectPointer.lock()->GetComponent<Sprite>()->IsFlippedX(),
                                     gameObjectPointer.lock()->GetComponent<Sprite>()->IsFlippedY(),
                                     gameObjectPointer.lock()->GetTransform().rotation,
                                     gameObjectPointer.lock()->GetTransform().scale);
        }
        else
        {
            // Create a Texture object for the sprite
            Texture spriteTexture(spriteComponent->GetSprite());

            // Draw the sprite
            gfx.DrawSprite(spriteTexture, spriteRect,
                           gameObjectPointer.lock()->GetComponent<Sprite>()->IsFlippedX(),
                           gameObjectPointer.lock()->GetComponent<Sprite>()->IsFlippedY(),
                           gameObjectPointer.lock()->GetTransform().rotation,
                           gameObjectPointer.lock()->GetTransform().scale);
        }
    }

    auto shapeComponent = gameObject->GetComponent<ShapeComponent>();
    if (shapeComponent)
    {
        for (auto &shape : shapeComponent->GetGeometries())
        {
            if (shapeComponent->DoTranslate())
            {
                shape->SetTranslation(
                    {static_cast<float>(relCamPos.x), static_cast<float>(relCamPos.y)});
            }
            else
            {
                // TODO: Perhaps do stuff like this more lazily
                auto gameObjectTransform = gameObject->GetTransform();
                shape->SetTranslation({static_cast<float>(gameObjectTransform.position.x),
                                       static_cast<float>(gameObjectTransform.position.y)});
            }
            shape->Accept(shapeRenderer);
        }
    }

    auto text = dynamic_pointer_cast<Text>(gameObject);
    if (text)
    {
        gfx.DrawText(*text);
    }

    // Draw collider shapes
    if (CoreConstants::Debug::EnableDebug && CoreConstants::Debug::DrawColliders &&
        !spriteComponent)
    {
        auto circleColliderShape = gameObject->GetComponent<CircleCollider>();
        if (circleColliderShape)
        {
            // Draw collider
            double radius = circleColliderShape->Radius();

            // Draw the collider shape with the correct position
            auto shape = Circle(Vector2D(relCamPos.x, relCamPos.y), radius * scale);
            shape.SetFillColor(Color::Red());
            gfx.DrawShape(shape);
        }

        auto boxColliderShape = gameObject->GetComponent<BoxCollider>();
        if (boxColliderShape)
        {
            // Draw collider
            double width = boxColliderShape->Width();
            double height = boxColliderShape->Height();

            // Draw the collider shape with the correct position
            auto shape =
                Rectangle(Vector2D(relCamPos.x, relCamPos.y), height * scale, width * scale);
            shape.SetFillColor(Color::Blue());
            gfx.DrawShape(shape);
        }
    }
}