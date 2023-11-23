#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Component.hpp"
#include <string>
#include <vector>

class Entity
{
  public:
    Entity() {}
    ~Entity() {}
    void update(SDL_Event &event);
    void addComponent(Component *component);
    void removeComponent(Component *component);
    template <typename T> T *getComponent() const
    {
        for (auto component : components)
        {
            T *t = dynamic_cast<T *>(component);
            if (t != nullptr)
            {
                return t;
            }
        }
        return nullptr;
    }

  private:
    std::string name;
    std::vector<Component *> components;
};

#endif