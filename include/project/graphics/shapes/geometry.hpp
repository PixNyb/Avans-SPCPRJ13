/**
 * @file geometry.hpp
 * @author Robin Pijnappels
 * @brief This file contains the Geometry class definition.
 * @version 0.1
 * @date 2023-11-08
 *
 * The Geometry class serves as an abstract base class for all geometric shapes within the
 * game engine. It holds a position vector and defines a common interface for drawing shapes.
 * Specific shapes should inherit from this class and implement their drawing logic.
 *
 * @see Vector2D
 */

#ifndef DEFUNBOBENGINE_GEOMETRY_HPP
#define DEFUNBOBENGINE_GEOMETRY_HPP

#include "vector2d.hpp"

/**
 * @class Geometry
 * @brief Abstract base class for geometric shapes.
 *
 * Geometry defines a common interface for all geometric shapes. Each shape will have a
 * position defined by a Vector2D object and must implement its own drawing functionality.
 */
class Geometry
{
  protected:
    Vector2D position; ///< Position of the geometric shape in 2D space.

  public:
    /**
     * @brief Constructs a Geometry object with a specified position.
     * @param pos The position of the geometric shape.
     */
    Geometry(const Vector2D &pos) : position(pos) {}

    /**
     * @brief Virtual destructor for Geometry.
     */
    virtual ~Geometry() {}

    /**
     * @brief Pure virtual function for drawing the geometric shape.
     *
     * Implementations of this function should contain the rendering logic specific to the shape.
     */
    virtual void draw() const = 0;
};

#endif // DEFUNBOBENGINE_GEOMETRY_HPP
