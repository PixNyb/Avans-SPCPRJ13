/// @file

#ifndef IKEYLISTENER_H_
#define IKEYLISTENER_H_

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
        virtual void OnKeyPressed() = 0;

        /**
         * @brief This method will be called whenever a pressed key is released again.
         *        Override for implementing the desired behaviour.

         */
        virtual void OnKeyReleased() = 0;
};

#endif // IKEYLISTENER_H_