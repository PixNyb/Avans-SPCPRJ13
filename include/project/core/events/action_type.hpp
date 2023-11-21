/**
 * @file action_type.hpp
 * @author Martijn Vermeer
 * @brief This file contains the action type class definition.
 * @version 0.1
 * @date 2023-11-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef AVANS_SPCPRJ13_ACTION_TYPE_HPP
#define AVANS_SPCPRJ13_ACTION_TYPE_HPP

/**
 * @class ActionType
 * @brief Enumerates the possible actions that can be performed in a game.
 *
 * The ActionType enum class defines a set of actions that can be performed by a game entity.
 */
enum class ActionType
{
    NONE,    ///< No specific action.
    JUMP,    ///< Jump action.
    PAUSE,   ///< Pause the game.
    GOLEFT,  ///< Move left.
    GORIGHT, ///< Move right.
    GOUP,    ///< Move up.
    GODOWN,  ///< Move down.
};

#endif // AVANS_SPCPRJ13_ACTION_TYPE_HPP
