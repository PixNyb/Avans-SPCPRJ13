/**
 * @file sdl_thread.cpp
 * @author Robin Pijnappels
 * @brief This file contains the SDLThread class implementation.
 * @version 0.1
 * @date 2023-11-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "sdl_thread.hpp"

// This function will run on the thread
int Thread::threadFunction(void* data) {
    // thread code here
    return 0;
}

Thread::~Thread() {
    if (thread != nullptr) {
        SDL_WaitThread(thread, nullptr);
    }
}

void Thread::Start(void* data) {
    thread = SDL_CreateThread(threadFunction, threadName.c_str(), data);
    if (thread == nullptr) {
        std::cerr << "SDL_CreateThread failed: " << SDL_GetError() << std::endl;
    }
}

void Thread::Stop() {
    if (thread != nullptr) {
        SDL_DetachThread(thread);
        thread = nullptr;
    }
}

void Thread::Pause() {
    // Implement pause functionality
    // SDL doesn't have a built-in pause for threads
}
