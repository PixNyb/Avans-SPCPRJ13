/**
 * @file triangle.hpp
 * @author Robin Pijnappels
 * @brief Defines the Triangle class for geometric calculations.
 * @version 0.1
 * @date 14/11/2023
 *
 * The Triangle class extends the Geometry class and is used to represent
 * the geometric shape of a triangle. It stores the coordinates of the triangle's
 * three vertices and provides functionality for basic geometric operations.
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_TRIANGLE_HPP
#define DEFUNBOBENGINE_TRIANGLE_HPP

#include "geometry.hpp"
#include "vector2d.hpp"

class Triangle {
private:
    Vector2D vertex1, vertex2, vertex3;

public:
    /**
     * @brief Constructs a new Triangle object.
     *
     * @param v1 The first vertex of the triangle.
     * @param v2 The second vertex of the triangle.
     * @param v3 The third vertex of the triangle.
     */
    Triangle(const Vector2D& v1, const Vector2D& v2, const Vector2D& v3)
            : vertex1(v1), vertex2(v2), vertex3(v3) {}

    // Accessor methods for the vertices
    Vector2D GetVertex1() const { return vertex1; }
    Vector2D GetVertex2() const { return vertex2; }
    Vector2D GetVertex3() const { return vertex3; }

};

#endif //DEFUNBOBENGINE_TRIANGLE_HPP
