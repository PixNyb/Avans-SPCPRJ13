/**
 * @file text.cpp
 * @author Robin Pijnappels
 * @brief This file contains the Text class implementation.
 * @version 0.1
 * @date 2023-11-08
 *
 * Copyright Copyright (c) 2023
 *
 */


#include "text.hpp"
#include "core_constants.hpp"

Text::Text()
    : UIObject(), fontSize(CoreConstants::Text::DEFAULT_SIZE),
      alignment(CoreConstants::Text::DEFAULT_ALIGNMENT),
      textColor(CoreConstants::Text::DEFAULT_COLOR)
{
}

Text::Text(const std::string &name, const std::string &tag, int layer, float width, float height)
    : UIObject(name, tag, layer, width, height), fontSize(CoreConstants::Text::DEFAULT_SIZE),
      alignment(CoreConstants::Text::DEFAULT_ALIGNMENT),
      textColor(CoreConstants::Text::DEFAULT_COLOR)
{
}

void Text::SetText(const std::string &str) { text = str; }

std::string Text::GetText() const { return text; }

void Text::SetFontSize(int size) { fontSize = size; }

int Text::GetFontSize() const { return fontSize; }

void Text::SetAlignment(const Alignment &align) { alignment = align; }

Alignment Text::GetAlignment() const { return alignment; }

void Text::SetTextColor(const Color &color) { textColor = color; }

Color Text::GetTextColor() const { return textColor; }
