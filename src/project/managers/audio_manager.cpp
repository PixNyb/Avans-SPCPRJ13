/**
 * @file audio_manager.cpp
 * @author "Melvin van Bree"
 * @brief TODO
 * @version 0.1
 * @date 22/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "audio_manager.hpp"

void AudioManager::SetVolume(float volume) { this->volume = volume; }

float AudioManager::GetVolume() const { return volume; }

std::weak_ptr<audio_source> AudioManager::CreateSound(audio_file_path filePath)
{
    return std::weak_ptr<audio_source>();
}

void AudioManager::PlayOneShot(audio_file_path filePath, float volume) {}
