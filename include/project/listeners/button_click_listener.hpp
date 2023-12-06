#ifndef DEFUNBOBENGINE_BUTTON_CLICK_LISTENER_HPP
#define DEFUNBOBENGINE_BUTTON_CLICK_LISTENER_HPP

#include "imouse_listener.hpp"
#include "button.hpp"

class ButtonClickListener : public IMouseListener {
  private:
    std::shared_ptr<Button> button;
    Point mousePos;

  public:
    ButtonClickListener(const std::shared_ptr<Button> &button);

    void SetMousePosition(const Point& mousePos);
    void OnMouseMoved() override;
    void OnMouseClicked() override;
    void OnMousePressed() override;
    void OnMouseReleased() override;
};

#endif // DEFUNBOBENGINE_BUTTON_CLICK_LISTENER_HPP
