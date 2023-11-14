/**
 * @file sdl_triangle.hpp
 * @author Robin Pijnappels (rm.pijnappels@student.avans.nl)
 * @brief This file contains the SDLTriangle class definition.
 * @version 0.1
 * @date 2023-11-08
 *
 * The SDLTriangle class provides functionality to represent a triangle shape and
 * render it using the SDL2_gfx library. It holds the vertices of the triangle
 * and a method to draw it on an SDL_Renderer.
 *
 * @note The current implementation assumes a white fill color for the triangle.
 * Future versions may allow custom colors.
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_SDL_TRIANGLE_HPP
#define DEFUNBOBENGINE_SDL_TRIANGLE_HPP

#include <SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

/**
 * @class SDLTriangle
 * @brief Encapsulates the properties of a triangle and provides a drawing method.
 *
 * SDLTriangle represents a simple geometric triangle defined by three vertices.
 * It provides a method to render the triangle onto an SDL_Renderer, using the filledPolygonRGBA
 * function from the SDL2_gfx library to draw a filled triangle.
 */
class SDLTriangle {
public:
    Sint16 vx[3];
    Sint16 vy[3];

    /**
     * @brief Constructs a triangle defined by three points.
     * @param x1 The x-coordinate of the first vertex.
     * @param y1 The y-coordinate of the first vertex.
     * @param x2 The x-coordinate of the second vertex.
     * @param y2 The y-coordinate of the second vertex.
     * @param x3 The x-coordinate of the third vertex.
     * @param y3 The y-coordinate of the third vertex.
     */
    SDLTriangle(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Sint16 x3, Sint16 y3) {
        vx[0] = x1; vy[0] = y1;
        vx[1] = x2; vy[1] = y2;
        vx[2] = x3; vy[2] = y3;
    }

    /**
     * @brief Renders the triangle on the provided SDL_Renderer.
     * @param renderer The SDL_Renderer to draw the triangle on.
     */
    void Draw(SDL_Renderer* renderer) const;

};

#endif //DEFUNBOBENGINE_SDL_TRIANGLE_HPP
