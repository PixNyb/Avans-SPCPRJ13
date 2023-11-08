/// @file

#include "ui_object.hpp"

UIObject::UIObject() : width(0), height(0) {
  // Default constructor initialization
}

// TODO: Implement game object props
UIObject::UIObject(const std::string &name, const std::string &tag, const std::string &layer, float width, float height) : GameObject(name), width(width), height(height) {

}

void UIObject::SetWidth(int w) { width = w; }

int UIObject::GetWidth() const { return width; }

void UIObject::SetHeight(int h) { height = h; }

int UIObject::GetHeight() const { return height; }
