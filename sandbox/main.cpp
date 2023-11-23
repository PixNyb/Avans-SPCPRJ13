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

#include "audio_source.hpp"
#include <iostream>

// Change this to whatever wav you like to test
// Download a sample file:
// https://file-examples.com/wp-content/storage/2017/11/file_example_WAV_1MG.wav
const std::string test = R"(C:\Users\melvi\Downloads\file_example_WAV_1MG.wav)";

int main(int argc, char *argv[])
{
    std::cout << "Sandbox" << std::endl;

    AudioSource audioSource = AudioSource(test);
    audioSource.Play();

    int ticks = 0;
    float pitch = 1.0f;

    while (ticks < 10)
    {
        ticks++;
        _sleep(1000);
        audioSource.SetPitch(pitch += 0.01f);
        if (ticks == 4)
            audioSource.Pause();

        if (ticks == 6)
            audioSource.Play();

        std::cout << "Sec: " << ticks << std::endl;
    }

    return 1;
}