/// @file

#ifndef AVANS_SPCPRJ13_AUDIOSOURCE_H
#define AVANS_SPCPRJ13_AUDIOSOURCE_H

#include <string>
#include "component.hpp"

/**
 * @brief Component which can play audio.
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
