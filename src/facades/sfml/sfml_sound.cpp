/**
 * @file sfml_sound.cpp
 * @author "Melvin van Bree"
 * @brief SFML implementation of the sound class.
 * @version 0.1
 * @date 22/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "sfml_sound.hpp"
#include "core_constants.hpp"

int SFMLSound::instanceCount = 0;

SFMLSound::SFMLSound(const std::string &filePath)
{
    // The destructor will decrease it even if an error is thrown.
    instanceCount++;

    if (instanceCount + 1 >= CoreConstants::Audio::AUDIO_MAX_INSTANCE_COUNT)
        throw std::runtime_error("Maximum amount of sound instances reached.");

    buffer.loadFromFile(filePath);

    if (!buffer.loadFromFile(filePath))
    {
        // TODO: Do some logging instead of throwing error?
        throw std::runtime_error("Could not load audio file: " + filePath);
    }

    sound.setBuffer(buffer);
}

SFMLSound::~SFMLSound()
{
    sound.stop();
    instanceCount--;
}

// Volume
void SFMLSound::SetVolume(float volume) { sound.setVolume(volume); }
float SFMLSound::GetVolume() const { return sound.getVolume(); }

// Pitch
void SFMLSound::SetPitch(float pitch) { sound.setPitch(pitch); }
float SFMLSound::GetPitch() const { return sound.getPitch(); }

// Loop
void SFMLSound::SetLoop(bool loop) { sound.setLoop(loop); }
bool SFMLSound::GetLoop() const { return sound.getLoop(); }

void SFMLSound::Play() { sound.play(); }
void SFMLSound::Stop() { sound.stop(); }
void SFMLSound::Pause() { sound.pause(); }
void SFMLSound::Resume() { sound.play(); }

SoundPlayState SFMLSound::GetState() const
{
    switch (sound.getStatus())
    {
    case sf::SoundSource::Status::Playing:
        return SoundPlayState::Playing;
    case sf::SoundSource::Status::Paused:
        return SoundPlayState::Paused;
    case sf::SoundSource::Status::Stopped:
        return SoundPlayState::Stopped;
    }

    return SoundPlayState::Stopped;
}
