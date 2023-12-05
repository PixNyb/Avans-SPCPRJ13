/**
 * @file texture.hpp
 * @author Robin Pijnappels
 * @brief This file contains the Texture class implementation.
 * @version 0.1
 * @date 2023-11-18
 *
 * The Texture class is responsible for managing SDL_Texture resources,
 * providing an interface for loading and retrieving an SDL_Texture from a file path.
 * It ensures that the loaded texture is properly released when the object is destroyed.
 */

#include "texture.hpp"

Texture::Texture(const std::string& filePath) : filePath(filePath) {}

Texture::~Texture() {}

const std::string& Texture::getFilePath() const {
    return filePath;
}
