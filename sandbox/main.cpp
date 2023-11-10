/**
 * @file main.cpp
 * @author "Melvin van Bree"
 * @brief TODO
 * @version 0.1
 * @date 10/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "core/engine.hpp"
#include "managers/scene_manager.hpp"
#include <iostream>

class TestScene : public Scene
{
  public:
    TestScene() = default;
    ~TestScene() override = default;

    void RenderScene() override
    {
        std::cout << "Test Scene" << std::endl;
    }

    void Update(float deltaTime) override
    {
        std::cout << "Updated Scene" << std::endl;
    }
};

int main(int argc, char *argv[])
{
    std::cout << "Sandbox" << std::endl;

    auto engine = Engine::getInstance();
    auto sceneManager = engine->get<SceneManager>();

    auto scene = std::make_shared<TestScene>();
    sceneManager->SetScene(scene);

    engine->Start();

    return 1;
}