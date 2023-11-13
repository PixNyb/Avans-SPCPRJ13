/**
 * @file engine.hpp
 * @author "Melvin van Bree"
 * @brief Engine is the core of the engine. It is responsible for managing the game loop and managing the DIContainer.
 * @version 0.1
 * @date 10/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef AVANS_SPCPRJ13_ENGINE_HPP
#define AVANS_SPCPRJ13_ENGINE_HPP

#include "core_constants.hpp"
#include <di_container.hpp>
#include <iostream>
#include <memory>

class Engine
{
  private:
    /**
     * @brief Construct a new Engine object
     *
     * Is responsible for creating a usable engine instance
     */
    Engine();

    /**
     * @brief The instance of the engine
     */
    static Engine *instancePtr;

    /**
     * @brief The container is used to store public or private instances for the game dev like SceneManager etc.
     */
    DIContainer container;

    /**
     * @brief Checks if the engine is running
     */
    bool isRunning = false;

    /**
     * @brief The FPS of the engine
     */
    float FPS_LIMIT = CoreConstants::Engine::DEFAULT_FPS;
    int currentFPS = 0;

  public:
    Engine(Engine &other) = delete;
    void operator=(const Engine &) = delete;

    /**
     * @brief Gets a public available instance (like SceneManager)
     * @tparam T The type of the instance
     * @return std::shared_ptr<T>
     */
    template <typename T>
    std::shared_ptr<T> Get();

    /**
     * @brief Gets a locally scoped instance for the engine (like facades)
     * @tparam T The type of the instance
     * @return std::shared_ptr<T>
     */
    template <typename T>
    std::shared_ptr<T> GetLocal();

    /**
     * @brief Gets the instance of the engine
     * @return Engine*
     */
    static Engine *GetInstance()
    {
        if (!instancePtr) {
            instancePtr = new Engine();
        }
        return instancePtr;
    }

    /**
     * @brief Starts the game loop
     */
    void Start();

    /**
     * @brief Stops the game loop
     */
    void Stop();

    /**
     * @brief Shuts down the engine
     * @details Calls stop and cleans up the engine
     */
    void Shutdown();

    /**
     * @brief Gets the FPS of the engine
     * @return int
     */
    int GetFPS() const;

    /**
     * @brief Sets the FPS of the engine
     * @param fps The FPS to set
     */
    void SetFPSLimit(float fps);
};

#endif // AVANS_SPCPRJ13_ENGINE_HPP
