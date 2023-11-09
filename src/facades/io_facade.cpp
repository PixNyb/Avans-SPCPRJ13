/**
 * @file io_facade.cpp
 * @author Robin Pijnappels
 * @brief This file contains the IOFacade interface definition.
 * @version 0.1
 * @date 09/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "io_facade.hpp"

void IOFacade::createWindow(const char* title, int width, int height) {
    sdlWindow.create(title, width, height);
}