/**
 * @file rigid_body.hpp
 * @author Robin Pijnappels
 * @version 0.1
 * @date 2023-11-12
 *
 * @brief Defines the RigidBody class for physics simulation in the game engine.
 * RigidBody is a component that represents a physics body with mass, gravity scale, and body type.
 * It can interact with forces and move according to physics simulations.
 * This class is crucial for creating dynamic and kinematic objects in a game world.
 *
 * @copyright Copyright (c) 2023
 */

#ifndef AVANS_SPCPRJ13_RIGIDBODY_H
#define AVANS_SPCPRJ13_RIGIDBODY_H

#include "component.hpp"
#include <string>
#include "point.hpp"

/**
 * @enum BodyType
 * @brief Enumeration for different types of rigid bodies.
 *
 * Defines the type of physics behavior a RigidBody will exhibit: static, kinematic, or dynamic.
 */
enum class BodyType {
    staticBody,    /**< A body that does not move under simulation. */
    kinematicBody, /**< A body that moves under simulation but is not affected by forces. */
    dynamicBody    /**< A fully simulated body affected by forces and collisions. */
};

/**
 * @class RigidBody
 * @brief Represents a physics body in the game engine.
 *
 * A component that adds physical properties to a game object, such as mass and the ability
 * to react to forces. It plays a key role in the game's physics system.
 */
class RigidBody : public Component {
public:
    /**
     * @brief Apply force to the rigid body.
     *
     * Adds a force to the rigid body, influencing its motion according to physics simulations.
     * @param forceDirection A Point representing the direction and magnitude of the force.
     */
    void AddForce(const Point& forceDirection);

    RigidBody(double mass, double gravityScale, BodyType bodyType);

    double GetMass();

    double GetGravityScale();

    BodyType GetBodyType();

private:
    double mass;        /**< The mass of the rigid body. */
    double gravityScale; /**< The scale at which gravity affects the rigid body. */
    BodyType bodyType;  /**< The type of the rigid body, determining its physics behavior. */
};

#endif // AVANS_SPCPRJ13_RIGIDBODY_H
