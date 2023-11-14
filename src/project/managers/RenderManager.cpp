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

#include "RenderManager.h"
#include "camera.hpp"
#include "core/engine.hpp"
#include "game_object.hpp"
#include "managers/scene_manager.hpp"
#include <map>
#include <sprite.hpp>
#include "circle_collider.hpp"
#include "box_collider.hpp"

RenderManager::RenderManager() = default;
RenderManager::~RenderManager() = default;

void RenderManager::Render()
{
    auto engine = Engine::GetInstance();
    auto sceneManager = engine->Get<SceneManager>();

    if(!sceneManager->HasScene()) return;

    // During the process, we might want to take temp partial ownership
    auto scene = sceneManager->GetScene().lock();
    if(!scene) return;

    // Prepare camera
    auto cameras = scene->GetAllByType<Camera>();
    std::shared_ptr<Camera> camera = std::make_shared<Camera>();
    if(!cameras.empty()) camera = cameras[0].lock();

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

        // Push game object onto layer
        layers[layer].push_back(gameObject);
    }

    // Make sure we have a render point regardless of whether we have a camera
    Point renderPoint = Point(0, 0);
    if(camera){
        auto transform = camera->GetTransform();
        renderPoint.x = transform.position.x;
        renderPoint.y = transform.position.y;
        // TODO: Calculate offset?
    }

    // Go through layers in-order (lowest to highest)
    for (const auto& layer : layers) {
        int layerIndex = layer.first;
        auto& gameObjects = layer.second;

        for(auto& gameObject : gameObjects){
            auto gameObjectPtr = gameObject.lock();
            if(!gameObjectPtr || !gameObjectPtr->IsActive()) continue;
            Render(renderPoint, *gameObjectPtr);
        }
    }


    // Specialize methods for shapes, sprites, text, etc.
}
void RenderManager::Render(const Point &renderPoint, const GameObject &gameObject) {
    // Draw sprites
    auto sprite = gameObject.GetComponent<Sprite>();
    if(sprite){
        // Draw sprite
        // TODO: Implement sprite
    }

    // Draw collider shapes
    auto circleColliderShape = gameObject.GetComponent<CircleCollider>();
    if(circleColliderShape && CoreConstants::Debug::DrawColliders){
        // Draw collider
        double radius = circleColliderShape->Radius();
        // TODO: Implement circle collider

    }

    auto boxColliderShape = gameObject.GetComponent<BoxCollider>();
    if(boxColliderShape && CoreConstants::Debug::DrawColliders){
        // Draw collider
        double width = boxColliderShape->Width();
        double height = boxColliderShape->Height();
        // TODO: Implement box collider
    }
}
