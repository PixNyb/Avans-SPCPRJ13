/// @file

#include "ui_object.hpp"

UIObject::UIObject() : width(0), height(0) {
  // Default constructor initialization
}

// TODO: Implement game object props
UIObject::UIObject(const std::string &name, const std::string &tag, int layer, float width, float height) : GameObject(name), width(width), height(height) {

}

void UIObject::SetWidth(float w) { width = w; }

float UIObject::GetWidth() const { return width; }

void UIObject::SetHeight(float h) { height = h; }

float UIObject::GetHeight() const { return height; }
