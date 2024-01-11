/**
 * @file behaviour_script_manager.cpp
 * @author "Melvin van Bree"
 * @brief Manager that updates all behaviour scripts.
 * @version 0.1
 * @date 15/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "behaviour_script_manager.hpp"
#include "behaviour_script.hpp"
#include "core/engine.hpp"
#include "game_object.hpp"
#include "game_object_utility.hpp"
#include "managers/scene_manager.hpp"

BehaviourScriptManager::BehaviourScriptManager() = default;
BehaviourScriptManager::~BehaviourScriptManager() = default;

bool BehaviourScriptManager::shouldExecute = true;

void BehaviourScriptManager::Update()
{
    auto engine = Engine::GetInstance();
    auto sceneManager = engine->Get<SceneManager>();
    if (!sceneManager->HasScene())
        return;
    auto scene = sceneManager->GetScene().lock();
    if (!scene)
        return;

    auto sceneGameObjects = scene->GetAllByType<GameObject>();
    for (auto &sceneGameObject : sceneGameObjects)
    {
        auto gameObject = sceneGameObject.lock();
        if (gameObject == nullptr)
            continue;

        // Execute script recursively
        if (shouldExecute) {
            GameObjectUtility::TraverseActiveGameObjects(
                gameObject,
                [](const std::shared_ptr<GameObject> &gameObject) { ExecuteScript(*gameObject); });
        }
    }
    Engine::GetInstance()->Get<BehaviourScriptManager>()->shouldExecute = true;
}
void BehaviourScriptManager::ExecuteScript(GameObject &gameObject)
{
    auto scripts = gameObject.GetComponents<BehaviourScript>();
    for (auto &script : scripts)
    {
        if (shouldExecute){
            if (!script || !script->IsActive())
                continue;

            if (!script->HasStarted())
                script->OnStart();

            script->OnUpdate();
        }

    }
}
