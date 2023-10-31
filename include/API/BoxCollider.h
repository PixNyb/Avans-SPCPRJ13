//
// Created by Robin on 30-10-2023.
//

#ifndef AVANS_SPCPRJ13_BOXCOLLIDER_H
#define AVANS_SPCPRJ13_BOXCOLLIDER_H

#include "Collider.hpp"

class BoxCollider : public Collider {
private:
    float width, height;

public:
    BoxCollider();
    // Getters, Setters, and other public member functions ...
};

#endif //AVANS_SPCPRJ13_BOXCOLLIDER_H
