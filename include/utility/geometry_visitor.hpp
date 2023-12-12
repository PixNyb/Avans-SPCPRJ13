/**
 * @file geometry_visitor.hpp
 * @author "Melvin van Bree"
 * @brief A file containing the GeometryVisitor class.
 * @version 0.1
 * @date 12/12/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_SRC_UTILITY_GEOMETRY_VISITOR_HPP
#define DEFUNBOBENGINE_SRC_UTILITY_GEOMETRY_VISITOR_HPP

#include "point.hpp"

class Circle;
class Line;
class Rectangle;
class Polygon;
class Triangle;

class GeometryVisitor
{
  public:
    virtual ~GeometryVisitor() = default;
    virtual void Visit(Circle &circle) = 0;
    virtual void Visit(Line &line) = 0;
    virtual void Visit(Rectangle &rectangle) = 0;
    virtual void Visit(Polygon &polygon) = 0;
    virtual void Visit(Triangle &polygon) = 0;
};

#endif // DEFUNBOBENGINE_SRC_UTILITY_GEOMETRY_VISITOR_HPP
