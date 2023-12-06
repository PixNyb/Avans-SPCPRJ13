/**
 * @file sdl_input_facade.hpp
 * @author Roël Couwenberg (contact@roelc.me)
 * @brief This file contains the SDLInputFacade class definition.
 * @version 0.1
 * @date 2023-11-22
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef INPUT_FACADE_HPP_
#define INPUT_FACADE_HPP_

#include "../listeners/button_click_listener.hpp"
#include "i_input_facade.hpp"
#include "point.hpp"
#include "sdl_input.hpp"
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

/**
 * @class SDLInputFacade
 * @brief The SDLInputFacade class is responsible for handling input from the user.
 */
class SDLInputFacade : public IInputFacade
{
  public:
    SDLInputFacade();

    /**
     * @brief Update the SDLInput state.
     */
    void Update() override;

    /**
     * @brief Is any key or mouse button currently held down? (Read Only)
     */
    bool AnyKey() const override;

    /**
     * @brief Returns true the first frame the user hits any key or mouse button. (Read Only)
     */
    bool AnyKeyDown() const override;

    /**
     * @brief Returns true the first frame the user releases any key or mouse button. (Read Only)
     */
    bool AnyKeyUp() const override;

    /**
     * @brief The current mouse position in pixel coordinates. (Read Only)
     */
    Point GetMousePosition() const override;

    /**
     * @brief Returns the value of the virtual axis identified by axisName.
     * @warning This function is not implemented yet.
     */
    double GetAxis() const override;

    /**
     * @brief Returns true while the user holds down the key identified by keycode.
     *
     * @param key The key to check.
     */
    bool GetKey(KeyCode key) const override;

    /**
     * @brief Returns true during the frame the user starts pressing down the key identified by
     * keycode.
     *
     * @param key The key to check.
     */
    bool GetKeyDown(KeyCode key) const override;

    /**
     * @brief Returns true during the frame the user releases the key identified by keycode.
     *
     * @param key The key to check.
     */
    bool GetKeyUp(KeyCode key) const override;

    /**
     * @brief Returns whether the given mouse button is held down.
     *
     * @param which The mouse button to check.
     */
    bool GetMouseButton(MouseButton which) const override;

    /**
     * @brief Returns true during the frame the user pressed the given mouse button.
     *
     * @param which The mouse button to check.
     */
    bool GetMouseButtonDown(MouseButton which) const override;

    /**
     * @brief Returns true during the frame the user releases the given mouse button.
     *
     * @param which The mouse button to check.
     */
    bool GetMouseButtonUp(MouseButton which) const override;

    /**
     * @brief Register an action with the input system.
     *
     * @param action The action to register.
     */
    void RegisterAction(const std::string &action) override;

    /**
     * @brief Unregister an action from the input system.
     *
     * @param action The action to unregister.
     */
    void UnregisterAction(const std::string &action) override;

    /**
     * @brief Get the keys bound to the given action.
     *
     * @param action The action to get the keys for.
     * @return The keys bound to the given action.
     */
    std::vector<KeyCode> GetKeysForAction(const std::string &action) const override;

    /**
     * @brief Get the mouse buttons bound to the given action.
     *
     * @param action The action to get the mouse buttons for.
     * @return The mouse buttons bound to the given action.
     */
    std::vector<MouseButton> GetMouseButtonsForAction(const std::string &action) const override;

    /**
     * @brief Get the actions currently registered with the input system.
     *
     * @return The actions currently registered with the input system.
     */
    std::vector<std::string> GetActions() const override;

    /**
     * @brief Bind the given key to the given action.
     *
     * @param key The key to bind.
     * @param action The action to bind the key to.
     */
    void BindKey(KeyCode key, const std::string &action) override;

    /**
     * @brief Bind the given mouse button to the given action.
     *
     * @param button The mouse button to bind.
     * @param action The action to bind the mouse button to.
     */
    void BindMouseButton(MouseButton button, const std::string &action) override;

    /**
     * @brief Unbind the given key from the given action.
     *
     * @param key The key to unbind.
     */
    void UnbindKey(KeyCode key) override;

    /**
     * @brief Unbind the given mouse button from the given action.
     *
     * @param button The mouse button to unbind.
     */
    void UnbindMouseButton(MouseButton button) override;

    /**
     * @brief Returns the action associated with the given key.
     *
     * @param key The key to get the action for.
     * @return The action associated with the key.
     */
    std::string GetActionForKey(KeyCode key) const override;

    /**
     * @brief Returns the action associated with the given mouse button.
     *
     * @param button The mouse button to get the action for.
     * @return The action associated with the mouse button.
     */
    std::string GetActionForMouseButton(MouseButton button) const override;

    /**
     * @brief Checks if any action is currently being performed.
     *
     * @return True if any action is being performed, false otherwise.
     */
    bool AnyAction() const override;

    /**
     * @brief Checks if any action has just started being performed.
     *
     * @return True if any action has just started, false otherwise.
     */
    bool AnyActionDown() const override;

    /**
     * @brief Returns true during the frame the user starts performing any action.
     *
     * @return True if any action has just stopped, false otherwise.
     */
    bool AnyActionUp() const override;

    /**
     * @brief Returns true while the user holds down the given action.
     *
     * @note The 'quit' action is always true when the user is quitting the game, regardless of
     * whether it is registered or not.
     * @return True if any action is being performed, false otherwise.
     */
    bool GetAction(const std::string &action) const override;

    /**
     * @brief Returns true during the frame the user starts performing the given action.
     *
     * @return True if the action has just started, false otherwise.
     */
    bool GetActionDown(const std::string &action) const override;

    /**
     * @brief Returns true during the frame the user stops performing the given action.
     *
     * @return True if the action has just stopped, false otherwise.
     */
    bool GetActionUp(const std::string &action) const override;

    /**
     * @brief Add a button click listener to the input system.
     * @param buttonClickListener The button click listener to add.
     */
    void AddButtonClickListener(
        const std::shared_ptr<ButtonClickListener> &buttonClickListener) override;

    /**
     * @brief Get the button click listeners currently registered with the input system.
     * @return The button click listeners currently registered with the input system.
     */
    std::vector<ButtonClickListener> GetButtonClickListeners() const override;

  private:
    std::unique_ptr<SDLInput> input; ///< The SDLInput instance.
    std::unordered_map<std::string, std::vector<KeyCode>>
        keyActionMap; ///< The keybindings on the keyboard.
    std::unordered_map<std::string, std::vector<MouseButton>> mouseActionMap; ///< The keybindings
                                                                              ///< on the mouse.
    std::vector<ButtonClickListener>
        buttonClickListeners; ///< The button click listeners registered.
};

#endif // INPUT_FACADE_HPP_