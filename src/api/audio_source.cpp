/**
 * @file audio_source.cpp
 * @author Robin Pijnappels
 * @brief This file contains the AudioSource class implementation.
 * @version 0.1
 * @date 2023-11-08
 *
 * Copyright Copyright (c) 2023
 *
 */

#include "audio_source.hpp"
#include "audio_facade.hpp"
#include <algorithm>
#include <utility>

AudioSource::AudioSource(std::string audioClipPath, bool playOnAwake, bool loop, double volume)
    : audioClip(std::move(audioClipPath)), playOnAwake(playOnAwake)
{
    sound = AudioFacade::CreateAudioInstance(audioClip);
    sound->SetLoop(loop);
    sound->SetVolume(static_cast<float>(std::clamp(volume * 100.0, 0.0, 100.0)));
    if (playOnAwake)
        sound->Play();
}

AudioSource::AudioSource(const AudioSource &other) : audioClip(other.audioClip)
{
    sound = AudioFacade::CreateAudioInstance(audioClip);
    sound->SetLoop(other.sound->GetLoop());
    sound->SetVolume(other.sound->GetVolume());
    sound->SetPitch(other.sound->GetPitch());
    playOnAwake = other.playOnAwake;
    if (playOnAwake)
        sound->Play();
}

void AudioSource::Play(bool looping)
{
    sound->SetLoop(looping);
    sound->Play();
}
void AudioSource::Stop() { sound->Stop(); }
void AudioSource::SetPitch(float pitch) { sound->SetPitch(pitch); }
void AudioSource::Pause() { sound->Pause(); }

void AudioSource::SetActive(bool isActivate)
{
    bool previousActive = IsActive();
    // Relay to base class
    Component::SetActive(isActivate);

    if (!isActivate)
    {
        Stop();
        return;
    }

    // If the component was inactive and is now active and play on awake, play the audio
    if (!previousActive && playOnAwake)
        Play(sound->GetLoop());
}

std::shared_ptr<Component> AudioSource::Clone(std::weak_ptr<GameObject> parent)
{
    return std::make_shared<AudioSource>(*this);
}
