/**
 * @file Line.hpp
 * @author "Melvin van Bree"
 * @brief Line is a class that represents a line in the game engine.
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
#include "geometry.hpp"
#include "vector2d.hpp"

struct Line : public Geometry {
  public:
    Vector2D start;
    Vector2D end;

    int GetArea() override {
        return 0;
    }

    bool IsWithinArea(const Vector2D& s, const Vector2D& e) override {
        return (s.x > e.x && (start.x > s.x || end.x < e.x)) ||
            (s.x <= e.x && (start.x < s.x || end.x > e.x));
    }
};

#endif // DEFUNBOBENGINE_INCLUDE_PROJECT_GRAPHICS_SHAPES_LINE_HPP
