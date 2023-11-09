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
class Rectangle : public Geometry {
private:
    float height; ///< The height of the rectangle.
    float width; ///< The width of the rectangle.

public:
    /**
     * @brief Constructs a new Rectangle object.
     *
     * @param pos The position of the rectangle's reference point (typically the top left corner).
     * @param h The height of the rectangle.
     * @param w The width of the rectangle.
     */
    Rectangle(const Vector2D& pos, float h, float w)
            : Geometry(pos), height(h), width(w) {}

    /**
     * @brief Draws the rectangle using the rendering system.
     *
     * Implementations should use the position, width, and height to draw the rectangle
     * to the screen. The actual rendering implementation would depend on the
     * graphics library being used.
     */
    void draw() const override {
        // Rendering logic goes here
    }
};

#endif //DEFUNBOBENGINE_RECTANGLE_HPP
