#ifndef DEFUNBOBENGINE_IINPUTHANDLER_HPP
#define DEFUNBOBENGINE_IINPUTHANDLER_HPP

#include "event.hpp"
#include "key_event.hpp"
#include "mouse_event.hpp"
#include <iostream>
#include <vector>
#include <memory>

class IInputHandler {
public:
    virtual ~IInputHandler() = default;

    virtual void PollEvents(std::vector<Event>& events) = 0;

    [[nodiscard]] virtual std::shared_ptr<KeyEvent> getLastPolledKeyEvent() const = 0;

    [[nodiscard]] virtual std::shared_ptr<MouseEvent> getLastPolledMouseEvent() const = 0;
};

#endif //DEFUNBOBENGINE_IINPUTHANDLER_HPP
