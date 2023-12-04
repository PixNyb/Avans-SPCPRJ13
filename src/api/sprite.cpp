/**
 * @file sprite.cpp
 * @author Robin Pijnappels
 * @brief This file contains the Sprite class implementation.
 * @version 0.1
 * @date 2023-11-08
 *
 * Copyright Copyright (c) 2023
 *
 */

#include "sprite.hpp"

Sprite::Sprite()
    : color(1.0, 1.0, 1.0, 1.0), // Initializing color to white (or any other default)
      flipX(false), flipY(false), sortingLayer(0), orderInLayer(0)
{
}

Sprite::Sprite(const Sprite &other)
    : BehaviourScript(other), sprite(other.sprite), color(other.color), flipX(other.flipX),
      flipY(other.flipY), sortingLayer(other.sortingLayer), orderInLayer(other.orderInLayer)
{
}

std::shared_ptr<Component> Sprite::Clone(std::weak_ptr<GameObject> parent)
{
    return std::make_shared<Sprite>(*this);
}
