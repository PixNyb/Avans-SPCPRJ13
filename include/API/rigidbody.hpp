//
// Created by Robin on 30-10-2023.
//

#ifndef AVANS_SPCPRJ13_RIGIDBODY_H
#define AVANS_SPCPRJ13_RIGIDBODY_H

#include "component.hpp"

class Rigidbody : public Component
{
private:
    float mass;
    float gravityScale;
    // bodyType can also be enum maybe?
    std::string bodyType;

public:
    Rigidbody();
    // Getters, Setters, and other public member functions ...
};

#endif // AVANS_SPCPRJ13_RIGIDBODY_H
