/**
 * @file sdl_color.hpp
 * @author "Melvin van Bree"
 * @brief A utility class for color related functions
 * @version 0.1
 * @date 17/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_PERFORMANCE_UTILITY_HPP
#define DEFUNBOBENGINE_PERFORMANCE_UTILITY_HPP

#include <SDL.h>
#include "color.hpp"

class SDLColorUtility {
  public:
    /**
     * @brief Converts a Color object to an SDL_Color object
     * @param color Color object to convert
     * @return SDL_Color SDL_Color object
     */
    static SDL_Color GetSDLColor(const Color &color) {
        return SDL_Color{static_cast<Uint8>(color.GetRed() * 255),
                         static_cast<Uint8>(color.GetGreen() * 255),
                         static_cast<Uint8>(color.GetBlue() * 255),
                         static_cast<Uint8>(color.GetAlpha() * 255)};
    }
};

#endif // DEFUNBOBENGINE_PERFORMANCE_UTILITY_HPP
