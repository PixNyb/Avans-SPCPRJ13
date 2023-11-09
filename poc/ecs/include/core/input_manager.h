#pragma once

#include "SDL_scancode.h"
#include <algorithm>

namespace InputManager
{
// Function declarations
void poll();
bool wasKeyPressed(SDL_Scancode key);
bool wasKeyReleased(SDL_Scancode key);
bool wasMouseButtonPressed(Uint8 button);
bool wasMouseButtonReleased(Uint8 button);
bool hasQuit();
} // namespace InputManager