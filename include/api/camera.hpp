/**
 * @file camera.hpp
 * @author Robin Pijnappels
 * @version 0.1
 * @date 2023-11-12
 *
 * @brief Defines the Camera class for managing camera views in a game engine.
 * The Camera class handles the rendering perspective in the game, including aspects like
 * background color, aspect ratio, and other view properties. It is essential for controlling
 * how scenes are visualized and interacted with in the game environment.
 *
 * @copyright Copyright (c) 2023
 */

#ifndef AVANS_SPCPRJ13_CAMERA_H
#define AVANS_SPCPRJ13_CAMERA_H

#include "color.hpp"
#include "game_object.hpp"

/**
 * @class Camera
 * @brief Represents a camera view in the game.
 *
 * Camera is a component that defines the view of the game world. It is responsible for defining
 * the area to be rendered, including the background color and aspect ratio.
 */
class Camera : public GameObject
{
  private:
    Color backgroundColor;
    double aspectWidth;
    double aspectHeight;

  public:
    Camera();

    // Setters and Getters for Background Color
    void SetBackgroundColor(const Color &color);
    Color GetBackgroundColor() const;

    // Setters and Getters for Aspect Width
    void SetAspectWidth(int width);
    int GetAspectWidth() const;

    // Setters and Getters for Aspect Height
    void SetAspectHeight(int height);
    int GetAspectHeight() const;

    // Function to retrieve the aspect ratio
    float GetAspectRatio() const;
};

#endif // AVANS_SPCPRJ13_CAMERA_H
