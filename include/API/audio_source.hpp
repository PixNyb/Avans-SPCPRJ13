//
// Created by Robin on 30-10-2023.
//

#ifndef AVANS_SPCPRJ13_AUDIOSOURCE_H
#define AVANS_SPCPRJ13_AUDIOSOURCE_H

#include <string>

class AudioSource {
private:
    std::string audioClip;
    bool playOnAwake;
    bool loop;

public:
    AudioSource();
    // Getters, Setters, and other public member functions ...
};

#endif //AVANS_SPCPRJ13_AUDIOSOURCE_H
