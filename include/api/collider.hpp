/**
 * @file collider.hpp
 * @author Daan Groot (d.groot3@student.avans.nl)
 * @brief This file contains the Collider class definition.
 * @version 0.1
 * @date 2023-11-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef COLLIDER2D_H_
#define COLLIDER2D_H_

#include "component.hpp"

/**
 * @brief The base class for all colliders.
 */
class Collider : public Component {
private:

public:
    /**
    * @brief Update the Component.
    *
    * This method updates the collider by
    */
    void Update() override;

    /**
     * @brief Check a condition.
     *
     * This method should be overridden by subclasses to provide specific
     * condition checking behavior.
     */
    void Condition() override;
};

#endif // COLLIDER2D_H_
