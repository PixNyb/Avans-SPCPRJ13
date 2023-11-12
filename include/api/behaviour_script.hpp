/// @file

#ifndef AVANS_SPCPRJ13_BEHAVIOURSCRIPT_H
#define AVANS_SPCPRJ13_BEHAVIOURSCRIPT_H

#include "collider.hpp"
#include "component.hpp"

class BehaviourScript : public Component
{
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
    virtual void OnTriggerEnter2D(const Collider &collider);

    /**
     * @brief Sent when another object leaves a trigger collider
     *        attached to this object (2D physics only).
     */
    virtual void OnTriggerExit2D(const Collider &collider);

    /**
     * @brief Sent each frame where another object is within a trigger
     *        collider attached to this object (2D physics only).
     */
    virtual void OnTriggerStay2D(const Collider &collider);
};

#endif // AVANS_SPCPRJ13_BEHAVIOURSCRIPT_H
