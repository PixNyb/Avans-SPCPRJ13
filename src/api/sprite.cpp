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
        : color(1.0, 1.0, 1.0, 1.0),  // Initializing color to white (or any other default)
          flipX(false),
          flipY(false),
          sortingLayer(0),
          orderInLayer(0)
{

}
