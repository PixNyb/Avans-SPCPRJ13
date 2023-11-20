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

class KeyListener : public IKeyListener {
public:
    void OnKeyPressed(const std::shared_ptr<KeyEvent>& event, const std::map<Event, std::vector<ActionType>>& actionTypeKeyBinds) override;
    void OnKeyReleased() override;
};

#endif //DEFUNBOBENGINE_KEY_LISTENER_HPP
