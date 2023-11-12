/**
 * @file sdl_circle.hpp
 * @author Robin Pijnappels (rm.pijnappels@student.avans.nl)
 * @brief This file contains the SDLCircle class definition.
 * @version 0.1
 * @date 2023-11-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_SDL_CIRCLE_HPP
#define DEFUNBOBENGINE_SDL_CIRCLE_HPP

#include <SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

/**
 * @class SDLCircle
 * @brief Represents a circle that can be rendered using SDL2_gfx.
 *
 * The SDLCircle class encapsulates the properties of a circle, such as its
 * position and radius, and provides a method to draw it on an SDL_Renderer.
 */
class SDLCircle {
public:
    int x, y, radius;

    /**
     * @brief Constructs a circle with specified position and radius.
     * @param x The x coordinate of the circle's center.
     * @param y The y coordinate of the circle's center.
     * @param radius The radius of the circle.
     */
    SDLCircle(int x, int y, int radius)
            : x(x), y(y), radius(radius) {}

    /**
    * @brief Draws the circle on the given SDL_Renderer.
    * @param renderer The renderer on which to draw the circle.
    */
    void draw(SDL_Renderer* renderer) const {
        filledCircleRGBA(renderer, x, y, radius, 255, 255, 255, 255); // TODO: add color
    }
};
#endif //DEFUNBOBENGINE_SDL_CIRCLE_HPP
