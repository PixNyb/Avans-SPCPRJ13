/**
 * @file input_facade.hpp
 * @author Martijn Vermeer
 * @brief Manages input events and provides an interface for handling input.
 * @version 0.1
 * @date 2023-11-20
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
#include <stdexcept>
#include <vector>

/**
 * @class SDLInputFacade
 * @brief Manages input events using SDL2 and provides an interface for handling input.
 *
 * The SDLInputFacade class implements the IInputFacade interface, managing input events
 * such as key presses and mouse actions. It allows the registration of listeners for key
 * and mouse events, tracks the state of pressed and released actions, and provides methods
 * for binding actions to events.
 *
 * @see IInputFacade
 * @see MouseListener
 * @see KeyListener
 * @see SDLEventListener
 * @see ActionType
 * @see Event
 * @version 0.1
 */
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
     * @brief Binds an action to a specific event.
     * @param key The Event representing the input event.
     * @param actionType The ActionType to associate with the event.
     */
    void Bind(const Event &key, const ActionType &actionType) override;

  private:
    std::unique_ptr<SDLEventListener>
        eventListener;                       ///< SDL event listener for handling input events.
    std::vector<ActionType> actionsReleased; ///< List of actions that have been released.
    std::vector<ActionType> actionsPressed;  ///< List of actions that are currently pressed.
    std::vector<std::unique_ptr<KeyListener>> keyListeners; ///< List of registered key listeners.
    std::vector<std::unique_ptr<MouseListener>>
        mouseListeners; ///< List of registered mouse listeners.

    /**
     * @brief Updates mouse-related events.
     */
    void UpdateMouseEvents();

    /**
     * @brief Updates key-related events.
     */
    void UpdateKeyEvents();
};

#endif // AVANS_SPCPRJ13_INPUT_MANAGER_HPP