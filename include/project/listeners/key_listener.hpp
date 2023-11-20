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

#include "ikey_listener.hpp"
#include "key_event.hpp"

class KeyListener : public IKeyListener {
public:
    void OnKeyPressed() override;
    void OnKeyReleased() override;

    void SetKeyEvent(const KeyEvent& keyEvent);

private:
    KeyEvent keyEvent;
};

#endif //DEFUNBOBENGINE_KEY_LISTENER_HPP
