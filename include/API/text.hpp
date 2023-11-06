/// @file

#ifndef AVANS_SPCPRJ13_TEXT_H
#define AVANS_SPCPRJ13_TEXT_H

#include "ui_object.hpp"
#include <string>

class Text : public UIObject {
private:
  std::string text;
  int fontSize;
  std::string alignment;
  // Add color, etc.

public:
  Text();
  // Getters, Setters, and other public member functions ...
};

#endif // AVANS_SPCPRJ13_TEXT_H
