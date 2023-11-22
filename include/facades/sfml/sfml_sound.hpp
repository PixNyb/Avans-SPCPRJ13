/**
 * @file sfml_sound.hpp
 * @author "Melvin van Bree"
 * @brief TODO
 * @version 0.1
 * @date 22/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_INCLUDE_FACADES_SFML_SFML_SOUND_HPP
#define DEFUNBOBENGINE_INCLUDE_FACADES_SFML_SFML_SOUND_HPP

#include "i_sound.hpp"
#include "i_sound_playstate.hpp"
#include <SFML/Audio.hpp>

class SFMLSound : public ISound
{
  private:
    sf::Sound sound;        ///< sound
    sf::SoundBuffer buffer; ///< sound buffer

  public:
    /**
     * @brief Construct a new SFMLSound object
     *
     * @param filePath The path to the audio file.
     */
    explicit SFMLSound(const std::string &filePath);

    /**
     * @brief Destroy the SFMLSound object
     */
    ~SFMLSound() override;

    // Volume
    void SetVolume(float volume) override;
    float GetVolume() const override;

    // Pitch
    void SetPitch(float pitch) override;
    float GetPitch() const override;

    // State
    SoundPlayState GetState() const override;

    /**
     * @brief Plays the sound.
     *
     * @details This function starts the stream if it was stopped, resumes it if it was paused, and
     * restarts it from beginning if it was it already playing. This function uses its own thread so
     * that it doesn't block the rest of the program while the sound is played.
     */
    void Play() override;

    /**
     * @brief Stops the sound.
     *
     * @details This function stops the sound if it was playing or paused, and does nothing if it
     * was already stopped. It also resets the playing position (unlike pause()).
     */
    void Stop() override;
    
    /**
     * @brief Pauses the sound.
     *
     * @details This function pauses the sound if it was playing, otherwise (sound already paused or
     * stopped) it has no effect.
     */
    void Pause() override;
    void Resume() override;
};

#endif // DEFUNBOBENGINE_INCLUDE_FACADES_SFML_SFML_SOUND_HPP
