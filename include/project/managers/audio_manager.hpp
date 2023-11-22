/**
 * @file audio_manager.hpp
 * @author "Melvin van Bree"
 * @brief A manager that manages all audio instances.
 * @version 0.1
 * @date 22/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_SRC_PROJECT_MANAGERS_AUDIO_MANAGER_HPP
#define DEFUNBOBENGINE_SRC_PROJECT_MANAGERS_AUDIO_MANAGER_HPP

#include "i_sound.hpp"
#include <chrono>
#include <memory>
#include <string>
#include <vector>

using audio_file_path = const std::string &;
using audio_instance = ISound;

/**
 * @brief Audio manager that managed all audio instances.
 *
 * @details At some point the instances will be cleaned up when the audio is done playing.
 * We pass a weak pointer to the user so it can still be cleaned up.
 *
 * @warning If a user owns the pointer (weak reference is transformed into ownership), the user will
 * be responsible for it. However, it will be removed from the manager.
 *
 * @warning Cleanup will only work when update is used.
 */
class AudioManager
{
  private:
    // Instances
    std::vector<std::shared_ptr<audio_instance>> audioInstances; ///< All audio instances
    uint64_t lastTimeStamp;                                      ///< The time since cleanup

    /**
     * @brief Cleans up all audio instances.
     * @details This will remove all audio instances that are done playing.
     * This is based on the play state of the audio instance and if it has played before.
     */
    void Cleanup();

  public:
    AudioManager();

    /**
     * @brief Updates the audio manager.
     * @details Primarily used for cleanup.
     */
    void Update();

    /**
     * @brief Creates a sound instance.
     * @param filePath The path to the audio file.
     * @return A weak pointer to the audio instance.
     *
     * @note The user is primarily responsible for the pointer if it is transformed into a shared
     * pointer. Avoid this by only accessing the pointer within a function scope.
     */
    std::weak_ptr<audio_instance> CreateSound(audio_file_path filePath);

    /**
     * @brief Destroys a sound instance.
     * @param sound The sound instance to destroy.
     */
    void DestroySound(std::weak_ptr<audio_instance> sound);

    /**
     * @brief Plays a sound once.
     * @param filePath The path to the audio file.
     * @param volume The volume of the audio file. (optional)
     */
    void PlayOneShot(audio_file_path filePath, float volume = 100.0f);

    /**
     * @brief Forces a cleanup of all audio instances.
     */
    void ForceClean();
};

#endif // DEFUNBOBENGINE_SRC_PROJECT_MANAGERS_AUDIO_MANAGER_HPP
