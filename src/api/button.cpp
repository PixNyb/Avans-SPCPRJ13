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
#include "button_click_listener.hpp"

Button::Button()
    : interactable(true), onClick(nullptr),
      buttonClickListener(std::make_shared<ButtonClickListener>(*this))
{
    buttonClickListener->Attach();
}

void Button::Click() {}

Button::Button(const std::string &name, const std::string &tag, int layer, float width,
               float height)
    : UIObject(name, tag, layer, width, height), interactable(true), onClick(nullptr),
      buttonClickListener(std::make_shared<ButtonClickListener>(*this))
{
    buttonClickListener->Attach();
}

Button::~Button() { buttonClickListener->Detach(); }
