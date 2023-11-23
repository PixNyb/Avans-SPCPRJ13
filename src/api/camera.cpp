/**
 * @file camera.cpp
 * @author Robin Pijnappels
 * @brief This file contains the Camera class implementation.
 * @version 0.1
 * @date 2023-11-08
 *
 * Copyright Copyright (c) 2023
 *
 */


#include "camera.hpp"

Camera::Camera()
    : backgroundColor(0, 0, 0, 1), // default to black color
      aspectWidth(16), aspectHeight(9)
{
    // Default constructor initialization
}

void Camera::SetBackgroundColor(const Color &color) { backgroundColor = color; }

Color Camera::GetBackgroundColor() const { return backgroundColor; }

void Camera::SetAspectWidth(int width) { aspectWidth = width; }

int Camera::GetAspectWidth() const { return aspectWidth; }

void Camera::SetAspectHeight(int height) { aspectHeight = height; }

int Camera::GetAspectHeight() const { return aspectHeight; }

float Camera::GetAspectRatio() const
{
    if (aspectHeight != 0)
    {
        return static_cast<float>(aspectWidth) / aspectHeight;
    }
    return 0.0f;
}

// ... additional methods if required
