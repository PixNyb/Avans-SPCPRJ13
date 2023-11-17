/**
 * @file CoreConstants.hpp
 * @author melvin van bree
 * @brief Meant to provide a way to store constants that are used in the core of the engine.
 * @version 0.1
 * @date 08/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_CORECONSTANTS_HPP
#define DEFUNBOBENGINE_CORECONSTANTS_HPP

#include "color.hpp"
#include "text.hpp"
#include <string>

namespace CoreConstants {
    namespace Text {
        const int DEFAULT_SIZE = 12;
        // TODO: Implement better way to handle this
        const std::string DEFAULT_FONT_PATH = "../resources/fonts/OpenSans-Normal.ttf";
        const Color DEFAULT_COLOR = Color::red();
        const Alignment DEFAULT_ALIGNMENT = Alignment::left;
    }
    namespace Renderer{
        const Color DEFAULT_RENDER_COLOR = Color::white();
    }
    namespace Engine {
        const int DEFAULT_FPS = 60;
    }
    namespace Debug {
        const bool EnableDebug = true;
        const bool DrawColliders = true;
    }
}

#endif // DEFUNBOBENGINE_CORECONSTANTS_HPP
