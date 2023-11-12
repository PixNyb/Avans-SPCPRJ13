/// @file

#ifndef AVANS_SPCPRJ13_UIOBJECT_H
#define AVANS_SPCPRJ13_UIOBJECT_H

#include "game_object.hpp"
#include "point.hpp"

class UIObject : public GameObject
{
  private:
    float width, height;

  public:
    UIObject();
    UIObject(const std::string &name, const std::string &tag, int layer, float width, float height);

    // Getters, Setters, and other public member functions ...
    void SetWidth(float w);
    [[nodiscard]] float GetWidth() const;

    void SetHeight(float h);
    [[nodiscard]] float GetHeight() const;
};

#endif // AVANS_SPCPRJ13_UIOBJECT_H
