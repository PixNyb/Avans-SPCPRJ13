/**
 * @file animator.hpp
 * @author Roël Couwenberg (contact@roelc.me)
 * @brief This file contains the Animator class definition.
 * @version 0.1
 * @date 2023-11-16
 *
 * @copyright Copyright (c) 2023
 */

#ifndef AVANS_SPCPRJ13_ANIMATOR_H
#define AVANS_SPCPRJ13_ANIMATOR_H

#include "animation_state.hpp"
#include "behaviour_script.hpp"
#include <iostream>
#include <map>
#include <memory>
#include <vector>

/**
 * @brief The Animator class is a BehaviourScript that can be added to a
 * GameObject to animate it according to a state machine type of system.
 *
 */
class Animator : public BehaviourScript
{
  public:
    /**
     * @brief Default constructor for Animator.
     *
     * Initializes a new Animator with default values.
     */
    Animator(int columns, int rows) : totalColumns(columns), totalRows(rows) {}

    /**
     * @brief Copy constructor for Animator.
     *
     * Initializes a new Animator with the values of an existing one.
     * @param other The Animator to copy values from.
     */
    Animator(const Animator &other);

    /**
     * @brief Make a clone of the component.
     * @param parent The parent GameObject.
     * @return The cloned component.
     */
    std::shared_ptr<Component> Clone(std::weak_ptr<GameObject> parent) override;

    /**
     * @brief Update the Animator.
     *
     * This method is called every frame by the GameObject it is attached to. It checks whether or
     * not a new animation state should be set and if so, it sets the new state. Then it updates
     * according to the current state.
     *
     * TODO: Finish this method.
     */
    //    void Update();
    //
    //    void Stop();

    /**
     * @brief Add a new state to the Animator.
     *
     * This method adds a new state to the Animator. The state is identified by a name, which is
     * used to set the state later on.
     *
     * @param name The name of the state.
     * @param state The state to add.
     */
    void AddState(const std::string &name, const AnimationState &state);

    /**
     * @brief Set the state of the Animator.
     *
     * This method sets the state of the Animator to the state identified by the given name.
     *
     * @param name The name of the state to set.
     */
    void SetState(const std::string &name);

    /**
     * @brief Update the Animator.
     * @param deltaTime
     */
    void OnUpdate() override;

    /**
     * @brief Get the current frame index.
     * @return int The current frame index.
     */
    [[nodiscard]] int GetCurrentFrameIndex() const;

    /**
     * @brief Gets the total number of columns in the sprite sheet.
     * This function returns the total number of columns in the sprite sheet.
     * @return int The total number of columns in the sprite sheet.
     */
    [[nodiscard]] int GetTotalColumns() const { return this->totalColumns; };

    /**
     * @brief Gets the total number of rows in the sprite sheet.
     * This function returns the total number of rows in the sprite sheet.
     * @return int The total number of rows in the sprite sheet.
     */
    [[nodiscard]] int GetTotalRows() const { return this->totalRows; };

    /**
     * @brief Sets the total number of columns in the sprite sheet.
     * This function sets the total number of columns in the sprite sheet.
     * @param totalColumns The total number of columns in the sprite sheet.
     */
    void SetTotalColumns(int columns) { this->totalColumns = columns; }

    /**
     * @brief Sets the total number of rows in the sprite sheet.
     * This function sets the total number of rows in the sprite sheet.
     * @param totalRows The total number of rows in the sprite sheet.
     */
    void SetTotalRows(int rows) { this->totalRows = rows; }

    /**
     * @brief Sets the GameObject of the Animator.
     * This function sets the GameObject of the Animator.
     * @param gameObject The GameObject of the Animator.
     */
    void SetGameObject(std::weak_ptr<GameObject> gObject) { this->gameObject = gObject; }

  private:
    std::unique_ptr<AnimationState> currentState; ///< The current state of the Animator.
    std::map<std::string, AnimationState> states; ///< Map of animation states.
    int totalColumns;                             ///< The total number of columns in the sprite
    int totalRows;                                ///< The total number of rows in the sprite
    std::weak_ptr<GameObject> gameObject;         ///< The GameObject of the Animator.
};

#endif // AVANS_SPCPRJ13_ANIMATOR_H
