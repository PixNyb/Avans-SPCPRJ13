/**
 * @file sdl_surface.hpp
 * @author Robin Pijnappels (rm.pijnappels@student.avans.nl)
 * @brief This file contains the SDLSurface class definition.
 * @version 0.1
 * @date 2023-11-08
 *
 * The SDLSurface class is responsible for managing SDL_Surface resources,
 * providing an interface for loading and retrieving an SDL_Surface from a file path.
 * It ensures that the loaded surface is properly released when the object is destroyed.
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_SDL_SURFACE_HPP
#define DEFUNBOBENGINE_SDL_SURFACE_HPP

#include <SDL.h>

/**
 * @class SDLSurface
 * @brief Manages an SDL_Surface loaded from a file.
 *
 * SDLSurface encapsulates an SDL_Surface object, handling its creation from a file
 * and destruction. It provides a method to access the underlying SDL_Surface pointer
 * for use with SDL operations.
 */
class SDLSurface {
private:
    SDL_Surface* surface;

public:
    /**
     * @brief Constructs an SDLSurface by loading from the specified file path.
     * @param filePath The path to the image file to load as an SDL_Surface.
     */
    SDLSurface(const char* filePath);
    /**
    * @brief Destroys the SDLSurface, freeing the managed SDL_Surface resource.
    */
    ~SDLSurface();

    /**
    * @brief Retrieves the underlying SDL_Surface pointer.
    * @return SDL_Surface* A pointer to the managed SDL_Surface.
    */
    SDL_Surface* getSDLSurface() const;
};

#endif //DEFUNBOBENGINE_SDL_SURFACE_HPP
