/**
 * @file component.hpp
 * @author Roël Couwenberg (contact@roelc.me)
 * @brief This file contains the Component class definition.
 * @version 0.1
 * @date 2023-11-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef AVANS_SPCPRJ13_COMPONENT_H
#define AVANS_SPCPRJ13_COMPONENT_H

/**
 * @class Component
 * @brief The Component class is a base class for all components that can be
 * added to a GameObject.
 *
 * It contains an active flag and methods for getting/setting the active status,
 * updating the component, and checking a condition.
 */
class Component
{
  protected:
    bool active; ///< The active flag of the Component.

  public:
    /**
     * @brief Default constructor for Component.
     *
     * Initializes a new Component with default values.
     */
    Component();

    /**
     * @brief Pure virtual destructor for Component.
     *
     * A pure virtual destructor is needed to make this class abstract.
     */
    virtual ~Component() = default;

    /**
     * @brief Copy constructor for Component.
     *
     * Initializes a new Component with the values of an existing one.
     * @param other The Component to copy values from.
     */
    Component(const Component &other);

    /**
     * @brief Check if the Component is active.
     *
     * @return True if the Component is active, false otherwise.
     */
    [[nodiscard]] bool IsActive() const;

    /**
     * @brief Set the active status of the Component.
     *
     * Sets the active status of the Component to the given value.
     * @param active The new active status of the Component.
     */
    void SetActive(bool active);

    /**
     * @brief Update the Component.
     *
     * This method should be overridden by subclasses to provide specific update
     * behavior.
     */
    virtual void Update();

    /**
     * @brief Check a condition.
     *
     * This method should be overridden by subclasses to provide specific
     * condition checking behavior.
     */
    virtual void Condition();
};

#endif // AVANS_SPCPRJ13_COMPONENT_H
