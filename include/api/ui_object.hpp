/**
 * @file ui_object.hpp
 * @author Robin Pijnappels
 * @version 0.1
 * @date 2023-11-12
 *
 * @brief Defines the UIObject class for representing user interface elements in the game engine.
 * UIObject extends the GameObject class to create interactive and visual components for the user interface.
 * It includes basic properties like width and height, essential for layout and rendering of UI elements.
 * This class forms the base for more complex UI components such as buttons, sliders, and text fields.
 *
 * @copyright Copyright (c) 2023
 */


#ifndef AVANS_SPCPRJ13_UIOBJECT_H
#define AVANS_SPCPRJ13_UIOBJECT_H

#include "game_object.hpp"
#include "point.hpp"

/**
 * @class UIObject
 * @brief Represents a user interface object in the game engine.
 *
 * UIObject is a specialized GameObject that serves as a base for UI elements.
 * It includes properties for size and position, along with functionalities specific to UI components.
 */
class UIObject : public GameObject {
private:
    float width;  ///< The width of the UI object.
    float height; ///< The height of the UI object.
public:
    /**
     * @brief Default constructor for UIObject.
     *
     * Initializes a new UIObject with default size.
     */
  UIObject();

    /**
     * @brief Constructor for UIObject with specific attributes.
     *
     * Initializes a new UIObject with specified name, tag, layer, width, and height.
     * @param name The name of the UI object.
     * @param tag The tag associated with the UI object.
     * @param layer The rendering layer of the UI object.
     * @param width The width of the UI object.
     * @param height The height of the UI object.
     */
  UIObject(const std::string &name, const std::string &tag, int layer, float width, float height);

    /**
     * @brief Sets the width of the UI object.
     * @param w The new width.
     */
    void SetWidth(float w);

    /**
     * @brief Gets the width of the UI object.
     * @return The width of the UI object.
     */
    [[nodiscard]] float GetWidth() const;

    /**
     * @brief Sets the height of the UI object.
     * @param h The new height.
     */
    void SetHeight(float h);

    /**
     * @brief Gets the height of the UI object.
     * @return The height of the UI object.
     */
    [[nodiscard]] float GetHeight() const;
};

#endif // AVANS_SPCPRJ13_UIOBJECT_H
