/**
 * @file sdl_rect.hpp
 * @author Robin Pijnappels (rm.pijnappels@student.avans.nl)
 * @brief This file contains the SDLRect class definition.
 * @version 0.1
 * @date 2023-11-08
 *
 * The SDLRect class encapsulates a rectangle's properties and provides a method
 * to convert it into an SDL_Rect structure which can be used with SDL rendering functions.
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_SDL_RECT_HPP
#define DEFUNBOBENGINE_SDL_RECT_HPP

#include <SDL.h>

/**
 * @class SDLRect
 * @brief Encapsulates the properties of a rectangle.
 *
 * This class represents a rectangle with a position and size.
 * It provides a method to convert its properties into an SDL_Rect,
 * which is commonly used in SDL for rendering and other operations involving rectangular areas.
 */
class SDLRect {
public:
    int x, y, width, height;

    /**
     * @brief Constructs a new SDLRect with specified position and size.
     * @param x The x coordinate of the top-left corner of the rectangle.
     * @param y The y coordinate of the top-left corner of the rectangle.
     * @param width The width of the rectangle.
     * @param height The height of the rectangle.
     */
    SDLRect(int x, int y, int width, int height)
            : x(x), y(y), width(width), height(height) {}

    /**
    * @brief Converts this SDLRect to an SDL_Rect structure.
    * @return SDL_Rect An SDL_Rect structure with the same position and size as this SDLRect.
    */
    SDL_Rect toSDLRect() const {
        return {x, y, width, height};
    }

    /**
     * @brief Draws the rectangle using SDL rendering functions.
     *
     * This method renders the rectangle represented by this SDLRect object on the screen
     * using the provided SDL_Renderer. The method currently sets the drawing color to white,
     * but this can be adjusted for color customization.
     *
     * @param renderer A pointer to an SDL_Renderer to draw the rectangle.
     */
    void Draw(SDL_Renderer* renderer) const;
};

#endif //DEFUNBOBENGINE_SDL_RECT_HPP
