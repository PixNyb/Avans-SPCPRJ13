/**
 * @file key_listener.hpp
 * @author Martijn Vermeer
 * @brief Defines the KeyListener class, which implements the IKeyListener interface.
 * @version 0.1
 * @date 2023-11-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_KEY_LISTENER_HPP
#define DEFUNBOBENGINE_KEY_LISTENER_HPP

#include "action_type.hpp"
#include "ikey_listener.hpp"
#include "key_event.hpp"
#include <iostream>
#include <map>
#include <memory>
#include <vector>

/**
 * @class KeyListener
 * @brief Listens for key events and implements the IKeyListener interface.
 *
 * The KeyListener class is responsible for handling key events and implementing the
 * IKeyListener interface. It provides callbacks for both key pressed and key released events.
 */
class KeyListener : public IKeyListener
{
  public:
    /**
     * @brief Constructs a KeyListener with a specified key event.
     * @param keyEvent The key event associated with the listener.
     */
    KeyListener(const KeyEvent &keyEvent);

    /**
     * @brief Callback for when a key is pressed.
     */
    void OnKeyPressed() override;

    /**
     * @brief Callback for when a key is released.
     */
    void OnKeyReleased() override;

    /**
     * @brief Retrieves the key event associated with the listener.
     * @return The key event.
     */
    KeyEvent GetKeyEvent();

  private:
    KeyEvent keyEvent; ///< The key event associated with the listener.
};

#endif // DEFUNBOBENGINE_KEY_LISTENER_HPP
