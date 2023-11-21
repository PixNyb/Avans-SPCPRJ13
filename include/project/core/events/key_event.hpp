/**
 * @file key_event.hpp
 * @author Martijn Vermeer
 * @brief This file contains the key event class definition.
 * @version 0.1
 * @date 2023-11-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_KEY_EVENT_HPP
#define DEFUNBOBENGINE_KEY_EVENT_HPP

#include "event.hpp"

class KeyEvent : public Event
{
  public:
    explicit KeyEvent(KeyCode keyCode, EventType eventType);

  private:
};

#endif // DEFUNBOBENGINE_KEY_EVENT_HPP
