/**
 * @file input_manager.hpp
 * @author Martijn Vermeer
 * @brief Manages input events and provides an interface for handling input.
 * @version 0.1
 * @date 2023-11-20
 *
 * The InputManager class handles input events such as key presses and mouse actions.
 * It allows the registration of listeners for key and mouse events, tracks the state of
 * pressed and released actions, and provides methods for binding actions to events.
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef AVANS_SPCPRJ13_INPUT_MANAGER_HPP
#define AVANS_SPCPRJ13_INPUT_MANAGER_HPP

//#include "../../api/imouse_listener.hpp"
//#include "../../api/ikey_listener.hpp"
#include "key_listener.hpp"
#include "mouse_listener.hpp"
#include "action_type.hpp"
#include "sdl2_input_handler.hpp"
#include <vector>
#include <map>
#include <memory>

class InputManager {
  public:
    InputManager();

    /**
     * @brief Updates the input manager with the latest SDL events.
     */
    void Update();

    /**
     * @brief Registers a mouse listener for receiving mouse events.
     * @param mouseListener A unique pointer to an IMouseListener.
     */
    void RegisterMouse(std::unique_ptr<IMouseListener> mouseListener);

    /**
    * @brief Registers a key listener for receiving key events.
    * @param keyListener A unique pointer to an IKeyListener.
    */
    void RegisterKeyListener(std::unique_ptr<IKeyListener> keyListener);

    /**
     * @brief Checks if a specific action is currently pressed.
     * @param actionType The ActionType to check.
     * @return True if the action is currently pressed, false otherwise.
     */
    [[nodiscard]] bool ActionPressed(const ActionType& actionType) const;

    /**
     * @brief Checks if a specific action has been released.
     * @param actionType The ActionType to check.
     * @return True if the action has been released, false otherwise.
     */
    [[nodiscard]] bool ActionReleased(const ActionType& actionType) const;

    /**
     * @brief Binds an action to a specific event.
     * @param key The Event representing the input event.
     * @param actionType The ActionType to associate with the event.
     */
    void Bind(const Event& key, const ActionType& actionType);

    /**
     * @brief Retrieves the SDL input handler.
     * @return A const reference to the unique pointer of the SDL input handler.
     */
    [[nodiscard]] const std::unique_ptr<IInputHandler>& GetSDLInputHandler() const;

  private:
    std::vector<ActionType> actionsReleased;
    std::vector<ActionType> actionsPressed;
    std::unique_ptr<IInputHandler> sdlInputHandler;
    std::vector<std::unique_ptr<IKeyListener>> keyListeners;
    std::vector<std::unique_ptr<IMouseListener>> mouseListeners;
    std::map<Event, std::vector<ActionType>> actionTypeKeyBinds;
};

#endif // AVANS_SPCPRJ13_INPUT_MANAGER_HPP