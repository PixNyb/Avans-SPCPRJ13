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

    void AddState(const std::string& name, const AnimationState& state);
    void SetState(const std::string& name);
    void Update(float deltaTime);
    int GetCurrentFrame() const;

  private:
    /**
     * @brief The current state of the Animator.
     *
     */
    AnimationState* currentState;

    /**
     * @brief A map of possible states for the Animator.
     *
     */
    std::map<std::string, AnimationState> possibleStates;
};

#endif // AVANS_SPCPRJ13_ANIMATOR_H
