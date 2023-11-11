/**
 * @file main.cpp
 * @author "Melvin van Bree"
 * @brief Sandbox is used to test stuff temporarily
 * @version 0.1
 * @date 10/11/2023
 *
 * @copyright Copyright (c) 2023
 * @details `development/` should have an empty main entry point. This is used to test stuff temporarily.
 */

#include "core/engine.hpp"
#include "managers/scene_manager.hpp"
#include <iostream>

class TestScene : public Scene
{
  private:
    int tick = 0;
  public:
    TestScene() = default;
    ~TestScene() override = default;

    void RenderScene() override
    {
        std::cout << "Test Scene" << std::endl;
    }

    void Update(float deltaTime) override
    {
        auto fps = Engine::GetInstance()->GetFPS();
        std::cout << "Update: " << tick << std::endl;
        std::cout << "Delta Time: " << deltaTime << std::endl;
        std::cout << "FPS: " << fps << std::endl;
        tick++;
    }
};

int main(int argc, char *argv[])
{
    std::cout << "Sandbox" << std::endl;

    auto engine = Engine::GetInstance();
    auto sceneManager = engine->Get<SceneManager>();

    auto scene = std::make_shared<TestScene>();
    sceneManager->SetScene(scene);

    engine->Start();

    return 1;
}