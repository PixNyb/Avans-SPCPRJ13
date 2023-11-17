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

#include "shape_color.hpp"
#include "vector2d.hpp"

/**
 * @class Geometry
 * @brief Abstract base class for geometric shapes.
 *
 * Geometry defines a common interface for all geometric shapes. Each shape will have a
 * position defined by a Vector2D object and must implement its own drawing functionality.
 */
class Geometry {
protected:
    ShapeColor fillColor; ///< Color of the geometric shape.
    double rotation = 0; ///< Rotation of the geometric shape.

public:
    Geometry() : fillColor(Color::black()) {}
    /**
     * @brief Virtual destructor for Geometry.
     */
    virtual ~Geometry() {}

    void SetFillColor(const Color& c) { fillColor.SetColor(c); }
    [[nodiscard]] Color SetFillColor() const { return fillColor.GetColor(); }

    void SetRotation(int r) { rotation = r; }
    [[nodiscard]] double GetRotation() const { return rotation; }

    // Get area
    /**
     * @brief Pure virtual method to get the area of a geometric shape.
     *
     * @return The area of the geometric shape.
     */
    virtual int GetArea() = 0;

    /**
     * @brief Pure virtual method to check if a geometric shape is within a given area.
     *
     * @param start The start of the area to check.
     * @param end The end of the area to check.
     * @return True if the shape is within the area, false otherwise.
     */
    virtual bool IsWithinArea(const Vector2D& start, const Vector2D& end) = 0;
};

#endif //DEFUNBOBENGINE_GEOMETRY_HPP
