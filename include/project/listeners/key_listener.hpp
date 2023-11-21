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
#include "action_type.hpp"
#include <map>
#include <vector>
#include <memory>
#include <iostream>

class KeyListener : public IKeyListener {
public:
    KeyListener(const KeyEvent &keyEvent);

    void OnKeyPressed() override;
    void OnKeyReleased() override;

private:
    KeyEvent keyEvent;
};

#endif //DEFUNBOBENGINE_KEY_LISTENER_HPP
