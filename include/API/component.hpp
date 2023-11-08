/**
 * @file component.hpp
 * @author Roël Couwenberg (contact@roelc.me)
 * @brief This file contains the Component class definition.
 * @version 0.1
 * @date 2023-11-08
 *
 * @copyright Copyright (c) 2023
 *
 */

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
