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
#include <memory>
#include <string>

/**
 * @brief A facade for the audio library.
 * Creates an instance of the audio instance.
 */
class AudioFacade
{
  public:
    /**
     * @brief Creates an instance of the audio instance.
     * @param filePath The path to the audio file.
     * @return A unique pointer to the audio instance.
     */
    static std::unique_ptr<ISound> CreateAudioInstance(const std::string &filePath);
};

#endif // DEFUNBOBENGINE_SRC_FACADES_AUDIO_FACADE_HPP
