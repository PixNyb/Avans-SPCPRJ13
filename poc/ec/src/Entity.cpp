#include "Entity.hpp"

void Entity::update(SDL_Event &event) {
  for (auto &component : components)
    component->update(event);
}

void Entity::addComponent(Component *component) {
  components.push_back(component);
}

void Entity::removeComponent(Component *component) {
  components.erase(std::remove(components.begin(), components.end(), component),
                   components.end());
}