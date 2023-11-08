//
// Created by Robin Pijnappels on 08/11/2023.
//

#ifndef DEFUNBOBENGINE_RENDER_HPP
#define DEFUNBOBENGINE_RENDER_HPP

#include <SDL.h>

class Render {
    SDL_Renderer* renderer;

public:
    Render(SDL_Renderer* renderer);
    void clear();
    void present();
};

#endif //DEFUNBOBENGINE_RENDER_HPP
