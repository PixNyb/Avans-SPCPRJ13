/// @file

#ifndef AVANS_SPCPRJ13_COLLIDER_H
#define AVANS_SPCPRJ13_COLLIDER_H

class Collider {
protected:
  bool active;

public:
  Collider();
  virtual ~Collider() = 0; // Making it abstract
};

#endif // AVANS_SPCPRJ13_COLLIDER_H
