/**
 * @file point.hpp
 * @author Robin Pijnappels
 * @version 0.1
 * @date 2023-11-12
 *
 * @brief Defines the Point struct for representing 2D points and vectors in the DefunBobEngine.
 * Point is a fundamental structure used throughout the engine to represent positions, directions,
 * and other two-dimensional vector-like data. It can be used in various contexts such as graphics,
 * physics, and user interface design.
 *
 * @copyright Copyright (c) 2023
 */

#ifndef DEFUNBOBENGINE_POINT_H
#define DEFUNBOBENGINE_POINT_H

/**
 * @struct Point
 * @brief Represents a 2D point or vector.
 *
 * This struct is used to represent both a point in 2D space and a 2D vector.
 * It includes two double members, x and y, to denote the coordinates or vector components.
 */
struct Point {
    double x; /**< The x-coordinate or x-component of the point/vector. */
    double y; /**< The y-coordinate or y-component of the point/vector. */

    /**
     * @brief Constructs a new Point with specified x and y values.
     *
     * @param x The x-coordinate or x-component of the point/vector.
     * @param y The y-coordinate or y-component of the point/vector.
     */
    Point(double x, double y) : x(x), y(y) {}
};

#endif // DEFUNBOBENGINE_POINT_H
