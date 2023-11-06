/// @file

#ifndef AVANS_SPCPRJ13_COMPONENT_H
#define AVANS_SPCPRJ13_COMPONENT_H

class Component {
protected:
  bool active;

public:
  Component();
  virtual ~Component() = 0; // Making it abstract
};

#endif // AVANS_SPCPRJ13_COMPONENT_H
