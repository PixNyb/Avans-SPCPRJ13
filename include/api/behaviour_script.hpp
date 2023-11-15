/// @file

#ifndef AVANS_SPCPRJ13_BEHAVIOURSCRIPT_H
#define AVANS_SPCPRJ13_BEHAVIOURSCRIPT_H

#include "component.hpp"
#include "collider.hpp"

class BehaviourScript : public Component {
protected:
    bool hasStarted = false;
public:
    /**
     * @brief Initializes everything required for the behaviour script.
     * @note This is required because not everything might be known while constructing a component
     * @warning DO set the hasStarted variable to true in this function or call the parent function
     */
    virtual void OnStart();

    /**
     * @brief Calls the update function of the behaviour script.
     * @note It only calls active behaviour scripts.
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

    /**
     * @brief Checks if the behaviour script has started.
     * @return True if the behaviour script has started, false otherwise.
     */
    bool HasStarted() const;
};

#endif // AVANS_SPCPRJ13_BEHAVIOURSCRIPT_H
