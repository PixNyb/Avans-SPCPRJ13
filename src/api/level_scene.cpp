/**
 * @file level_scene.hpp
 * @author Maxuuuu
 * @brief Implementation of the LevelScene class.
 * @version 0.1
 * @date 20/11/2023
 *
 * @copyright Copyright (c) 2023
 */

#include "level_scene.hpp"

void LevelScene::RenderScene() {}

void LevelScene::Update(double deltaTime)
{
    auto camera = this->GetCamera();
    std::string searchString = "Player";
    auto playerObject = std::find_if(contents.begin(), contents.end(),
                                     [&searchString](const std::shared_ptr<GameObject> &obj)
                                     { return obj->GetName() == searchString; });
    auto transform = camera->GetTransform();
    transform.position.x = playerObject->get()->GetTransform().position.x;
    transform.position.y = playerObject->get()->GetTransform().position.y - 100;
    camera->SetTransform(transform);
}
