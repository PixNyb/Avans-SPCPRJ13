/// @file

#ifndef AVANS_SPCPRJ13_SPRITE_H
#define AVANS_SPCPRJ13_SPRITE_H

#include "behaviour_script.hpp"
#include "color.hpp"
#include <string>

class Sprite : public BehaviourScript
{
  private:
    std::string sprite;
    Color color;
    bool flipX;
    bool flipY;
    int sortingLayer;
    int orderInLayer;

  public:
    Sprite();
    // Getters, Setters, and other public member functions ...
};

#endif // AVANS_SPCPRJ13_SPRITE_H
