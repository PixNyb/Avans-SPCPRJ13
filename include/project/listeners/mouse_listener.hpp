#ifndef DEFUNBOBENGINE_MOUSE_LISTENER_HPP
#define DEFUNBOBENGINE_MOUSE_LISTENER_HPP

#include "imouse_listener.hpp"

class MouseListener : public IMouseListener {
public:
    void OnMouseMoved() override;
    void OnMouseClicked(const std::shared_ptr<MouseEvent>& event, const std::map<Event, std::vector<ActionType>>& actionTypeKeyBinds) override;
    void OnMousePressed() override;
    void OnMouseReleased() override;
};

#endif //DEFUNBOBENGINE_MOUSE_LISTENER_HPP
