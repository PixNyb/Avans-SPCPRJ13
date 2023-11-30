/**
 * @file sdl_thread.hpp
 * @author Robin Pijnappels (rm.pijnappels@student.avans.nl)
 * @brief This file contains the Thread class definition for abstracting SDL threading.
 * @version 0.1
 * @date 2023-11-08
 *
 * The Thread class provides a simple wrapper around SDL_Thread to facilitate the
 * creation, management, and synchronization of threads within the game engine.
 * It encapsulates common threading operations such as starting, stopping, and pausing threads.
 *
 * @warning Multithreading can introduce complexity and potential issues such as race conditions
 * and deadlocks. Use with care and ensure proper synchronization.
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_THREAD_HPP
#define DEFUNBOBENGINE_THREAD_HPP

#include <SDL.h>
#include <iostream>
#include <string>

/**
 * @class Thread
 * @brief A wrapper class for SDL_Thread to manage threading in the game engine.
 *
 * This class abstracts the details of thread creation and control using SDL's threading
 * capabilities. It provides methods to start, stop, and pause execution of threads and encapsulates
 * the thread callback function within the class scope.
 */
class Thread
{
    SDL_Thread *thread;
    std::string threadName;
    static int ThreadFunction(void *data);

  public:
    explicit Thread(const std::string &name) : thread(nullptr), threadName(name) {}

    /**
     * @brief Destroy the Thread object, ensuring the thread is properly cleaned up.
     */
    ~Thread();

    /**
     * @brief Starts the thread, invoking the associated thread function.
     */
    void Start(void *data);

    /**
     * @brief Stops the thread, making sure it exits cleanly.
     */
    void Stop();

    /**
     * @brief Pauses the thread. Implementation depends on how pause functionality is handled.
     */
    void Pause();
};

#endif // DEFUNBOBENGINE_THREAD_HPP
