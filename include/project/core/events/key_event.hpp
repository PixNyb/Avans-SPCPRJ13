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

/**
 * @class KeyEvent
 * @brief Represents a keyboard event.
 *
 * The KeyEvent class is derived from the base Event class and provides specific
 * functionality for keyboard events.
 */
class KeyEvent : public Event
{
  public:
    /**
     * @brief Constructs a KeyEvent object.
     * @param keyCode The code associated with the pressed or released key.
     * @param eventType The type of keyboard event (key pressed or key released).
     */
    explicit KeyEvent(KeyCode keyCode, EventType eventType);

  private:
};

#endif // DEFUNBOBENGINE_KEY_EVENT_HPP
