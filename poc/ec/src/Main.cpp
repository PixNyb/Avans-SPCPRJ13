#include "Component.hpp"
#include "Entity.hpp"
#include "Game.hpp"

int main(int argc, char *argv[])
{
    Game game;
    SDL_Renderer &renderer = game.getRenderer();

    Entity *player = new Entity();
    player->addComponent(new PositionComponent(*player, 0, 0));
    player->addComponent(new MovementComponent(*player));
    player->addComponent(new InputComponent(*player));
    player->addComponent(new RenderComponent(*player, 32, 32, {0, 0, 255, 255}, renderer));

    Entity *enemy = new Entity();
    enemy->addComponent(new PositionComponent(*enemy, 100, 100));
    enemy->addComponent(new MovementComponent(*enemy));
    enemy->addComponent(new FollowComponent(*enemy, *player));
    enemy->addComponent(new RenderComponent(*enemy, 16, 32, {255, 0, 0, 255}, renderer));

    game.addEntity(player);
    game.addEntity(enemy);

    game.run();
    return 0;
}