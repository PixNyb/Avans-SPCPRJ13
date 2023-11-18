#ifndef DEFUNBOBENGINE_MOUSE_LISTENER_HPP
#define DEFUNBOBENGINE_MOUSE_LISTENER_HPP

#include "imouse_listener.hpp"

class MouseListener : public IMouseListener {
public:
    void OnMouseMoved(const std::shared_ptr<MouseEvent>& event) override;
    void OnMouseClicked() override;
    void OnMousePressed(const std::shared_ptr<MouseEvent>& event, const std::map<Event, std::vector<ActionType>>& actionTypeKeyBinds) override;
    void OnMouseReleased() override;
};

#endif //DEFUNBOBENGINE_MOUSE_LISTENER_HPP
