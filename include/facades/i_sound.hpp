/**
 * @file i_sound.hpp
 * @author "Melvin van Bree"
 * @brief A sound wrapper
 * @version 0.1
 * @date 22/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_INCLUDE_FACADES_I_SOUND_HPP
#define DEFUNBOBENGINE_INCLUDE_FACADES_I_SOUND_HPP

#include "i_sound_playstate.hpp"
class ISound
{
  public:
    virtual ~ISound() = default;
    /**
     * @brief Set the volume of the sound.
     * @param volume The volume of the sound between 0 and 100.
     */
    virtual void SetVolume(float volume) = 0;

    /**
     * @brief Get the volume of the sound.
     * @return float The volume of the sound between 0 and 100.
     */
    [[nodiscard]] virtual float GetVolume() const = 0;

    /**
     * @brief Set the pitch of the sound.
     * @param pitch The pitch of the sound.
     */
    virtual void SetPitch(float pitch) = 0;

    /**
     * @brief Get the pitch of the sound.
     * @return float The pitch of the sound.
     */
    [[nodiscard]] virtual float GetPitch() const = 0;

    /**
     * @brief Get the sound state. Either playing, paused or stopped.
     * @return SoundPlayState
     */
    [[nodiscard]] virtual SoundPlayState GetState() const = 0;

    /**
     * @brief Plays the sound.
     */
    virtual void Play() = 0;

    /**
     * @brief Stops the sound.
     */
    virtual void Stop() = 0;

    /**
     * @brief Pauses the sound.
     */
    virtual void Pause() = 0;

    /**
     * @brief Resumes the sound.
     */
    virtual void Resume() = 0;
};

#endif // DEFUNBOBENGINE_INCLUDE_FACADES_I_SOUND_HPP
