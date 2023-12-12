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

#include <utility>

BoxCollider::BoxCollider(std::weak_ptr<GameObject> parent) : width(0.0), height(0.0)
{
    this->parent = std::move(parent);
}

std::shared_ptr<Component> BoxCollider::Clone(std::weak_ptr<GameObject> parent)
{
    return std::make_shared<BoxCollider>(*this);
}

BoxCollider::BoxCollider(const BoxCollider &other) : Collider(other)
{
    width = other.width;
    height = other.height;
}
