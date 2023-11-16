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

class AnimationState
{
  private:
    /**
     * @brief A 
     *
     */
    std::map<std::string, AnimationState> states;

  public:
    AnimationState();
    void Update(GameObject &gameObject);
    // Getters, Setters, and other public member functions ...
};

#endif // AVANS_SPCPRJ13_ANIMATIONSTATE_H
