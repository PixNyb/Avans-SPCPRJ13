//
// Created by Robin Pijnappels on 08/11/2023.
//

#ifndef DEFUNBOBENGINE_SDL_TEXTURE_HPP
#define DEFUNBOBENGINE_SDL_TEXTURE_HPP

#include <SDL.h>

class SDLTexture {
private:
    SDL_Texture* texture;

public:
    SDLTexture(SDL_Renderer* renderer, const char* filePath);
    ~SDLTexture();

    SDL_Texture* getSDLTexture() const;
};

#endif //DEFUNBOBENGINE_SDL_TEXTURE_HPP
