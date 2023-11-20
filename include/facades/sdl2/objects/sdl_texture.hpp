/**
 * @file sdl_texture.hpp
 * @author Robin Pijnappels (rm.pijnappels@student.avans.nl)
 * @brief This file contains the SDLTexture class definition.
 * @version 0.1
 * @date 2023-11-08
 *
 * The SDLTexture class is responsible for managing an SDL_Texture resource,
 * providing an interface for creating and retrieving an SDL_Texture from a file path.
 * It ensures that the texture is properly released when the object is destroyed.
 * This class is typically used to handle the texture's lifecycle and to facilitate
 * rendering with SDL2.
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_SDL_TEXTURE_HPP
#define DEFUNBOBENGINE_SDL_TEXTURE_HPP

#include <SDL.h>
#include <string>

/**
 * @class SDLTexture
 * @brief Manages an SDL_Texture loaded from a file.
 *
 * SDLTexture encapsulates an SDL_Texture object, handling its creation from a file
 * and destruction. It provides a method to access the underlying SDL_Texture pointer
 * for use with SDL rendering operations. The texture is created given a renderer
 * and a file path to an image resource.
 */
class SDLTexture
{
  private:
    SDL_Texture *texture;

  public:
    /**
     * @brief Constructs an SDLTexture by loading from the specified file path.
     * @param renderer The SDL_Renderer that will be used to create the texture.
     * @param filePath The path to the image file to load as an SDL_Texture.
     */
    SDLTexture(SDL_Renderer *renderer, const std::string &filePath);

    /**
     * @brief Destroys the SDLTexture, freeing the managed SDL_Texture resource.
     */
    ~SDLTexture() { SDL_DestroyTexture(texture); };

    /**
     * @brief Retrieves the underlying SDL_Texture pointer.
     * @return SDL_Texture* A pointer to the managed SDL_Texture.
     */
    SDL_Texture *GetSDLTexture() const;
};

#endif // DEFUNBOBENGINE_SDL_TEXTURE_HPP
