/**
 * @file ui_object.cpp
 * @author Robin Pijnappels
 * @brief This file contains the UIObject class implementation.
 * @version 0.1
 * @date 2023-11-08
 *
 * Copyright Copyright (c) 2023
 *
 */

#include "ui_object.hpp"

UIObject::UIObject() : width(0), height(0), useRelativePosition(false)
{
    // Default constructor initialization
}

// TODO: Implement game object props
UIObject::UIObject(const std::string &name, const std::string &tag, int layer, float width,
                   float height)
    : GameObject(name), width(width), height(height), useRelativePosition(false)
{
    this->tag = tag;
    this->layer = layer;
}

void UIObject::SetWidth(float w) { width = w; }

float UIObject::GetWidth() const { return width; }

void UIObject::SetHeight(float h) { height = h; }

float UIObject::GetHeight() const { return height; }

void UIObject::SetUseRelativePosition(bool status) { useRelativePosition = status; }

bool UIObject::GetUseRelativePosition() const { return useRelativePosition; }
