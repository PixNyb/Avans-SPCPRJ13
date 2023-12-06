/**
 * @file button.cpp
 * @author Robin Pijnappels
 * @brief This file contains the Button class implementation.
 * @version 0.1
 * @date 2023-11-08
 *
 * Copyright Copyright (c) 2023
 *
 */

#include "button.hpp"

Button::Button() : interactable(true), onClick(nullptr)
{
    // Default constructor initialization
}
void Button::Click() {}

Button::Button(const std::string &name, const std::string &tag, int layer, float width,
               float height)
    : UIObject(name, tag, layer, width, height), interactable(true), onClick(nullptr)
{
    // Default constructor initialization
}