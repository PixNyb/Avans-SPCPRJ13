/**
 * @file animation_state.hpp
 * @author Roël Couwenberg (contact@roelc.me)
 * @brief This file contains the AnimationState class definition.
 * @version 0.1
 * @date 2023-11-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef AVANS_SPCPRJ13_ANIMATIONSTATE_H
#define AVANS_SPCPRJ13_ANIMATIONSTATE_H

#include "game_object.hpp"
#include <map>
#include <string>

/**
 * @class AnimationState
 * @brief Manages the states of an animation.
 *
 * This class is responsible for handling different states of an animation.
 * It maintains a map of states and provides functionalities to update
 * the animation based on the current state.
 */
class AnimationState
{
  private:
    /**
     * @brief Map to hold various animation states.
     *
     * This map associates state names with their corresponding AnimationState objects.
     */
    std::map<std::string, AnimationState> states;

  public:
    /**
     * @brief Constructs a new AnimationState object.
     *
     * Initializes a new instance of the AnimationState class.
     */
    AnimationState();

    /**
     * @brief Updates the animation state of the given game object.
     *
     * This function updates the state of an animation based on the current state
     * and the properties of the provided game object.
     *
     * @param gameObject The game object whose animation state is to be updated.
     */
    void Update(GameObject &gameObject);
    // Getters, Setters, and other public member functions ...
};

#endif // AVANS_SPCPRJ13_ANIMATIONSTATE_H
