/**
 * @file transform.hpp
 * @author Roël Couwenberg (contact@roelc.me)
 * @brief This file contains the Transform struct definition.
 * @version 0.1
 * @date 2023-11-08
 *
 * @brief Defines the Transform struct for representing 2D transformations in the game engine.
 * Transform is a fundamental structure that encapsulates translation, rotation, and scaling in 2D
 * space. It is widely used for positioning, rotating, and scaling game objects within the game
 * world.
 *
 * @copyright Copyright (c) 2023
 */

#ifndef AVANS_SPCPRJ13_TRANSFORM_H
#define AVANS_SPCPRJ13_TRANSFORM_H

#include "point.hpp"

/**
 * @brief Represents a 2D transformation including position, rotation, and scale.
 *
 * Instances of this struct are used to define the transformation properties of game objects,
 * including their position in the game world, rotation angle, and scaling factor.
 */
struct Transform
{
    /**
     * @brief Construct a new Transform object
     *
     */
    Transform();

    /**
     * @brief Construct a new Transform object with specified position, rotation, and scale.
     *
     * @param position The position component of the transform, represented as a Point.
     * @param rotation The rotation component of the transform, in radians.
     * @param scale The scale component of the transform, as a multiplication factor.
     */
    Transform(const Point &position, double rotation, double scale);

    Point position;  ///< Translation (shift)
    double rotation; ///< Rotation, in radians
    double scale;    ///< Multiplication factor

    /**
     * @brief Adds two transforms together.
     * @param other The other transform to add to this one.
     * @return Transform The sum of the two transforms.
     */
    Transform operator+(const Transform &other) const;

    /**
     * @brief Subtracts two transforms from each other.
     * @param other The other transform to subtract from this one.
     * @return Transform The difference of the two transforms.
     */
    Transform operator-(const Transform &other) const;

    /**
     * @brief Compares two transforms to see if they are identical.
     * @param other The transform which it is to be compared to.
     * @return Whether the two transforms are identical.
     */
    bool operator==(const Transform &other) const;
};

#endif // AVANS_SPCPRJ13_TRANSFORM_H
