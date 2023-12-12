/**
 * @file circle_collider.cpp
 * @author Robin Pijnappels
 * @brief This file contains the CircleCollider class implementation.
 * @version 0.1
 * @date 2023-11-08
 *
 * Copyright Copyright (c) 2023
 *
 */
#include "circle_collider.hpp"

CircleCollider::CircleCollider(std::weak_ptr<GameObject> parent) : radius(0.0)
{
    this->parent = parent;
}

CircleCollider::CircleCollider(const CircleCollider &other) : Collider(other)
{
    radius = other.radius;
}

std::shared_ptr<Component> CircleCollider::Clone(std::weak_ptr<GameObject> parent)
{
    return std::make_shared<CircleCollider>(*this);
}
