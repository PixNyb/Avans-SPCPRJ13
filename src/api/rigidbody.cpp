/**
 * @file rigidbody.cpp
 * @author Daan Groot (d.groot3@student.avans.nl)
 * @brief This file contains the RigidBody class implementation.
 * @version 0.1
 * @date 2023-11-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "rigidbody.hpp"

double RigidBody::GetMass() const {
    return mass;
}

double RigidBody::GetGravityScale() const {
    return gravityScale;
}

BodyType RigidBody::GetBodyType() {
    return bodyType;
}

RigidBody::RigidBody(double mass, double gravityScale, BodyType bodyType) {
    this->mass = mass;
    this->gravityScale = gravityScale;
    this->bodyType = bodyType;
}

RigidBody::RigidBody(const RigidBody &other) : Component(other) {
    mass = other.mass;
    gravityScale = other.gravityScale;
    bodyType = other.bodyType;
}

std::shared_ptr<Component> RigidBody::Clone(std::weak_ptr<GameObject> parent)
{
    return std::make_shared<RigidBody>(*this);
}

