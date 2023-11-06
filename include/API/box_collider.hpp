/// @file

#ifndef AVANS_SPCPRJ13_BOXCOLLIDER_H
#define AVANS_SPCPRJ13_BOXCOLLIDER_H

#include "collider.hpp"

class BoxCollider : public Collider {
private:
  float width, height;

public:
  BoxCollider();
  // Getters, Setters, and other public member functions ...
};

#endif // AVANS_SPCPRJ13_BOXCOLLIDER_H
