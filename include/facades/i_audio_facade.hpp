/**
 * @file i_audio_facade.hpp
 * @author "Melvin van Bree"
 * @brief An audio facade interface.
 * @version 0.1
 * @date 22/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_INCLUDE_FACADES_I_AUDIO_FACADE_HPP
#define DEFUNBOBENGINE_INCLUDE_FACADES_I_AUDIO_FACADE_HPP

#include <string>

const int MAX_SIMULTANEOUS_SOUNDS = 255;

class IAudioFacade
{
  public:
    virtual ~IAudioFacade() = default;

#pragma region Audio Manipulation
    // Volume
    virtual void SetVolume(float volume) = 0;
    [[nodiscard]] virtual float GetVolume() const = 0;

    // Pitch
    virtual void SetPitch(float pitch) = 0;
    [[nodiscard]] virtual float GetPitch() const = 0;

    // Pan
    virtual void SetPan(float pan) = 0;
    [[nodiscard]] virtual float GetPan() const = 0;
#pragma endregion

    virtual void PlayOneShot(const std::string &filePath, float volume = 1.0f) = 0;
};

#endif // DEFUNBOBENGINE_INCLUDE_FACADES_I_AUDIO_FACADE_HPP
