/**
 * @file main.cpp
 * @author "Melvin van Bree"
 * @brief Used as a sandbox to test code without have to open up a game.
 * @version 0.1
 * @date 10/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "audio_manager.hpp"
#include <iostream>

const std::string test = R"(C:\Users\melvi\Downloads\file_example_WAV_1MG.wav)";

int main(int argc, char *argv[])
{
    std::cout << "Sandbox" << std::endl;

    auto audioManager = AudioManager();

    //    audioManager.PlayOneShot(test);

    // Make sure it goes out of scope
    {
        auto instance = audioManager.CreateSound(test);
        auto audio = instance.lock();
        audio->Play();

        float pitch = 1.0f;

        while (audio->GetState() != SoundPlayState::Stopped)
        {
            audioManager.Update();
            _sleep(100);
            pitch += 0.01f;
            audio->SetPitch(pitch);
        }
    }

    int tick = 0;
    while (tick < 10)
    {
        audioManager.Update();
        _sleep(100);
        tick++;
    }

    std::cout << "Done" << std::endl;

    return 1;
}