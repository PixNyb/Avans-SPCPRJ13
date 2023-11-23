/**
 * @file circle.hpp
 * @author Robin Pijnappels
 * @brief This file contains the Circle class definition.
 * @version 0.1
 * @date 2023-11-08
 *
 * Circle is a concrete implementation of the Geometry class. It represents a circle
 * in 2D space and extends the Geometry class by adding a radius and implementing
 * the draw method to render a circle to the screen.
 *
 * @see Geometry
 */

#ifndef DEFUNBOBENGINE_CIRCLE_HPP
#define DEFUNBOBENGINE_CIRCLE_HPP

#include "geometry.hpp"

/**
 * @class Circle
 * @brief Represents a circle and extends the Geometry class.
 *
 * This class is used to represent a circle. It holds the radius of the circle along
 * with its position in the form of a Vector2D inherited from the Geometry class. It
 * implements the draw method to provide the logic for rendering the circle.
 */
class Circle : public Geometry
{
  private:
    float radius;      ///< The radius of the circle.
    Vector2D position; ///< The position of the circle's center.

  public:
    /**
     * @brief Constructs a new Circle object.
     *
     * @param pos The position of the circle's center.
     * @param r The radius of the circle.
     */
    Circle(const Vector2D &pos, float r) : position(pos), radius(r) {}

    [[nodiscard]] Vector2D GetPosition() const { return position; }

    float GetRadius() const { return radius; }

    int GetArea() override { return 3.14 * radius * radius; }

    bool IsWithinArea(const Vector2D &start, const Vector2D &end) override
    {
        auto rad = GetRadius();

        if (start.x <= position.x + rad && start.y <= position.y + rad)
        {
            if (end.x >= position.x - rad && end.y >= position.y - rad)
            {
                return true;
            }
        }

        return false;
    }
};

#endif // DEFUNBOBENGINE_CIRCLE_HPP
