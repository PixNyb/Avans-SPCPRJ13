/**
 * @file component.cpp
 * @author Roël Couwenberg (contact@roelc.me)
 * @brief This file contains the Component class implementation.
 * @version 0.1
 * @date 2023-11-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "component.hpp"

Component::Component() : active(true) {}
Component::Component(const Component &other) : active(other.active) {}

bool Component::IsActive() const { return active; }
void Component::SetActive(bool active) { this->active = active; }
void Component::Update() {}
void Component::Condition() {}

std::shared_ptr<Component> Component::Clone(std::weak_ptr<GameObject> parent)
{
    return std::shared_ptr<Component>(this);
}
