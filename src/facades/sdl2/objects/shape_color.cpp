/**
 * @file shape_color.cpp
 * @author "Melvin van Bree"
 * @brief TODO
 * @version 0.1
 * @date 17/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "shape_color.hpp"

ShapeColor::ShapeColor(Color color) : color(color) {}
Color ShapeColor::GetColor() const { return color; }
void ShapeColor::SetColor(const Color &c) { color = c; }
