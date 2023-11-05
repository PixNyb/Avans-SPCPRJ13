//
// Created by Robin on 30-10-2023.
//

#ifndef AVANS_SPCPRJ13_BUTTON_H
#define AVANS_SPCPRJ13_BUTTON_H

#include "ui_object.hpp"

class Button : public UIObject
{
private:
    bool interactable;
    // ... (other members)

public:
    Button();
    void onClick();
    // Getters, Setters, and other public member functions ...
};

#endif // AVANS_SPCPRJ13_BUTTON_H
