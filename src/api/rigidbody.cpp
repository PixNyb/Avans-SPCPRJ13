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

