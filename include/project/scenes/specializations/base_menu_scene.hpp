/**
 * @file base_menu_scene.hpp
 * @author melvi
 * @brief TODO
 * @version 0.1
 * @date 08/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_BASE_MENU_SCENE_HPP
#define DEFUNBOBENGINE_BASE_MENU_SCENE_HPP

#include "base_scene.hpp"
#include "core_constants.hpp"
#include "point.hpp"
#include "color.hpp"
#include "button.hpp"
#include "text.hpp"

/**
 * @brief Provides specializations for menu scenes
 *
 */
class BaseMenuScene : public BaseScene
{
public:
    BaseMenuScene();
    ~BaseMenuScene();

    /**
    * @brief Add a text to the scene
    * @param text The text to be added
    * @param position The positions of the text on the screen
    * @param size Size of the text (default: 12)
    * @param font Font of the text (default: Sans.ttf)
    */
    void AddText(const std::string &text, const Point &position, const int size = CoreConstants::Text::DEFAULT_SIZE, const std::string &font = CoreConstants::Text::DEFAULT_FONT);

    // TODO: Add bounds to button (2D Vector)
    /**
    * @brief Add a button to the scene
    * @param text The text to be added
    * @param position The positions of the button on the screen
    * @param bgColor The background color of the button (default: black)
    * @param textColor The text color of the button (default: white)
    * @param textSize The size of the text (default: 12)
    * @param font The font of the text (default: Sans.ttf)
    * @return A reference to the button that was added (Required for actions)
    */
    std::shared_ptr<Button> AddButton(const std::string &text, const Point &position, const Color &bgColor = Color::black(), const Color &textColor = Color::white(), const int textSize = CoreConstants::Text::DEFAULT_SIZE, const std::string &font = CoreConstants::Text::DEFAULT_FONT);

    /**
     * @brief Add a button to the scene
     * @param text The text to be added
     * @param position The positions of the button on the screen
     * @param buttonBackgroundImagePath The path to the image that will be used as the background of the button
     * @param textSize The size of the text (default: 12)
     * @param font The font of the text (default: Sans.ttf)
     * @return A reference to the button that was added (Required for actions)
     */
    std::shared_ptr<Button> AddButton(const std::string &text, const Point &position, const std::string& buttonBackgroundImagePath, const int textSize = CoreConstants::Text::DEFAULT_SIZE, const std::string &font = CoreConstants::Text::DEFAULT_FONT);
};

#endif // DEFUNBOBENGINE_BASE_MENU_SCENE_HPP
