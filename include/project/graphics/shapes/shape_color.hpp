/**
 * @file shape_color.hpp
 * @author "Melvin van Bree"
 * @brief ShapeColor is a class that represents a color in the game engine.
 * @version 0.1
 * @date 17/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_INCLUDE_PROJECT_GRAPHICS_SHAPES_SHAPE_COLOR_HPP
#define DEFUNBOBENGINE_INCLUDE_PROJECT_GRAPHICS_SHAPES_SHAPE_COLOR_HPP

#include "color.hpp"

class ShapeColor
{
  private:
    Color color;
  public:
    explicit ShapeColor(Color color);
    void SetColor(const Color& c);
    [[nodiscard]] Color GetColor() const;
};

#endif // DEFUNBOBENGINE_INCLUDE_PROJECT_GRAPHICS_SHAPES_SHAPE_COLOR_HPP
