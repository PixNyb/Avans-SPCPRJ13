/**
 * @file game_object.cpp
 * @author Roël Couwenberg (contact@roelc.me)
 * @author Daan Groot (d.groot3@student.avans.nl)
 * @brief This file contains the GameObject class implementation.
 * @version 0.1
 * @date 2023-11-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "game_object.hpp"
#include "component.hpp"
#include "physics_manager.hpp"
#include "transform.hpp"
#include <algorithm>
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

std::shared_ptr<GameObject> GameObject::Clone()
{
    auto ptr = std::make_shared<GameObject>();

    // The parent will remain undefined because it has to be redefined in the level format.
    ptr->parent = nullptr;
    ptr->name = name;

    for (const auto &comp : components)
        ptr->components.push_back(comp->Clone(ptr));

    ptr->transform = transform;
    ptr->active = active;
    ptr->tag = tag;
    ptr->layer = layer;

    return ptr;
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

void GameObject::SetTransform(const Transform &t) { this->transform = t; }

bool GameObject::IsActive() const { return active; }

void GameObject::SetActive(bool active) { this->active = active; }

bool GameObject::IsActiveInWorld() const { return active; }

bool GameObject::IsActiveSelf() const { return active; }

void GameObject::SetPhysicsManager(std::weak_ptr<PhysicsManager> physicsPointer)
{
    this->physicsManager = std::move(physicsPointer);
}

void GameObject::SetParent(std::shared_ptr<GameObject> newParent)
{
    if (newParent == nullptr)
    {
        parent = nullptr;
        return;
    }

    if (parent == newParent)
        return;

    // Remove from old parent
    if (parent != nullptr)
    {
        auto it = std::find(parent->children.begin(), parent->children.end(), shared_from_this());
        if (it != parent->children.end())
            parent->children.erase(it);
    }

    // Set new parent
    parent = std::move(newParent);

    // Add self to new parent
    if (parent != nullptr)
        parent->children.push_back(shared_from_this());
}

GameObject::~GameObject()
{
    for (auto &child : children)
        child->SetParent(nullptr);
}
