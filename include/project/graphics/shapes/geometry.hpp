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

#include "geometry_visitor.hpp"
#include "shape_color.hpp"
#include "vector2d.hpp"

class GeometryVisitor;

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
    Vector2D translation{0, 0}; ///< The translation of the geometric shape.
    ShapeColor fillColor;       ///< Color of the geometric shape.
    double rotation = 0;        ///< Rotation of the geometric shape.

  public:
    Geometry() : fillColor(Color::Black()) {}
    /**
     * @brief Virtual destructor for Geometry.
     */
    virtual ~Geometry() {}

    /**
     * Sets the color of the geometric shape.
     * @param c The color to set.
     */
    void SetFillColor(const Color &c) { fillColor.SetColor(c); }

    /**
     * Gets the color of the geometric shape.
     * @return The color of the geometric shape.
     */
    [[nodiscard]] Color GetFillColor() const { return fillColor.GetColor(); }

    /**
     * Set the rotation of the geometric shape.
     *
     * @param r The clockwise rotation of the geometric shape.
     */
    void SetRotation(int r) { rotation = r; }

    /**
     * Get the rotation of the geometric shape.
     *
     * @return The clockwise rotation of the geometric shape.
     */
    [[nodiscard]] double GetRotation() const { return rotation; }

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
    virtual bool IsWithinArea(const Vector2D &start, const Vector2D &end) = 0;

    /**
     * @brief Sets the translation of the geometric shape.
     * @param t The translation to set.
     */
    void SetTranslation(const Vector2D &t) { translation = t; }

    /**
     * @brief Gets the translation of the geometric shape.
     * @return The translation of the geometric shape.
     */
    [[nodiscard]] Vector2D GetTranslation() const { return translation; }

    /**
     * @brief Accepts a visitor.
     * @param visitor The visitor to accept.
     */
    virtual void Accept(GeometryVisitor &visitor) = 0;
};

#endif // DEFUNBOBENGINE_GEOMETRY_HPP
