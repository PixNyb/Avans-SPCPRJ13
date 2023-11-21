/**
 * @file input_facade.hpp
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

#include "action_type.hpp"
#include "i_input_facade.hpp"
#include "key_listener.hpp"
#include "mouse_listener.hpp"
#include "sdl_event_listener.hpp"
#include <map>
#include <memory>
#include <vector>
#include <stdexcept>

class SDLInputFacade : public IInputFacade
{
  public:
    SDLInputFacade();

    /**
     * @brief Updates the input manager with the latest SDL events.
     */
    void Update() override;

    /**
     * @brief Registers a mouse listener for receiving mouse events.
     * @param mouseListener A unique pointer to an IMouseListener.
     */
    void RegisterMouseListener(std::unique_ptr<MouseListener> mouseListener) override;

    /**
     * @brief Registers a key listener for receiving key events.
     * @param keyListener A unique pointer to an IKeyListener.
     */
    void RegisterKeyListener(std::unique_ptr<KeyListener> keyListener) override;

    /**
     * @brief Checks if a specific action is currently pressed.
     * @param actionType The ActionType to check.
     * @return True if the action is currently pressed, false otherwise.
     */
    bool ActionPressed(const ActionType &actionType) const override;

    /**
     * @brief Checks if a specific action has been released.
     * @param actionType The ActionType to check.
     * @return True if the action has been released, false otherwise.
     */
    bool ActionReleased(const ActionType &actionType) const override;

    /**
     * @brief Binds an action to a specific event.
     * @param key The Event representing the input event.
     * @param actionType The ActionType to associate with the event.
     */
    void Bind(const Event &key, const ActionType &actionType) override;

  private:
    std::unique_ptr<SDLEventListener> eventListener;

    std::vector<ActionType> actionsReleased;
    std::vector<ActionType> actionsPressed;
    std::vector<std::unique_ptr<KeyListener>> keyListeners;
    std::vector<std::unique_ptr<MouseListener>> mouseListeners;

    void UpdateMouseEvents();
    void UpdateKeyEvents();
};

#endif // AVANS_SPCPRJ13_INPUT_MANAGER_HPP