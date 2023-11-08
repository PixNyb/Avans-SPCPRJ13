/// @file

#ifndef AVANS_SPCPRJ13_TEXT_H
#define AVANS_SPCPRJ13_TEXT_H

#include "color.hpp"
#include "ui_object.hpp"
#include <string>

/**
 * @brief Enumeration for different text alignments.
 */
enum class Alignment { left, center, right };

/**
 * @brief Class representing a piece of text which can be rendered.
 */
class Text {
private:
    std::string text;      ///< The text string.
    int fontSize;          ///< The font size of the text.
    std::string alignment; ///< The alignment of the text.
    Color textColor;       ///< The color of the text.

public:
    /**
     * @brief Default constructor for Text.
     *
     * Initializes a new Text with default values.
     */
    Text();

    /**
     * @brief Set the text string.
     *
     * @param str The new text string.
     */
    void SetText(const std::string &str);

    /**
     * @brief Get the text string.
     *
     * @return The text string.
     */
    std::string GetText() const;

    /**
     * @brief Set the font size of the text.
     *
     * @param size The new font size.
     */
    void SetFontSize(int size);

    /**
     * @brief Get the font size of the text.
     *
     * @return The font size of the text.
     */
    int GetFontSize() const;

    /**
     * @brief Set the alignment of the text.
     *
     * @param align The new alignment.
     */
    void SetAlignment(const std::string &align);

    /**
     * @brief Get the alignment of the text.
     *
     * @return The alignment of the text.
     */
    std::string GetAlignment() const;

    /**
     * @brief Set the color of the text.
     *
     * @param color The new text color.
     */
    void SetTextColor(const Color &color);

    /**
     * @brief Get the color of the text.
     *
     * @return The color of the text.
     */
    Color GetTextColor() const;
};

#endif // AVANS_SPCPRJ13_TEXT_H