//
// Created by Robin Pijnappels on 08/11/2023.
//

#ifndef DEFUNBOBENGINE_THREAD_HPP
#define DEFUNBOBENGINE_THREAD_HPP

#include <SDL.h>

class Thread {
    SDL_Thread* thread;
    static int threadFunction(void* data);

public:
    Thread();
    ~Thread();
    void start();
    void stop();
    void pause();
};

#endif //DEFUNBOBENGINE_THREAD_HPP
