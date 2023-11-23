/**
 * @file sdl_init.hpp
 * @author Robin Pijnappels (rm.pijnappels@student.avans.nl)
 * @brief
 * @version 0.1
 * @date 2023-11-12
 *
 * ......
 *
 * @copyright Copyright (c) 2023
 */

#ifndef DEFUNBOBENGINE_SDL_INIT_HPP
#define DEFUNBOBENGINE_SDL_INIT_HPP

#include <SDL.h>
#include <iostream>

/**
 * @class SDLInit
 * @brief Class for initializing and cleaning up SDL.
 *
 * This class encapsulates the initialization and cleanup of SDL.
 * It initializes SDL in its constructor and handles cleanup in its destructor.
 * The copy constructor and assignment operator are deleted to prevent
 * copying of this singleton-like class.
 */
class SDLInit
{
  public:
    /**
     * @brief Constructs the SDLInit object and initializes SDL.
     *
     * The constructor attempts to initialize SDL. If initialization fails,
     * an error message is displayed to standard error output.
     */
    SDLInit();

    /**
     * @brief Destroys the SDLInit object and cleans up SDL.
     *
     * The destructor ensures that SDL is properly cleaned up when
     * the SDLInit object is destroyed.
     */
    ~SDLInit() { SDL_Quit(); }

    // Delete copy constructor and assignment operator to prevent copying
    SDLInit(const SDLInit &) = delete;
    SDLInit &operator=(const SDLInit &) = delete;
};

#endif // DEFUNBOBENGINE_SDL_INIT_HPP
