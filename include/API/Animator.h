//
// Created by Robin on 30-10-2023.
//

#ifndef AVANS_SPCPRJ13_ANIMATOR_H
#define AVANS_SPCPRJ13_ANIMATOR_H

#include "BehaviourScript.hpp"
#include "AnimationState.hpp"
#include <vector>
#include <map>

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

#endif //AVANS_SPCPRJ13_ANIMATOR_H
