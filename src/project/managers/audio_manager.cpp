/**
 * @file audio_manager.cpp
 * @author "Melvin van Bree"
 * @brief Audio manager that updates all audio instances.
 * @version 0.1
 * @date 22/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "audio_manager.hpp"
#include "audio_facade.hpp"
#include "core_constants.hpp"
#include <future>
#include <iostream>

AudioManager::AudioManager()
{
    audioInstances = std::vector<std::shared_ptr<audio_instance>>();
    // Time
    auto current = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::steady_clock::now().time_since_epoch());
    lastTimeStamp = current.count();
}

void AudioManager::Cleanup()
{
    for (auto it = audioInstances.rbegin(); it != audioInstances.rend();)
    {
        const auto &instance = *it;

        // We assume that the instance is done playing when it
        // has played before, and we are the only owner
        if (instance->GetState() == SoundPlayState::Stopped && instance.use_count() == 1)
        {
            it = decltype(it)(audioInstances.erase(std::next(it).base()));
        }
        else
        {
            ++it;
        }
    }
}

std::weak_ptr<audio_instance> AudioManager::CreateSound(audio_file_path filePath)
{
    auto audioInstance = AudioFacade::CreateAudioInstance(filePath);
    audioInstances.push_back(audioInstance);
    return audioInstance;
}

void AudioManager::DestroySound(std::weak_ptr<audio_instance> sound)
{
    audioInstances.erase(std::remove_if(audioInstances.begin(), audioInstances.end(),
                                        [&sound](const auto &ptr) { return ptr == sound.lock(); }),
                         audioInstances.end());
}

void AudioManager::PlayOneShot(audio_file_path filePath, float vol)
{
    auto audioInstance = AudioFacade::CreateAudioInstance(filePath);
    audioInstance->SetVolume(vol);
    audioInstance->Play();

    audioInstances.push_back(audioInstance);
}

void AudioManager::Update()
{
    auto current = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::steady_clock::now().time_since_epoch());

    auto expired = current.count() - lastTimeStamp;

    // Cleanup
    if (expired >= CoreConstants::Audio::AUDIO_CLEANUP_TIMEOUT)
    {
        Cleanup();
        lastTimeStamp = current.count();
    }
}

void AudioManager::ForceClean() { audioInstances.clear(); }
