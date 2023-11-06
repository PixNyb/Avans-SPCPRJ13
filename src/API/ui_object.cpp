/// @file

#include "ui_object.hpp"

UIObject::UIObject() : width(0), height(0) {
  // Default constructor initialization
}

void UIObject::SetWidth(int w) { width = w; }

int UIObject::GetWidth() const { return width; }

void UIObject::SetHeight(int h) { height = h; }

int UIObject::GetHeight() const { return height; }
