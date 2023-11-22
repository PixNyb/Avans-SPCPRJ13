/**
 * @file audio_manager.hpp
 * @author "Melvin van Bree"
 * @brief TODO
 * @version 0.1
 * @date 22/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_SRC_PROJECT_MANAGERS_AUDIO_MANAGER_HPP
#define DEFUNBOBENGINE_SRC_PROJECT_MANAGERS_AUDIO_MANAGER_HPP

#include <memory>
#include <string>

using audio_file_path = const std::string &;
using audio_instance = void *;
using audio_source = void *;

class AudioManager
{
  private:
    // Instances
    std::shared_ptr<audio_instance> instance;
    float volume = 1.0f;

  public:
    // Manipulation
    void SetVolume(float volume);
    float GetVolume() const;

    // Play audio
    std::weak_ptr<audio_source> CreateSound(audio_file_path filePath);
    void PlayOneShot(audio_file_path filePath, float volume = 1.0f);
};

#endif // DEFUNBOBENGINE_SRC_PROJECT_MANAGERS_AUDIO_MANAGER_HPP
