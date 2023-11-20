/**
 * @file text.hpp
 * @author Robin Pijnappels
 * @version 0.1
 * @date 2023-11-12
 *
 * @brief Defines the Text class for handling text rendering in UI elements within the game engine.
 * The Text class extends UIObject to represent text elements in the user interface.
 * It provides properties such as text content, font size, alignment, and color, essential for
 * displaying and styling text in various UI scenarios. The class plays a crucial role in creating
 * interactive and informative user interfaces.
 *
 * @copyright Copyright (c) 2023
 */

#ifndef AVANS_SPCPRJ13_TEXT_H
#define AVANS_SPCPRJ13_TEXT_H

#include "color.hpp"
#include "ui_object.hpp"
#include <string>

/**
 * @enum Alignment
 * @brief Enumeration for different text alignments.
 *
 * Represents the possible alignments for text, such as left, center, and right.
 */
enum class Alignment { left, center, right };

/**
 * @class Text
 * @brief Represents a piece of text in the user interface.
 * @warning If you don't set width and height properly, text is not going to be shown.
 * @note Height is boxed, width is wrapped. So if the text exceeds the width, it will be wrapped.
 * If it exceeds the height, it will be boxed, so overflow will be invisible.
 *
 * Text is a UIObject that manages the display of text, including its content, appearance,
 * and position within the user interface.
 */
class Text : public UIObject {
private:
    std::string text;      ///< The text string.
    int fontSize;          ///< The font size of the text.
    // TODO: Implement alignment
    Alignment alignment; ///< The alignment of the text.
    Color textColor;       ///< The color of the text.

public:
    /**
     * @brief Default constructor for Text.
     *
     * Initializes a new Text with default values.
     */
    Text();

    /**
     * @brief Default for Text.
     * @param name The name of the text.
     * @param tag The tag of the text.
     * @param layer The layer of the text.
     * @param width The width of the text.
     * @param height The height of the text.
     */
    Text(const std::string &name, const std::string &tag, int layer, float width, float height);

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
    void SetAlignment(const Alignment &align);

    /**
     * @brief Get the alignment of the text.
     *
     * @return The alignment of the text.
     */
    Alignment GetAlignment() const;

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