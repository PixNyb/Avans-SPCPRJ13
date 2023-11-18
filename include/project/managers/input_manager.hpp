#ifndef AVANS_SPCPRJ13_INPUT_MANAGER_HPP
#define AVANS_SPCPRJ13_INPUT_MANAGER_HPP

#include "../../api/imouse_listener.hpp"
#include "../../api/ikey_listener.hpp"
#include "action_type.hpp"
#include "sdl2_input_handler.hpp"
#include <vector>
#include <map>
#include <memory>

class InputManager {
  public:
    InputManager();

    void update(std::vector<SDL_Event>& events);
    void registerMouse(std::unique_ptr<IMouseListener> mouseListener);
    void registerKey(std::unique_ptr<IKeyListener> keyListener);
    [[nodiscard]] bool actionPressed(const ActionType& actionType) const;
    [[nodiscard]] bool actionReleased(const ActionType& actionType) const;
    void bind(const Event& key, const ActionType& actionType);
    [[nodiscard]] const std::unique_ptr<IInputHandler>& getSDLInputHandler() const;
  private:
    std::vector<ActionType> actionsReleased;
    std::vector<ActionType> actionsPressed;
    std::unique_ptr<IInputHandler> sdlInputHandler;
    std::vector<std::unique_ptr<IKeyListener>> keyListeners;
    std::vector<std::unique_ptr<IMouseListener>> mouseListeners;
    std::map<Event, std::vector<ActionType>> actionTypeKeyBinds;
};

#endif // AVANS_SPCPRJ13_INPUT_MANAGER_HPP