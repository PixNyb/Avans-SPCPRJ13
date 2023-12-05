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
    Animator();

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
    void Update();

    // TODO: Finish these methods, and add methods for adding and removing states.
    void Stop();
    void Play(bool looping);

    /**
     * @brief Add a new state to the Animator.
     *
     * This method adds a new state to the Animator. The state is identified by a name, which is
     * used to set the state later on.
     *
     * @param name The name of the state.
     * @param state The state to add.
     */
    [[gnu::used]] void AddState(const std::string &name, const AnimationState &state);

    /**
     * @brief Set the state of the Animator.
     *
     * This method sets the state of the Animator to the state identified by the given name.
     *
     * @param name The name of the state to set.
     */
    [[gnu::used]] void SetState(const std::string &name);

    /**
     * @brief Update the Animator.
     * @param deltaTime
     */
    virtual void OnUpdate() override;

    /**
     * @brief Get the current frame index.
     * @return int The current frame index.
     */
    int GetCurrentFrameIndex() const;

  private:
    /**
     * @brief The current state of the Animator.
     *
     */
    std::unique_ptr<AnimationState> currentState;

    /**
     * @brief A map of possible states for the Animator.
     *
     */
    std::map<std::string, AnimationState> states;
};

#endif // AVANS_SPCPRJ13_ANIMATOR_H
