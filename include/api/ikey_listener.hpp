/**
 * @file ikey_listener.hpp
 * @author Robin Pijnappels
 * @version 0.1
 * @date 2023-11-12
 *
 * @brief Defines the IKeyListener interface for handling keyboard events.
 * IKeyListener is an interface designed for objects that need to respond to keyboard events.
 * It includes virtual methods for handling key press and release events, allowing
 * implementing classes to define specific behaviors for these actions.
 * This interface is instrumental in creating interactive and responsive game objects.
 *
 * @copyright Copyright (c) 2023
 */

#ifndef IKEYLISTENER_H_
#define IKEYLISTENER_H_

#include "key_event.hpp"
#include "action_type.hpp"
#include <map>
#include <vector>
#include <memory>

/**
 * @class IKeyListener
 * @brief Interface for objects that respond to keyboard events.
 *
 * IKeyListener provides a structure for objects to handle keyboard input.
 * Implementing classes can define specific behaviors for key press and key release events.
 */
class IKeyListener {
    public:
        /**
         * @brief Virtual destructor.

         */
        virtual ~IKeyListener() = default;

        /**
         * @brief This method will be caled whenever a key is pressed.
         *        Override for implementing the desired behaviour.
         * @param event A shared pointer to a KeyEvent object representing the key event.
         * @param actionTypeKeyBinds A map associating Event objects with vectors of ActionType objects.
         *                           The map defines the actions to be performed for different key events.
         */
        virtual void OnKeyPressed(const std::shared_ptr<KeyEvent>& event, const std::map<Event, std::vector<ActionType>>& actionTypeKeyBinds) = 0;

        /**
         * @brief This method will be called whenever a pressed key is released again.
         *        Override for implementing the desired behaviour.

         */
        virtual void OnKeyReleased() = 0;
};

#endif // IKEYLISTENER_H_
