/**
 * @file engine.cpp
 * @author Melvin van Bree
 * @brief Implementation of the Engine class for the core game engine functionalities.
 * @version 0.1
 * @date 2023-11-10
 *
 * This file contains the implementation of the Engine class, which is central to the game engine's operation.
 * The Engine class manages the game loop, rendering process, and scene management. It also provides
 * utilities for frame timing and FPS calculation. The Engine ensures the cohesive operation of different
 * engine components, including IO and graphics, and manages the game's running state.
 *
 * Copyright Copyright (c) 2023
 *
 */

#include "engine.hpp"
#include "scene_manager.hpp"
#include "io_facade.hpp"
#include "graphics_facade.hpp"
#include "time_utility.hpp"
#include <thread>

Engine* Engine::instancePtr = nullptr;

Engine::Engine() {
    container.registerInstance<SceneManager>(std::make_shared<SceneManager>());
    container.registerInstance<IOFacade>(std::make_shared<GraphicsFacade>(), InstanceScope::Engine);
}

void Engine::Start()
{
    isRunning = true;
    int frameCount = 0;
    TimeUtility time;
    float lastFPSUpdateTime = time.GetTotalTime();
    auto graphicsFacade = GetLocal<IOFacade>();

    if (!graphicsFacade) {
        std::cerr << "GraphicsFacade instance is null" << std::endl;
        return;
    }
    graphicsFacade->Init();

    while (isRunning) {
        float deltaTime = time.GetDeltaTime();

        // Start of the frame
        time.StartFrame();

        // Game logic goes here
        // ...
        Get<SceneManager>()->Update(deltaTime);

        // Render stuff goes here
        graphicsFacade->ClearScreen();
        graphicsFacade->PresentScreen();

        // End of the frame

        // Calculate FPS
        frameCount++;
        if (time.GetTotalTime() - lastFPSUpdateTime >= 1.0f) {
            currentFPS = frameCount;
            frameCount = 0;
            lastFPSUpdateTime = time.GetTotalTime();
        }

        // Frame limiting
        float elapsedMs = time.GetElapsedTimeSinceFrameStart();
        float targetMs = 1000.0f / FPS_LIMIT;
        if (targetMs > elapsedMs)
        {
            graphicsFacade->Delay(static_cast<unsigned int>(targetMs - elapsedMs));
        }
    }
}

void Engine::Stop() {
    isRunning = false;
}

void Engine::Shutdown() {
    Stop();

    if(auto sceneManager = Get<SceneManager>(); sceneManager != nullptr)
        sceneManager->ClearScene();
}

int Engine::GetFPS() const {
    return currentFPS;
}

void Engine::SetFPSLimit(float fps) {
    FPS_LIMIT = fps;
}

Engine *Engine::GetInstance() {
    if (!instancePtr) {
        instancePtr = new Engine();
    }
    return instancePtr;
}

template <typename T> std::shared_ptr<T> Engine::GetLocal()
{
    return container.resolve<T>(InstanceScope::Engine);
}

template <typename T> std::shared_ptr<T> Engine::Get() {
    return container.resolve<T>();
}

