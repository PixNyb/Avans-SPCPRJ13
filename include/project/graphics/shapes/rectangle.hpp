/**
 * @file rectangle.hpp
 * @author Robin Pijnappels
 * @brief This file contains the Rectangle class definition.
 * @version 0.1
 * @date 2023-11-08
 *
 * Rectangle is a concrete implementation of the Geometry class that represents a
 * rectangle in 2D space. It extends the Geometry class by adding width and height
 * properties and implementing the draw method to render a rectangle on the screen.
 *
 * @see Geometry
 */

#ifndef DEFUNBOBENGINE_RECTANGLE_HPP
#define DEFUNBOBENGINE_RECTANGLE_HPP

#include "geometry.hpp"

/**
 * @class Rectangle
 * @brief Represents a rectangle and extends the Geometry class.
 *
 * This class is used to represent a rectangle with a given width and height.
 * The rectangle's position is defined by the position property from the Geometry class.
 * The draw method is used to render the rectangle to the screen using the rendering logic
 * specific to the graphics library being used.
 */
class Rectangle : public Geometry
{
  private:
    int height;        ///< The height of the rectangle.
    int width;         ///< The width of the rectangle.
    Vector2D position; ///< The position of the rectangle's reference point (typically the top left
                       ///< corner).

  public:
    /**
     * @brief Constructs a new Rectangle object.
     *
     * @param pos The position of the rectangle's reference point (typically the top left corner).
     * @param h The height of the rectangle.
     * @param w The width of the rectangle.
     */
    Rectangle(const Vector2D &pos, int h, int w) : position(pos), height(h), width(w) {}

    [[nodiscard]] Vector2D GetPosition() const { return position; }

    int GetHeight() const { return height; }

    int GetWidth() const { return width; }

    int GetArea() override { return height * width; }

    bool IsWithinArea(const Vector2D &start, const Vector2D &end) override
    {
        return (position.x >= start.x && position.y >= start.y) &&
               (position.x + width <= end.x && position.y + height <= end.y);
    }
};

#endif // DEFUNBOBENGINE_RECTANGLE_HPP
