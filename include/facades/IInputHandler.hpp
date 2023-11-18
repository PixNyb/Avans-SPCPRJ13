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

    virtual void PollEvents(std::vector<SDL_Event>& sdlEvents) = 0;

    [[nodiscard]] virtual std::vector<std::shared_ptr<KeyEvent>> getPolledKeyEvents() const = 0;

    [[nodiscard]] virtual std::vector<std::shared_ptr<MouseEvent>> getPolledMouseEvents() const = 0;
};

#endif //DEFUNBOBENGINE_IINPUTHANDLER_HPP
