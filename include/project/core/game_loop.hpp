//
// Created by Robin Pijnappels on 08/11/2023.
//

#ifndef DEFUNBOBENGINE_GAME_LOOP_HPP
#define DEFUNBOBENGINE_GAME_LOOP_HPP

class GameLoop {
public:
    GameLoop();
    ~GameLoop();

    void run();
    void update();
    void render();
    bool isRunning() const;

private:
    bool running;
};

#endif //DEFUNBOBENGINE_GAME_LOOP_HPP
