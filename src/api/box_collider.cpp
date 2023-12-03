/**
 * @file box_collider.cpp
 * @author Robin Pijnappels
 * @brief This file contains the BoxCollider class implementation.
 * @version 0.1
 * @date 2023-11-08
 *
 * Copyright Copyright (c) 2023
 *
 */
#include "box_collider.hpp"

BoxCollider::BoxCollider() : width(0.0), height(0.0)
{}

std::shared_ptr<Component> BoxCollider::Clone(std::weak_ptr<GameObject> parent)
{
    return std::make_shared<BoxCollider>(*this);
}

BoxCollider::BoxCollider(const BoxCollider &other) : Collider(other)
{
    width = other.width;
    height = other.height;
}
