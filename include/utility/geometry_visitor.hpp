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

// Forward declaration of classes
class Circle;
class Line;
class Rectangle;
class Polygon;
class Triangle;

/**
 * @brief Interface for a Geometry Visitor
 *
 * GeometryVisitor is an interface for a class that "visits" different types of geometry.
 */
class GeometryVisitor
{
  public:
    /**
     * @brief Default Virtual Destructor
     *
     */
    virtual ~GeometryVisitor() = default;

    /**
     * @brief Visit circle geometry
     * @param circle: Reference to the Circle object being visited.
     */
    virtual void Visit(Circle &circle) = 0;

    /**
     * @brief Visit line geometry
     * @param line: Reference to the Line object being visited.
     */
    virtual void Visit(Line &line) = 0;

    /**
     * @brief Visit rectangle geometry
     * @param rectangle: Reference to the Rectangle object being visited.
     */
    virtual void Visit(Rectangle &rectangle) = 0;

    /**
     * @brief Visit polygon geometry
     * @param polygon: Reference to the Polygon object being visited.
     */
    virtual void Visit(Polygon &polygon) = 0;
    
    /**
     * @brief Visit triangle geometry
     * @param triangle: Reference to the Triangle object being visited.
     */
    virtual void Visit(Triangle &triangle) = 0;
};

#endif // DEFUNBOBENGINE_SRC_UTILITY_GEOMETRY_VISITOR_HPP