#ifndef DEFUNBOBENGINE_KEY_LISTENER_HPP
#define DEFUNBOBENGINE_KEY_LISTENER_HPP

#include "ikey_listener.hpp"

class KeyListener : public IKeyListener {
public:
    void OnKeyPressed(const std::shared_ptr<KeyEvent>&, const std::map<Event, std::vector<ActionType>>& actionTypeKeyBinds) override;
    void OnKeyReleased() override;
};

#endif //DEFUNBOBENGINE_KEY_LISTENER_HPP
