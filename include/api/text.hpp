/// @file

#ifndef AVANS_SPCPRJ13_TEXT_H
#define AVANS_SPCPRJ13_TEXT_H

#include "ui_object.hpp"
#include "color.hpp"
#include <string>

/**
 * @brief Enumeration for different text alignments.
 */
enum class Alignment {
    left,
    center,
    right
};

/**
 * @brief Class representing a piece of text which can be rendered.
 */
class Text : public UIObject {
private:
    std::string text;
    std::string font;
    int size;
    Alignment alignment;
    Color color;
};

#endif // AVANS_SPCPRJ13_TEXT_H
