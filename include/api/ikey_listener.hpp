/// @file

#ifndef IKEYLISTENER_H_
#define IKEYLISTENER_H_

#include "key_event.hpp"
#include "action_type.hpp"
#include <map>
#include <vector>
#include <memory>

/**
 * @brief Interface for objects wanting to respond to keyboard events.
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

         */
        virtual void OnKeyPressed(const std::shared_ptr<KeyEvent>& event, const std::map<Event, std::vector<ActionType>>& actionTypeKeyBinds) = 0;

        /**
         * @brief This method will be called whenever a pressed key is released again.
         *        Override for implementing the desired behaviour.

         */
        virtual void OnKeyReleased() = 0;
};

#endif // IKEYLISTENER_H_
