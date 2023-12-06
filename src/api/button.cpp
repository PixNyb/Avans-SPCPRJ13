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
#include "color.hpp"
#include "iostream"

Button::Button() : interactable(true), onClick(nullptr)
{
    // Default constructor initialization
}
void Button::Click() {
    std::cout << "Reached button" << std::endl;
}

Button::Button(const std::string &name, const std::string &tag, int layer, float width,
               float height)
    : UIObject(name, tag, layer, width, height), interactable(true), onClick(nullptr)
{
    // Default constructor initialization
}