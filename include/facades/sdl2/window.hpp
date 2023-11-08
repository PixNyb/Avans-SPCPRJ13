//
// Created by Robin Pijnappels on 08/11/2023.
//

#ifndef DEFUNBOBENGINE_WINDOW_HPP
#define DEFUNBOBENGINE_WINDOW_HPP

#include <SDL.h>

class Window {
    SDL_Window* window;

public:
    Window(const char* title, int width, int height);
    ~Window();
    SDL_Window* getSDLWindow() const;
};

#endif //DEFUNBOBENGINE_WINDOW_HPP
