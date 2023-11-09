/// @file

#include "button.hpp"
#include "color.hpp"

Button::Button() : interactable(true), onClick(nullptr) {
  // Default constructor initialization
}
void Button::Click() {}

Button::Button(const std::string& name, const std::string& tag, int layer, float width, float height) : UIObject(name, tag, layer, width, height), interactable(true), onClick(nullptr) {
  // Default constructor initialization
}