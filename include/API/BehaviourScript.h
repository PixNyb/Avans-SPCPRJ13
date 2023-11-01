//
// Created by Robin on 30-10-2023.
//

#ifndef AVANS_SPCPRJ13_BEHAVIOURSCRIPT_H
#define AVANS_SPCPRJ13_BEHAVIOURSCRIPT_H

#include "Component.hpp"

class BehaviourScript : public Component {
public:
    BehaviourScript();
    virtual void OnStart() = 0;
    virtual void OnUpdate() = 0;
    // Add other virtual functions as needed
};

#endif //AVANS_SPCPRJ13_BEHAVIOURSCRIPT_H
