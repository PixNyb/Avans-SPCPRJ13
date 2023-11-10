/**
 * @file engine.hpp
 * @author "Melvin van Bree"
 * @brief TODO
 * @version 0.1
 * @date 10/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef AVANS_SPCPRJ13_ENGINE_HPP
#define AVANS_SPCPRJ13_ENGINE_HPP

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
     * @brief The public container is used to store public instances for the game dev like SceneManager etc.
     */
    DIContainer publicContainer;
    /**
     * @brief The private container is used to store private instances for the game dev like facades.
     */
    DIContainer privateContainer;

    /**
     * @brief Checks if the engine is running
     */
    bool isRunning = false;

    /**
     * @brief The FPS of the engine
     */
    float FPS_LIMIT = 60;
    int currentFPS = 0;

    /**
     * @brief Gets a privately available instance (like facades)
     * @tparam T The type of the instance
     * @return std::shared_ptr<T>
     */
    template <typename T>
    std::shared_ptr<T> getPrivate();

  public:
    Engine(Engine &other) = delete;
    void operator=(const Engine &) = delete;

    /**
     * @brief Gets a public available instance (like SceneManager)
     * @tparam T The type of the instance
     * @return std::shared_ptr<T>
     */
    template <typename T>
    std::shared_ptr<T> get();

    /**
     * @brief Gets the instance of the engine
     * @return Engine*
     */
    static Engine *getInstance()
    {
        if (instancePtr == nullptr)
        {
            instancePtr = new Engine();
            return instancePtr;
        }

        return instancePtr;
    }


    void Start();
};

#endif // AVANS_SPCPRJ13_ENGINE_HPP
