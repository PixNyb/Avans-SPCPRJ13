/**
 * @file physics_facade.hpp
 * @author Daan Groot (d.groot3@student.avans.nl)
 * @brief This file contains the PhysicsFacade class definition.
 * @version 0.1
 * @date 2023-11-08
 * @copyright Copyright (c) 2023
 *
 */

#ifndef AVANS_SPCPRJ13_PHYSICS_FACADE_HPP
#define AVANS_SPCPRJ13_PHYSICS_FACADE_HPP

#include "collider.hpp"
#include "debug_renderer.hpp"
#include "game_object.hpp"
#include "rigidbody.hpp"
#include <box2d/box2d.h>
#include <map>
#include <memory>
#include <vector>

/**
 * @class PhysicsFacade
 * @brief The PhysicsFacade is responsible for all physics related logic. It gives the engine the
 * tools to simulate bodies in the game in a realistic manner.
 *
 * This class supports the following functionalities:
 *  Creating a physics world
 *  Simulating the created physics world
 *  Adding and removing bodies to and from the physics world
 *  Updating the various properties of bodies in the physics world
 */
class PhysicsFacade
{
  private:
    std::map<std::shared_ptr<GameObject>, b2Body *>
        bodies;                     ///< The map with bodies in the physicsfacade.
    std::unique_ptr<b2World> world; ////< The world in which the bodies can move.

    /**
     * @brief Creates a shape on a body through a fixture
     * @param body the body that the fixture is placed on
     * @param shape the shape you want to add to the body
     * @param rigidBody the rigidbody of the gameobject/body this fixture will belong to
     * @param area the area of the shape
     */
    void SetFixture(b2Body *body, b2Shape *shape, const std::shared_ptr<RigidBody> &rigidBody,
                    double area);

  public:
    /**
     * @brief Determines whether the debug mode should be active
     */
    bool DEBUG;

    /**
     * @brief Constructs a physicsfacade
     */
    PhysicsFacade();

    /**
     * @brief Destructs a physicsfacade
     */
    ~PhysicsFacade();

    /**
     * @brief Create a body from a gameobject
     */
    void MakeBody(std::shared_ptr<GameObject> gameObject);

    /**
     * @brief Destroy a body from a gameobject
     */
    void DestroyBody(const std::shared_ptr<GameObject> &gameObject);

    /**
     * @brief Populate the b2World through a list of gameobjects
     */
    void PopulateWorld(std::vector<std::shared_ptr<GameObject>> gameObjects);

    /**
     * @brief Add a force to an object
     * can be used for jumping or boosts in speed
     */
    void AddForce(const std::shared_ptr<GameObject> &gameObject, float vx, float vy);

    /**
     * @brief Add a linear impulse to an object
     * can be used for jumping or boosts in speed
     */
    void AddLinearImpulse(const std::shared_ptr<GameObject> &gameObject, float vx, float vy);

    /**
     * @brief Add a force to an object
     * can be used for jumping or boosts in speed
     */
    void AddRotation(const std::shared_ptr<GameObject> &gameObject, float amount);

    /**
     * @brief Execute the step function on the b2World
     */
    void Step();

    /**
     * @brief Sets the given gameobject to sleep
     * @param gameObject the gameobject that is set asleep
     */
    void Sleep(const std::shared_ptr<GameObject> &gameObject);

    /**
     * @brief Sets the given gameobject to wake up
     * @param gameObject the gameobject that is set awake
     */
    void Wake(const std::shared_ptr<GameObject> &gameObject);

    /**
     * @brief Simulate all bodies in the b2World in a window
     */
    void ShowDebug();

    /**
     * @brief Gets the body by the given GameObject
     */
    b2Body *GetBodyByObject(const std::shared_ptr<GameObject> &gameObject);

    /**
     * @brief Updates the position of a body inside the b2World. WARNING setting a body to a certain
     * position where other bodies are located behavior can be unexpected
     * @param gameObject the gameobject that changed its position
     * @param xPos x-axis position
     * @param yPos y-axis position
     */
    void UpdatePosition(const std::shared_ptr<GameObject> &gameObject, double xPos, double yPos);

    /**
     * @brief Sets the rotation of a body inside the b2World
     * @param gameObject the gameobject that changed its rotation
     * @param rotation the amount of rotation to be applied
     */
    void UpdateRotation(const std::shared_ptr<GameObject> &gameObject, double rotation);

    /**
     * Updates the velocity of the GameObject
     * @param gameObject the object
     * @param vX velocity on the x-axis
     * @param vY velocity on the y-axis
     */
    void UpdateVelocity(const std::shared_ptr<GameObject> &gameObject, double vX, double vY);
};

#endif // AVANS_SPCPRJ13_PHYSICS_FACADE_HPP
