//
// Created by Robin on 30-10-2023.
//

#ifndef AVANS_SPCPRJ13_CAMERA_H
#define AVANS_SPCPRJ13_CAMERA_H


class Camera {
private:
    // color backgroundColor; Uncomment and define 'color'
    float aspectWidth, aspectHeight;

public:
    Camera();

    // Setters and Getters for Background Color
    void SetBackgroundColor(const Color& color);
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


#endif //AVANS_SPCPRJ13_CAMERA_H
