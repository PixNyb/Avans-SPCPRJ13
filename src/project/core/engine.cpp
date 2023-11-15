#include "engine.hpp"
#include "behaviour_script_manager.hpp"
#include "graphics_facade.hpp"
#include "render_manager.hpp"
#include "scene_manager.hpp"
#include "time.hpp"
#include <thread>

Engine* Engine::instancePtr = nullptr;

Engine::Engine() {
    container.registerInstance<SceneManager>(std::make_shared<SceneManager>());
    // TODO: Figure out the scope?
    container.registerInstance<IOFacade>(std::make_shared<GraphicsFacade>());
    container.registerInstance<RenderManager>(std::make_shared<RenderManager>(),InstanceScope::Engine);
    container.registerInstance<BehaviourScriptManager>(std::make_shared<BehaviourScriptManager>(),InstanceScope::Engine);
}

void Engine::Start()
{
    isRunning = true;
    int frameCount = 0;
    double lastFPSUpdateTime = Time::GetTotalTime();
    auto graphicsFacade = Get<IOFacade>();

    if (!graphicsFacade) {
        std::cerr << "GraphicsFacade instance is null" << std::endl;
        return;
    }

    graphicsFacade->Init();

    while (isRunning) {
        double deltaTime = Time::GetDeltaTime();

        // Start of the frame
        Time::StartFrame();

        // Game logic goes here


        // TODO: Remove
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
        }

        Get<SceneManager>()->Update(deltaTime);
        Get<BehaviourScriptManager>()->Update();

        // Render stuff goes here
        graphicsFacade->ClearScreen();
        Get<RenderManager>()->Render();
        graphicsFacade->PresentScreen();

        // End of the frame

        // Calculate FPS
        frameCount++;
        if (Time::GetTotalTime() - lastFPSUpdateTime >= 1.0f) {
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