/**
 * @file RenderManager.cpp
 * @author "Melvin van Bree"
 * @brief TODO
 * @version 0.1
 * @date 14/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "render_manager.hpp"
#include "box_collider.hpp"
#include "camera.hpp"
#include "circle.hpp"
#include "circle_collider.hpp"
#include "core/engine.hpp"
#include "game_object.hpp"
#include "graphics_facade.hpp"
#include "managers/scene_manager.hpp"
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

    if(!sceneManager->HasScene()) return;

    // During the process, we might want to take temp partial ownership
    auto scene = sceneManager->GetScene().lock();
    if(!scene) return;

    // Prepare camera
    auto camera = scene->GetCamera();

    // Prepare layers
    auto layers = std::map<int, std::vector<std::weak_ptr<GameObject>>>();

    for(auto& gameObject : scene->GetAllByType<GameObject>()){
        auto gameObjectPtr = gameObject.lock();
        if(!gameObjectPtr || !gameObjectPtr->IsActive()) continue;

        int layer = gameObjectPtr->GetLayer();
        if(layers.contains(layer)){
            // Ensure the layer for the game object exists
            layers.insert(std::make_pair(layer, std::vector<std::weak_ptr<GameObject>>()));
        }

        // TODO: Check game objects with geometry for render occlusion

        // Push game object onto layer
        layers[layer].push_back(gameObject);
    }

    // Make sure we have a render point regardless of whether we have a camera (menu might not
    // always have a camera)
    Point renderPoint = Point(0, 0);
    if(camera){
        auto transform = camera->GetTransform();
        renderPoint.x = transform.position.x;
        renderPoint.y = transform.position.y;
        renderPoint.x -= camera->GetAspectWidth() / 2;
        renderPoint.y -= camera->GetAspectHeight() / 2;
    }

    // Go through layers in-order (lowest to highest)
    for (const auto& layer : layers) {
        int layerIndex = layer.first;
        auto& gameObjects = layer.second;

        for(auto& gameObject : gameObjects){
            auto gameObjectPtr = gameObject.lock();
            if(!gameObjectPtr || !gameObjectPtr->IsActive()) continue;
            // Delegate to private render method
            Render(*graphicsFacade, renderPoint, gameObjectPtr);
        }
    }
}

void RenderManager::Render(IOFacade &gfx, const Point &cameraPoint, const
                           std::weak_ptr<GameObject>& gameObjectPointer) {

    auto gameObject = gameObjectPointer.lock();

    // Calculate relative camera position
    auto relCamPos = gameObject->GetTransform().position - cameraPoint;
    double scale = gameObject->GetTransform().scale;

    // TODO: Don't try to draw objects that are out of bounds? Purely for efficiency, shouldn't
    //  really matter for now

    // Draw sprites
    auto sprite = gameObject->GetComponent<Sprite>();
    if (sprite) {

    }

    auto text = dynamic_pointer_cast<Text>(gameObject);
    if(text) {
        gfx.DrawText(*text);
    }

    // Draw collider shapes
    if (CoreConstants::Debug::EnableDebug && CoreConstants::Debug::DrawColliders) {
        auto circleColliderShape = gameObject->GetComponent<CircleCollider>();
        if (circleColliderShape) {
            // Draw collider
            double radius = circleColliderShape->Radius();

            // Draw the collider shape with the correct position
            auto shape = Circle(Vector2D(relCamPos.x, relCamPos.y), radius * scale);
            shape.SetFillColor(Color::red());
            gfx.DrawShape(shape);
        }

        auto boxColliderShape = gameObject->GetComponent<BoxCollider>();
        if (boxColliderShape) {
            // Draw collider
            double width = boxColliderShape->Width();
            double height = boxColliderShape->Height();

            // Draw the collider shape with the correct position
            auto shape = Rectangle(Vector2D(relCamPos.x, relCamPos.y), width * scale, height *scale);
            shape.SetFillColor(Color::blue());
            gfx.DrawShape(shape);
        }
    }
}