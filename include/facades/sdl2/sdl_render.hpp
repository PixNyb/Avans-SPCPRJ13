/**
 * @file sdl_render.hpp
 * @author Robin Pijnappels (rm.pijnappels@student.avans.nl)
 * @brief This file contains the Render class definition.
 * @version 0.1
 * @date 2023-11-08
 *
 * The Render class is a wrapper around SDL_Renderer, providing a simplified
 * interface for rendering operations such as clearing the screen and presenting
 * the rendered content.
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_RENDER_HPP
#define DEFUNBOBENGINE_RENDER_HPP

#include <SDL.h>

/**
 * @class Render
 * @brief Wrapper class for SDL_Renderer to provide rendering utilities.
 *
 * This class is designed to abstract the lower-level rendering details provided
 * by SDL_Renderer and to expose a simpler interface for clearing and presenting
 * operations. It is intended to be used as part of the rendering loop of a game engine.
 */
class Render {
    SDL_Renderer* renderer;

public:
    /**
    * @brief Constructs a Render object with the specified SDL_Renderer.
    * @param renderer A pointer to an SDL_Renderer responsible for rendering operations.
    */
    Render(SDL_Renderer* renderer);

    /**
     * @brief Clears the rendering target with the current drawing color.
     *
     * This function clears the entire rendering target, setting it to the color
     * previously set by SDL_SetRenderDrawColor.
     */
    void clear() {
        SDL_RenderClear(renderer);
    }

    /**
     * @brief Updates the screen with any rendering performed since the previous call.
     *
     * This function presents the current rendering, typically called after all rendering
     * operations have been completed for the current frame.
     */
    void present() {
        SDL_RenderPresent(renderer);
    }
};

#endif //DEFUNBOBENGINE_RENDER_HPP