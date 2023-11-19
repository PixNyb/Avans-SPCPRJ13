/**
 * @file texture.hpp
 * @author Robin Pijnappels
 * @brief This file contains the Texture class definition.
 * @version 0.1
 * @date 2023-11-18
 *
 * The Texture class is responsible for managing SDL_Texture resources,
 * providing an interface for loading and retrieving an SDL_Texture from a file path.
 * It ensures that the loaded texture is properly released when the object is destroyed.
 */

#ifndef DEFUNBOBENGINE_TEXTURE_HPP
#define DEFUNBOBENGINE_TEXTURE_HPP

#include <string>

/**
 * @class Texture
 * @brief Manages an SDL_Texture loaded from a file.
 *
 * Texture encapsulates an SDL_Texture object, handling its creation from a file
 * and destruction. It provides a method to access the underlying SDL_Texture pointer
 */
class Texture {
public:
    /**
     * @brief Constructs a Texture by loading from the specified file path.
     * @param filePath The path to the image file to load as an SDL_Texture.
     */
    Texture(const std::string& filePath);

    /**
     * @brief Destroys the Texture, freeing the managed SDL_Texture resource.
     */
    ~Texture();

    /**
     * @brief Retrieves the underlying SDL_Texture pointer.
     * @return SDL_Texture* A pointer to the managed SDL_Texture.
     */
    const std::string& getFilePath() const;

private:
    std::string filePath; ///< The path to the image file to load as an SDL_Texture.
};

#endif //DEFUNBOBENGINE_TEXTURE_HPP
