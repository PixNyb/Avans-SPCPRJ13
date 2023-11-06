/// @file

#ifndef AVANS_SPCPRJ13_CIRCLECOLLIDER_H
#define AVANS_SPCPRJ13_CIRCLECOLLIDER_H

#include "collider.hpp"

class CircleCollider : public Collider {
private:
  float radius;

public:
  CircleCollider();
  // Getters, Setters, and other public member functions ...
};

#endif // AVANS_SPCPRJ13_CIRCLECOLLIDER_H
