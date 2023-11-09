//
// Created by Robin Pijnappels on 07/11/2023.
//

#include "game_loop.hpp"

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