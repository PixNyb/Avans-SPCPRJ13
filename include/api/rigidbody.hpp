/// @file

#ifndef AVANS_SPCPRJ13_RIGIDBODY_H
#define AVANS_SPCPRJ13_RIGIDBODY_H

#include "component.hpp"
#include <string>
#include "point.hpp"

/**
 * @brief Enumeration for different rigid body types
 */
enum class BodyType {
    staticBody,
    kinematicBody,
    dynamicBody
};

/**
 * @brief A component representing a rigid body.
 */
class RigidBody : public Component {
public:
    /**
     * @brief Apply force to this rigid body.
     * @param forceDirection A point, used as a vector to indicate direction
     *        and magnitude of the force to be applied.
     */
    void AddForce(const Point& forceDirection);

    RigidBody(double mass, double gravityScale, BodyType bodyType);

    double GetMass();

    double GetGravityScale();

    BodyType GetBodyType();

private:
    double mass;
    double gravityScale;
    BodyType bodyType;
};

#endif // AVANS_SPCPRJ13_RIGIDBODY_H
