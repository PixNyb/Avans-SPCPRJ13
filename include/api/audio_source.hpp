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

#include <string>
#include "component.hpp"

/**
 * @class AudioSource
 * @brief Component for handling audio playback.
 *
 * AudioSource is a component that can be attached to game objects to enable audio playback.
 * It can play, pause, and stop audio clips, as well as control properties like volume and pitch.
 */
class AudioSource : public Component {
public:
    AudioSource();
    AudioSource(const std::string &audioClipPath);

    /**
     * @brief Call this method to start playing audio.
     * @param looping Automatically start over when done.
     */
    void Play(bool looping);

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

private:
    /**
     * @brief Path to a locally stored audio file.
     */
    std::string audioClip;

    /**
     * @brief When true, the component will start playing automatically.
     */
    bool playOnAwake;

    /**
     * @brief When true, the audio will play indefinitely.
     */
    bool loop;

    /**
     * @brief Audio volume, between 0.0 and 1.0.
     */
    double volume;
};

#endif // AVANS_SPCPRJ13_AUDIOSOURCE_H
