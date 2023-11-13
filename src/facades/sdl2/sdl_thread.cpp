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
