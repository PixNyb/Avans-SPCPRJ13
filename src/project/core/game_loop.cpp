/**
 * @file game_loop.cpp
 * @author Robin Pijnappels (rm.pijnappels@student.avans.nl)
 * @brief This file contains the GameLoop class implementation.
 * @version 0.1
 * @date 2023-11-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "game_loop.hpp"
#include "graphics_facade.hpp"
#include "engine.hpp"
#include <thread>

GameLoop::GameLoop() : running(true) {}

GameLoop::~GameLoop() {}

void GameLoop::run()
{
    while (isRunning())
    {
        update();
        render();
        // Hier kun je ook input handling en andere per-frame logica toevoegen.
    }
}

void GameLoop::update()
{
    // Update game state.
}

void GameLoop::render()
{
    // Render the game.
}

bool GameLoop::isRunning() const { return running; }