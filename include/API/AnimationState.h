//
// Created by Robin on 30-10-2023.
//

#ifndef AVANS_SPCPRJ13_ANIMATIONSTATE_H
#define AVANS_SPCPRJ13_ANIMATIONSTATE_H

#include <map>
#include <string>
#include "GameObject.h"

class AnimationState {
private:
    std::map<std::string, AnimationState> states;

public:
    AnimationState();
    void Update(GameObject& gameObject);
    // Getters, Setters, and other public member functions ...
};

#endif //AVANS_SPCPRJ13_ANIMATIONSTATE_H
