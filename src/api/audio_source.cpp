/// @file

#include "audio_source.hpp"

AudioSource::AudioSource() : audioClip(""), playOnAwake(true), loop(false), volume(1.0f)
{
    // Default constructor initialization
}

AudioSource::AudioSource(const std::string &audioClipPath)
    : audioClip(audioClipPath), playOnAwake(true), loop(false), volume(1.0f)
{
    // Constructor with audio clip path initialization
}

AudioSource::AudioSource(const AudioSource &other)
    : audioClip(other.audioClip), playOnAwake(other.playOnAwake), loop(other.loop),
      volume(other.volume)
{
}

void AudioSource::Play(bool looping) {}
void AudioSource::Stop() {}
void AudioSource::SetPitch(float pitch) {}
void AudioSource::Pause() {}
