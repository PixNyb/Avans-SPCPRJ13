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

GameObject::GameObject() : name(""), active(true), tag(""), layer(0), transform()
{
    // Constructor default initialization
}

GameObject::GameObject(const std::string &name)
    : name(name), active(true), tag(""), layer(0), transform()
{
    // Constructor with name initialization
}

GameObject::GameObject(const std::string &name, const Transform &transform)
    : name(name), transform(transform), active(true), tag(""), layer(0)
{
    // Constructor with name and transform initialization
}

GameObject::GameObject(const GameObject &other)
{
    name = other.name;

    // TODO: Update the clone functionality to make a deep copy.
    std::vector<std::shared_ptr<Component>> comps;
    for (const auto& comp : other.components)
        comps.push_back(std::make_shared<Component>(*comp));
    components = comps;

    transform = other.transform;
    active = other.active;
    tag = other.tag;
    layer = other.layer;
}

GameObject &GameObject::operator=(const GameObject &other)
{
    if (this == &other)
        return *this;

    components = std::vector<std::shared_ptr<Component>>();
    // The parent will remain undefined because it has to be redefined in the level format.
    parent = nullptr;

    name = other.name;

    // TODO: Add copy for components.
    components = other.components;

    transform = other.transform;
    active = other.active;
    tag = other.tag;
    layer = other.layer;

    return *this;
}

void GameObject::AddComponent(std::shared_ptr<Component> component)
{
    components.push_back(component);
}

void GameObject::SetName(const std::string &name) { this->name = name; }

std::string GameObject::GetName() const { return name; }

std::string GameObject::GetTag() const { return tag; }

void GameObject::SetTag(std::string tag) { this->tag = tag; }

int GameObject::GetLayer() const { return layer; }

void GameObject::SetLayer(int layer) { this->layer = layer; }

const Transform &GameObject::GetTransform() const { return transform; }

void GameObject::SetTransform(const Transform &transform) { this->transform = transform; }

bool GameObject::IsActive() const { return active; }

void GameObject::SetActive(bool active) { this->active = active; }

bool GameObject::IsActiveInWorld() const { return active; }

bool GameObject::IsActiveSelf() const { return active; }
