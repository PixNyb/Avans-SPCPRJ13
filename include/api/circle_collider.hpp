/**
 * @file circle_collider.hpp
 * @author Robin Pijnappels
 * @version 0.1
 * @date 2023-11-12
 *
 * @brief Defines the CircleCollider class for representing circular collision areas.
 * CircleCollider is a subclass of Collider, specialized for handling collisions in circular areas.
 * It provides functionalities to get and set the radius of the collider, crucial for circular collision detection.
 * This class is essential in physics simulations and collision detection in a game engine.
 *
 * @copyright Copyright (c) 2023
 */

#ifndef AVANS_SPCPRJ13_CIRCLECOLLIDER_H
#define AVANS_SPCPRJ13_CIRCLECOLLIDER_H

#include "collider.hpp"

/**
 * @class CircleCollider
 * @brief Represents a circular collision area.
 *
 * CircleCollider is a component used for collision detection and physics simulation.
 * It defines a circular area that can interact with other colliders in the game world.
 */
class CircleCollider : public Collider {
public:
    /**
     * @brief Get the collider's radius
     * @return The radius
     */
    double Radius() const { return radius; }

    /**
     * @brief Set the collider's radius
     * @param newRadius The desired radius
     */
    void Radius(double newRadius) { radius = newRadius; }

private:
    double radius;
};

#endif // AVANS_SPCPRJ13_CIRCLECOLLIDER_H
