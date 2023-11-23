/**
 * @file audio_facade.hpp
 * @author "Melvin van Bree"
 * @brief A facade for the audio library.
 * @version 0.1
 * @date 22/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_SRC_FACADES_AUDIO_FACADE_HPP
#define DEFUNBOBENGINE_SRC_FACADES_AUDIO_FACADE_HPP

#include "i_sound.hpp"
#include "sfml_sound.hpp"
#include <memory>

class AudioFacade
{
  public:
    static std::unique_ptr<ISound> CreateAudioInstance(const std::string &filePath);
};

#endif // DEFUNBOBENGINE_SRC_FACADES_AUDIO_FACADE_HPP
