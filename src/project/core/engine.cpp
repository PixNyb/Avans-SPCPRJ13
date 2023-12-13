/**
 * @file engine.cpp
 * @author Melvin van Bree
 * @brief Implementation of the Engine class for the core game engine functionalities.
 * @version 0.1
 * @date 2023-11-10
 *
 * This file contains the implementation of the Engine class, which is central to the game engine's
 * operation. The Engine class manages the game loop, rendering process, and scene management. It
 * also provides utilities for frame timing and FPS calculation. The Engine ensures the cohesive
 * operation of different engine components, including IO and graphics, and manages the game's
 * running state.
 *
 * Copyright Copyright (c) 2023
 *
 */

#include "engine.hpp"
#include "behaviour_script_manager.hpp"
#include "graphics_facade.hpp"
#include "level_manager.hpp"
#include "pathfinding_manager.hpp"
#include "physics_manager.hpp"
#include "render_manager.hpp"
#include "scene_manager.hpp"
#include "sdl_input_facade.hpp"
#include "time.hpp"
#include <iostream>

Engine *Engine::instancePtr = nullptr;

Engine::Engine()
{
    auto jsonReader = std::make_shared<JSONReader>();
    container.registerInstance<JSONReader>(jsonReader, InstanceScope::Engine);

    // Managers
    auto sceneManager = std::make_shared<SceneManager>();
    container.registerInstance<SceneManager>(sceneManager, InstanceScope::Public);

    auto prefabManager = std::make_shared<PrefabManager>();
    container.registerInstance<PrefabManager>(prefabManager, InstanceScope::Public);

    container.registerInstance<LevelManager>(
        std::make_shared<LevelManager>(sceneManager, prefabManager, jsonReader),
        InstanceScope::Public);

    container.registerInstance<RenderManager>(std::make_shared<RenderManager>(),
                                              InstanceScope::Engine);

    container.registerInstance<BehaviourScriptManager>(std::make_shared<BehaviourScriptManager>(),
                                                       InstanceScope::Engine);

    container.registerInstance<PhysicsManager>(std::make_shared<PhysicsManager>());
    container.registerInstance<PathfindingManager>(std::make_shared<PathfindingManager>());

    // Facades
    container.registerInstance<IInputFacade>(std::make_shared<SDLInputFacade>());
    container.registerInstance<IOFacade>(std::make_shared<GraphicsFacade>());
}

void Engine::Start()
{
    isRunning = true;
    int frameCount = 0;
    double lastFPSUpdateTime = Time::GetTotalTime();
    auto graphicsFacade = Get<IOFacade>();

    if (!graphicsFacade)
    {
        std::cerr << "GraphicsFacade instance is null" << std::endl;
        return;
    }

    graphicsFacade->Init();

    while (isRunning)
    {
        double deltaTime = Time::GetDeltaTime();

        // Start of the frame
        Time::StartFrame();

        Get<PhysicsManager>()->Step();

        Get<IInputFacade>()->Update();

        Get<SceneManager>()->Update(deltaTime);

        Get<BehaviourScriptManager>()->Update();

        graphicsFacade->ClearScreen();
        Get<RenderManager>()->Render();
        Get<PathfindingManager>()->Render();

        graphicsFacade->PresentScreen();

        // Keep this at the end of the frame so the user can execute actions before the engine stops
        if (Get<IInputFacade>()->GetAction("quit"))
            Stop();
        // End of the frame

        // Calculate FPS
        frameCount++;
        if (Time::GetTotalTime() - lastFPSUpdateTime >= 1.0f)
        {
            currentFPS = frameCount;
            frameCount = 0;
            lastFPSUpdateTime = Time::GetTotalTime();
        }

        // Frame limiting
        double elapsedMs = Time::GetElapsedTimeSinceFrameStart();
        double targetMs = 1000.0f / FPS_LIMIT;
        if (targetMs > elapsedMs)
        {
            graphicsFacade->Delay(static_cast<unsigned int>(targetMs - elapsedMs));
        }
    }
}

void Engine::Stop() { isRunning = false; }

void Engine::Shutdown()
{
    Stop();

    if (auto sceneManager = Get<SceneManager>(); sceneManager != nullptr)
        sceneManager->ClearScene();
}

int Engine::GetFPS() const { return currentFPS; }

void Engine::SetFPSLimit(float fps) { FPS_LIMIT = fps; }

Engine *Engine::GetInstance()
{
    if (!instancePtr)
    {
        instancePtr = new Engine();
    }
    return instancePtr;
}
