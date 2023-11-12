#include "engine.hpp"
#include "scene_manager.hpp"
#include "time_utility.hpp"
#include <thread>

Engine *Engine::instancePtr = nullptr;

Engine::Engine()
{
    container.registerInstance<SceneManager>(std::make_shared<SceneManager>());
    // TODO: Change to actual facade
    //    privateContainer.registerInstance<IOFacade>(std::make_shared<mock_io_facade>());
}

void Engine::Start()
{
    isRunning = true;
    int frameCount = 0;
    TimeUtility time;
    float lastFPSUpdateTime = time.GetTotalTime();

    while (isRunning)
    {
        float deltaTime = time.GetDeltaTime();

        // Start of the frame
        time.StartFrame();

        // Game logic goes here
        // ...
        Get<SceneManager>()->Update(deltaTime);

        // Render stuff goes here
        // ...

        // End of the frame

        // Calculate FPS
        frameCount++;
        if (time.GetTotalTime() - lastFPSUpdateTime >= 1.0f)
        {
            currentFPS = frameCount;
            frameCount = 0;
            lastFPSUpdateTime = time.GetTotalTime();
        }

        // Frame limiting
        float elapsedMs = time.GetElapsedTimeSinceFrameStart();
        float targetMs = 1000.0f / FPS_LIMIT;
        if (targetMs > elapsedMs)
        {
            // TODO: Place in IOFacade
            SDL_Delay(static_cast<unsigned int>(targetMs - elapsedMs));
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

template <typename T> std::shared_ptr<T> Engine::GetLocal()
{
    return container.resolve<T>(InstanceScope::Engine);
}

template <typename T> std::shared_ptr<T> Engine::Get() { return container.resolve<T>(); }
