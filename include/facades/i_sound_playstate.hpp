/**
 * @file i_sound_playstate.hpp
 * @author "Melvin van Bree"
 * @brief The playstate of a sound
 * @version 0.1
 * @date 22/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_INCLUDE_FACADES_I_SOUND_PLAYSTATE_HPP
#define DEFUNBOBENGINE_INCLUDE_FACADES_I_SOUND_PLAYSTATE_HPP

/**
 * @brief The play state of a sound
 */
enum class SoundPlayState
{
    Playing, ///< The sound is playing
    Stopped, ///< The sound is stopped and can be played again
    Paused   ///< The sound is paused and can be resumed
};

#endif // DEFUNBOBENGINE_INCLUDE_FACADES_I_SOUND_PLAYSTATE_HPP
