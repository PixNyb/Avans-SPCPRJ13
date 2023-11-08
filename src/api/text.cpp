/// @file

#include "text.hpp"

Text::Text()
        : text(""), fontSize(12), alignment("left"), textColor(255, 255, 255, 1) {
    // Default constructor initialization
}

void Text::SetText(const std::string &str) { text = str; }

std::string Text::GetText() const { return text; }

void Text::SetFontSize(int size) { fontSize = size; }

int Text::GetFontSize() const { return fontSize; }

void Text::SetAlignment(const std::string &align) { alignment = align; }

std::string Text::GetAlignment() const { return alignment; }

void Text::SetTextColor(const Color &color) { textColor = color; }

Color Text::GetTextColor() const { return textColor; }