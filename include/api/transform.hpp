/**
 * @file transform.hpp
 * @author Roël Couwenberg (contact@roelc.me)
 * @brief This file contains the Transform struct definition.
 * @version 0.1
 * @date 2023-11-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef AVANS_SPCPRJ13_TRANSFORM_H
#define AVANS_SPCPRJ13_TRANSFORM_H

#include "point.hpp"

/**
 * @brief Instances of this class represent specific 2D transformations.
 */
struct Transform
{
    /**
     * @brief Construct a new Transform object
     *
     */
    Transform();

    /**
     * @brief Construct a new Transform object.
     *
     * @param position
     * @param rotation
     * @param scale
     */
    Transform(const Point &position, double rotation, double scale);

    Point position;  ///< Translation (shift)
    double rotation; ///< Rotation, in radians
    double scale;    ///< Multiplication factor

    Transform operator +(const Transform &other) const;
    Transform operator -(const Transform &other) const;
};

#endif // AVANS_SPCPRJ13_TRANSFORM_H
