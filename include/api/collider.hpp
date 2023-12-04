/**
 * @file collider.hpp
 * @author Robin Pijnappels
 * @version 0.1
 * @date 2023-11-12
 *
 * @brief Defines the Collider class as a base for all collider components in a game engine.
 * Collider is an abstract class that serves as a base for specialized collider types like
 * BoxCollider and CircleCollider. It is a crucial part of the physics and collision detection
 * system within the game engine, providing a framework for handling collisions between game
 * objects.
 *
 * @copyright Copyright (c) 2023
 */

#ifndef COLLIDER2D_H_
#define COLLIDER2D_H_

#include "component.hpp"

/**
 * @class Collider
 * @brief Base class for collider components.
 *
 * The Collider class is an abstract base class for all collider components used in the game engine.
 * It provides a foundation for defining collision properties and behaviors for game objects.
 */
class Collider : public Component
{
  public:
    Collider();
    ~Collider() override = default;

    /**
     * @brief Make a clone of the component.
     * @param parent The parent GameObject.
     * @return The cloned component.
     */
    std::shared_ptr<Component> Clone(std::weak_ptr<GameObject> parent) override = 0;
};

#endif // COLLIDER2D_H_
