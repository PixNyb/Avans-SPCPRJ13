/// @file

#ifndef AVANS_SPCPRJ13_ANIMATIONSTATE_H
#define AVANS_SPCPRJ13_ANIMATIONSTATE_H

#include "game_object.hpp"
#include <map>
#include <string>

class AnimationState {
private:
  std::map<std::string, AnimationState> states;

public:
  AnimationState();
  void Update(GameObject &gameObject);
  // Getters, Setters, and other public member functions ...
};

#endif // AVANS_SPCPRJ13_ANIMATIONSTATE_H
