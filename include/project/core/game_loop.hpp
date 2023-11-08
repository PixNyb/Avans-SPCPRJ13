/**
 * @file game_loop.hpp
 * @author Robin Pijnappels (rm.pijnappels@student.avans.nl)
 * @brief This file contains the GameLoop class definition.
 * @version 0.1
 * @date 2023-11-08
 *
 * The GameLoop class manages the main loop of the game engine. It controls the game's
 * update and rendering cycles and maintains a flag to determine if the game is currently running.
 * This class is the central part of the game's runtime, calling the update and render methods
 * on a consistent time interval.
 *
 * @see update()
 * @see render()
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_GAME_LOOP_HPP
#define DEFUNBOBENGINE_GAME_LOOP_HPP

/**
 * @class GameLoop
 * @brief Manages the main execution loop of the game engine.
 *
 * GameLoop is responsible for controlling the flow of the game's execution.
 * It provides mechanisms to run the update and render cycles at a consistent
 * timing and to check whether the game is currently running.
 */
class GameLoop {
public:
    /**
     * @brief Construct a new Game Loop object.
     *
     * Initializes the game loop control flag to false, indicating the loop is not running initially.
     */
    GameLoop();

    /**
     * @brief Destroy the Game Loop object.
     *
     * Ensures that any resources used by the game loop are properly released.
     */
    ~GameLoop();

    /**
     * @brief Starts the game loop.
     *
     * Begins the main execution cycle, including update and render operations.
     * This loop continues until the running flag is set to false.
     */
    void run();

    /**
     * @brief Updates the game state.
     *
     * This method should be called every frame to update the game's internal state,
     * including game object positions, physics calculations, and other logic.
     */
    void update();

    /**
     * @brief Renders the game state.
     *
     * This method should be called every frame to render the game state to the screen.
     */
    void render();

    /**
     * @brief Checks if the game loop is currently running.
     *
     * @return true if the game loop is running, false otherwise.
     */
    bool isRunning() const;

private:
    bool running; ///< Flag indicating whether the game loop is currently running.
};

#endif //DEFUNBOBENGINE_GAME_LOOP_HPP
