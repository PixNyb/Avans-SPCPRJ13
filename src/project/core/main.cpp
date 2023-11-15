/**
 * @file main.cpp
 * @author Robin Pijnappels
 * @brief Entry point for the Engine, initializing and running the game loop.
 * @version 0.1
 * @date 07/11/2023
 *
 * This file contains the main entry point of the Engine. It creates an instance of the GameLoop class
 * and starts the game loop. The GameLoop class is responsible for managing the core game processes,
 * including initializing the game state, handling input, updating game logic, and rendering frames.
 * The 'run' method of the GameLoop kicks off the continuous loop that drives the game.
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "game_loop.hpp"

int main(int argc, char *argv[])
{
    GameLoop gameLoop;

    gameLoop.run(); // Start de game loop.

    return 0;
}