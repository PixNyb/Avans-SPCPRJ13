/**
 * @file vector2d.hpp
 * @author Robin Pijnappels
 * @brief This file contains the Vector2D class definition.
 * @version 0.1
 * @date 2023-11-08
 *
 * Vector2D is a simple structure that represents a two-dimensional vector, commonly used for
 * position, direction, and velocity in a 2D space. It provides the basic components, x and y,
 * which can be used directly or through vector-related operations.
 *
 */

#ifndef DEFUNBOBENGINE_VECTOR2D_HPP
#define DEFUNBOBENGINE_VECTOR2D_HPP

/**
 * @class Vector2D
 * @brief Represents a two-dimensional vector.
 *
 * This class encapsulates a 2D vector with x and y components. It can be used
 * throughout the game engine wherever 2D coordinates or vectors are needed, such as
 * in position calculations, physics, and rendering.
 */
#include <cmath>
class Vector2D
{
  public:
    float x; ///< The x component of the vector.
    float y; ///< The y component of the vector.

    /**
     * @brief Constructs a new Vector2D with given x and y components.
     * @param x The x component of the vector.
     * @param y The y component of the vector.
     */
    Vector2D(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

    Vector2D operator+=(const Vector2D &rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    Vector2D operator-=(const Vector2D &rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }

    void Normalize()
    {
        float length = sqrt(x * x + y * y);
        x /= length;
        y /= length;
    }

    void Direction()
    {
        x = (x > 0) - (x < 0);
        y = (y > 0) - (y < 0);
    }
};

#endif // DEFUNBOBENGINE_VECTOR2D_HPP
