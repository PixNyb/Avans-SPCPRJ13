/// @file

#ifndef AVANS_SPCPRJ13_UIOBJECT_H
#define AVANS_SPCPRJ13_UIOBJECT_H

#include "game_object.hpp"

class UIObject : GameObject {
private:
  float width, height;

public:
  UIObject();
  // Getters, Setters, and other public member functions ...
    void SetWidth(int w);
    int GetWidth() const;

    void SetHeight(int h);
    int GetHeight() const;
};

#endif // AVANS_SPCPRJ13_UIOBJECT_H
