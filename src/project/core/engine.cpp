/**
 * @file engine.cpp
 * @author "Melvin van Bree"
 * @brief TODO
 * @version 0.1
 * @date 10/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "engine.hpp"

Engine* Engine::instancePtr = nullptr;

Engine::Engine() {
    publicContainer.registerInstance<SceneManager>(std::make_shared<SceneManager>());
}
