//
// Created by Robin Pijnappels on 31/10/2023.
//

#include "rigidbody.hpp"

double RigidBody::GetMass() {
    return mass;
}

double RigidBody::GetGravityScale() {
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

