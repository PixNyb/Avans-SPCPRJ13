//
// Created by Eigenaar on 22-11-2023.
//

#ifndef DEFUNBOBENGINE_COLLIDER_BEHAVIOR_TEST_HPP
#define DEFUNBOBENGINE_COLLIDER_BEHAVIOR_TEST_HPP

#include "behaviour_script.hpp"
#include "physics_manager.hpp"
#include <memory>

class ColliderBehaviorTest : public BehaviourScript
{
  private:
    std::weak_ptr<PhysicsManager>
        physicsManager;               ///< the physicsmanager that is used to perform actions
    std::weak_ptr<GameObject> parent; ///< the parent of this behaviourscript

  public:
    /**
     * Constucts a colliderbehaviortest
     * @param physicsManagerPointer
     * @param parent
     */
    ColliderBehaviorTest(std::weak_ptr<PhysicsManager> physicsManagerPointer,
                         std::weak_ptr<GameObject> parent);

    /**
     * @brief Sent when another object enters a trigger collider
     *        attached to this object (2D physics only).
     */
    void OnTriggerEnter2D(const Collider &collider) override;

    /**
     * @brief Sent when another object leaves a trigger collider
     *        attached to this object (2D physics only).
     */
    void OnTriggerExit2D(const Collider &collider) override;

    /**
     * @brief Sent each frame where another object is within a trigger
     *        collider attached to this object (2D physics only).
     */
    void OnTriggerStay2D(const Collider &collider) override;
};

#endif // DEFUNBOBENGINE_COLLIDER_BEHAVIOR_TEST_HPP
