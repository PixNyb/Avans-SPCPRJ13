/**
 * @file audio_source.hpp
 * @author Robin Pijnappels
 * @version 0.1
 * @date 2023-11-12
 *
 * @brief The AudioSource class provides audio playback functionality for game objects.
 * This class is part of a game engine, enabling the integration and control of audio elements.
 *
 * AudioSource allows game objects to have audio capabilities, like playing sound effects
 * or music. It supports various operations such as play, pause, and stop, and offers
 * controls for audio properties like volume and pitch.
 *
 * @copyright Copyright (c) 2023
 */

#ifndef AVANS_SPCPRJ13_AUDIOSOURCE_H
#define AVANS_SPCPRJ13_AUDIOSOURCE_H

#include "audio_facade.hpp"
#include "component.hpp"
#include <string>

/**
 * @class AudioSource
 * @brief Component for handling audio playback.
 *
 * AudioSource is a component that can be attached to game objects to enable audio playback.
 * It can play, pause, and stop audio clips, as well as control properties like volume and pitch.
 */
class AudioSource : public Component
{
  private:
    std::shared_ptr<ISound> sound;

  public:
    /**
     * @brief Construct a new Audio Source object
     *
     * @param audioClipPath Path to a locally stored audio file.
     */
    explicit AudioSource(std::string audioClipPath, bool playOnAwake = false, bool loop = false,
                         double volume = 1.0);

    /**
     * @brief Copy constructor for Component.
     *
     * Initializes a new Component with the values of an existing one.
     * @param other The Component to copy values from.
     */
    AudioSource(const AudioSource &other);

    /**
     * @brief Call this method to start playing audio.
     * @param looping Automatically start over when done.
     */
    void Play(bool looping = false);

    /**
     * @brief Call this method to set the volume of the audio.
     * @param volume The volume, between 0.0 and 1.0.
     */
    void SetPitch(float pitch);

    /**
     * @brief Call this method to pause playing audio.
     */
    void Pause();

    /**
     * @brief Call this method to stop playing audio.
     */
    void Stop();

    /**
     * @brief Set the active status of the Component, also stops the audio.
     */
    void SetActive(bool isActivate) override;

  private:
    /**
     * @brief Path to a locally stored audio file.
     */
    std::string audioClip;

    /**
     * @brief Whether to play the audio clip on creation
     */
    bool playOnAwake;

    /**
     * @brief The audio instance.
     */
    std::shared_ptr<ISound> audioInstance;
};

#endif // AVANS_SPCPRJ13_AUDIOSOURCE_H
