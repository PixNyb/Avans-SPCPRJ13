/// @file

#include "audio_source.hpp"

AudioSource::AudioSource()
    : audioClip(""), playOnAwake(true), loop(false), volume(1.0f) {
  // Default constructor initialization
}

AudioSource::AudioSource(const std::string &audioClipPath)
    : audioClip(audioClipPath), playOnAwake(true), loop(false), volume(1.0f) {
  // Constructor with audio clip path initialization
}

void AudioSource::Play(bool loop) {}
void AudioSource::Stop() {}
void AudioSource::SetPitch(float pitch) {}
void AudioSource::Pause() {}
