/**
 * @file game_object.cpp
 * @author Roël Couwenberg (contact@roelc.me)
 * @brief This file contains the GameObject class implementation.
 * @version 0.1
 * @date 2023-11-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "game_object.hpp"
#include "component.hpp"
#include <memory>

GameObject::GameObject() : name(""), active(true), tag(0), layer(0), transform()
{
    // Constructor default initialization
}

GameObject::GameObject(const std::string &name)
    : name(name), active(true), tag(0), layer(0), transform()
{
    // Constructor with name initialization
}

GameObject::GameObject(const std::string &name, const Transform &transform)
    : name(name), transform(transform), active(true), tag(0), layer(0)
{
    // Constructor with name and transform initialization
}

void GameObject::AddComponent(std::shared_ptr<Component> component)
{
    components.push_back(component);
}

bool GameObject::IsActive() const { return active; }

void GameObject::SetActive(bool active) { this->active = active; }

bool GameObject::IsActiveInWorld() const { return active; }

bool GameObject::IsActiveSelf() const { return active; }
