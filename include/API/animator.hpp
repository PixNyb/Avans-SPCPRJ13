/// @file

#ifndef AVANS_SPCPRJ13_ANIMATOR_H
#define AVANS_SPCPRJ13_ANIMATOR_H

#include "animation_state.hpp"
#include "behaviour_script.hpp"
#include <map>
#include <vector>

class Animator : public BehaviourScript {
private:
  AnimationState currentState;
  std::map<std::string, AnimationState> possibleStates;

public:
  Animator();
  void Update();
  void Stop();
  void Play(bool looping);
  // Getters, Setters, and other public member functions ...
};

#endif // AVANS_SPCPRJ13_ANIMATOR_H
