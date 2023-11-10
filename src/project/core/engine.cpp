#include "engine.hpp"
#include "io_facade.hpp"
#include "scene_manager.hpp"
#include "time_utility.h"
#include <thread>

Engine* Engine::instancePtr = nullptr;

Engine::Engine() {
    publicContainer.registerInstance<SceneManager>(std::make_shared<SceneManager>());
    // TODO: Change to actual facade
//    privateContainer.registerInstance<IOFacade>(std::make_shared<mock_io_facade>());
}

void Engine::Start()
{
    isRunning = true;
    int frameCount = 0;
    TimeUtility time;
    float lastFPSUpdateTime = time.GetTotalTime();

//    auto io = std::dynamic_pointer_cast<mock_io_facade>(getPrivate<IOFacade>());

    while (isRunning) {
        std::cout << std::string(50, '-') << std::endl;

        // Start of the frame
        time.StartFrame();

        // Game logic goes here
        // ...

        // Render stuff goes here
        // ...

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
            // TODO: Place in IOFacade
            SDL_Delay(static_cast<unsigned int>(targetMs - elapsedMs));
//            io->delay(static_cast<unsigned int>(targetMs - elapsedMs));
        }

        std::cout << "FPS: " << currentFPS << std::endl;
        std::cout << "Delta time: " << time.GetDeltaTime() << std::endl;
        std::cout << "Frame time: " << time.GetDeltaTime() * 1000.0f << std::endl;
        std::cout << std::string(50, '-') << std::endl;
    }

    get<SceneManager>()->ClearScene();
}

template <typename T> std::shared_ptr<T> Engine::getPrivate()
{
    return privateContainer.resolve<T>();
}
template <typename T> std::shared_ptr<T> Engine::get() {
    return publicContainer.resolve<T>();
}
