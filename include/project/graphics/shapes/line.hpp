/**
 * @file Line.hpp
 * @author "Melvin van Bree"
 * @brief TODO
 * @version 0.1
 * @date 17/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_INCLUDE_PROJECT_GRAPHICS_SHAPES_LINE_HPP
#define DEFUNBOBENGINE_INCLUDE_PROJECT_GRAPHICS_SHAPES_LINE_HPP

#include "point.hpp"
#include "color.hpp"

struct Line : public Geometry {
  public:
    Vector2D start;
    Vector2D end;
};

#endif // DEFUNBOBENGINE_INCLUDE_PROJECT_GRAPHICS_SHAPES_LINE_HPP
