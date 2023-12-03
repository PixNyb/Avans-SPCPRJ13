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

  public:
    /**
     * @brief Constructs a new Sprite object with default settings.
     */
    Sprite();

    /**
     * @brief Copy constructor for Sprite.
     *
     * Initializes a new Sprite with the values of an existing one.
     * @param other The Sprite to copy values from.
     */
    Sprite(const Sprite &other);

    /**
     * @brief Make a clone of the component.
     * @param parent The parent GameObject.
     * @return The cloned component.
     */
    std::shared_ptr<Component> Clone(std::weak_ptr<GameObject> parent) override;

    // Getters, Setters, and other public member functions ...
};

#endif // AVANS_SPCPRJ13_SPRITE_H
