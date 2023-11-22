/**
 * @file box_collider.hpp
 * @author Robin Pijnappels
 * @version 0.1
 * @date 2023-11-12
 *
 * @brief Defines the BoxCollider class for representing rectangular collision areas.
 * BoxCollider is a subclass of Collider, specialized for handling collisions in rectangular areas.
 * It provides functionalities to get and set the dimensions (width and height) of the collider.
 * This class is useful in physics simulations and collision detection in a game engine.
 *
 * @copyright Copyright (c) 2023
 */

#ifndef AVANS_SPCPRJ13_BOXCOLLIDER_H
#define AVANS_SPCPRJ13_BOXCOLLIDER_H

#include "collider.hpp"

/**
 * @class BoxCollider
 * @brief Represents a rectangular collision area.
 *
 * BoxCollider is a component used for collision detection and physics simulation.
 * It defines a rectangular area that can interact with other colliders in the game world.
 */
class BoxCollider : public Collider
{
  public:
    /**
     * @brief The collider's width
     * @return The current width
     */
    double Width() const { return width; }

    /**
     * @brief The collider's width
     * @param newWidth The desired width
     */
    void Width(double newWidth) { width = newWidth; }

    /**
     * @brief The collider's height
     * @return The current height
     */
    double Height() const { return height; }

    /**
     * @brief The collider's height
     * @param newHeight The desired height
     */
    void Height(double newHeight) { height = newHeight; }

  private:
    double width;
    double height;
};

#endif // AVANS_SPCPRJ13_BOXCOLLIDER_H
