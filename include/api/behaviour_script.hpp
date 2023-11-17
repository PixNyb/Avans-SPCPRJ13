/**
 * @file behaviour_script.hpp
 * @author Robin Pijnappels
 * @version 0.1
 * @date 2023-11-12
 *
 * @brief Defines the BehaviourScript class as part of a game engine framework.
 * BehaviourScript is a base class for scripting custom behaviors in game objects,
 * providing a structure for event-driven programming in a gaming context.
 * It offers a range of virtual methods for responding to common game events,
 * such as start, update, and physics-triggered interactions.
 *
 * @copyright Copyright (c) 2023
 */

#ifndef AVANS_SPCPRJ13_BEHAVIOURSCRIPT_H
#define AVANS_SPCPRJ13_BEHAVIOURSCRIPT_H

#include "component.hpp"
#include "collider.hpp"

/**
 * @class BehaviourScript
 * @brief Base class for scriptable behavior in game objects.
 *
 * BehaviourScript serves as a base class for defining custom behaviors that can be
 * attached to game objects. It provides a framework for scripting events such as
 * start, update, and collision triggers.
 */
class BehaviourScript : public Component {
public:
    /**
     * @brief TODO
     */
    virtual void OnStart();

    /**
     * @brief TODO
     */
    virtual void OnUpdate();

    /**
     * @brief Sent when another object enters a trigger collider
     *        attached to this object (2D physics only).
     */
    virtual void OnTriggerEnter2D(const Collider& collider);

    /**
     * @brief Sent when another object leaves a trigger collider
     *        attached to this object (2D physics only).
     */
    virtual void OnTriggerExit2D(const Collider& collider);

    /**
     * @brief Sent each frame where another object is within a trigger
     *        collider attached to this object (2D physics only).
     */
    virtual void OnTriggerStay2D(const Collider& collider);
};

#endif // AVANS_SPCPRJ13_BEHAVIOURSCRIPT_H
