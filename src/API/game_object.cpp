/**
 * @file game_object.cpp
 * @brief GameObject class definition
 */

#include "game_object.hpp"
#include "component.hpp"

GameObject::GameObject() : name(""), active(true), tag(0), layer(0) {
  // Constructor default initialization
}

GameObject::GameObject(const std::string &name)
    : name(name), active(true), tag(0), layer(0) {
  // Constructor with name initialization
}

void GameObject::AddComponent(Component *component) {
  components.push_back(component);
}

bool GameObject::IsActive() const { return active; }

void GameObject::SetActive(bool active) { this->active = active; }

bool GameObject::IsActiveInWorld() const { return active; }

bool GameObject::IsActiveSelf() const { return active; }
