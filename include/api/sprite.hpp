/**
 * @file sprite.hpp
 * @author Robin Pijnappels
 * @version 0.1
 * @date 2023-11-12
 *
 * @brief Defines the Sprite class for handling sprite rendering in the game engine.
 * The Sprite class extends the BehaviourScript and represents a graphical sprite in a game.
 * It includes properties such as the sprite image, color, flipping states, and rendering order,
 * which are crucial for rendering and managing sprite-based game objects.
 * This class is essential for adding visual elements to game objects.
 *
 * @copyright Copyright (c) 2023
 */

#ifndef AVANS_SPCPRJ13_SPRITE_H
#define AVANS_SPCPRJ13_SPRITE_H

#include "behaviour_script.hpp"
#include "color.hpp"
#include <string>

/**
 * @class Sprite
 * @brief Represents a graphical sprite in the game engine.
 *
 * Sprite extends BehaviourScript to handle sprite-based graphics. It manages the visual
 * representation of game objects, including image, color, orientation, and rendering order.
 */
class Sprite : public BehaviourScript
{

  private:
    std::string sprite; ///< The sprite image file path or identifier.
    Color color;        ///< The color tint applied to the sprite.
    bool flipX;         ///< Flag to flip the sprite horizontally.
    bool flipY;         ///< Flag to flip the sprite vertically.
    int sortingLayer;   ///< The sorting layer for rendering order.
    int orderInLayer;   ///< The specific order within the sorting layer.
    int frameWidth, frameHeight; ///< For the spritesheet

  public:
    /**
     * @brief Constructs a new Sprite object with default settings.
     */
    Sprite();

    /**
     * @brief Constructs a new Sprite object with the specified sprite image.
     * @param sprite The sprite image file path or identifier.
     */
    [[nodiscard]] const std::string& GetSprite() const { return sprite; }

    /**
     * @brief Sets the sprite image for this Sprite object.
     * @param spriteImage The sprite image file path or identifier.
     */
    void SetSprite(const std::string& spriteImage) {
        sprite = spriteImage;
    }

    [[nodiscard]] int GetFrameWidth() const { return frameWidth; }
    [[nodiscard]] int GetFrameHeight() const { return frameHeight; }
};

#endif // AVANS_SPCPRJ13_SPRITE_H
