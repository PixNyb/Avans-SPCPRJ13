#include "Component.hpp"
#include "Entity.hpp"

void PositionComponent::update(SDL_Event &event) {}

void InputComponent::update(SDL_Event &event)
{
    MovementComponent *movementComponent = entity.getComponent<MovementComponent>();
    if (!movementComponent)
        return;

    int vx = 0, vy = 0;
    switch (event.type)
    {
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
            vy = -5;
            break;
        case SDLK_DOWN:
            vy = 5;
            break;
        case SDLK_LEFT:
            vx = -5;
            break;
        case SDLK_RIGHT:
            vx = 5;
            break;
        }
        break;
    case SDL_KEYUP:
        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
            vy = 0;
            break;
        case SDLK_DOWN:
            vy = 0;
            break;
        case SDLK_LEFT:
            vx = 0;
            break;
        case SDLK_RIGHT:
            vx = 0;
            break;
        }
        break;
    }
    movementComponent->setVx(vx);
    movementComponent->setVy(vy);
}

void FollowComponent::update(SDL_Event &event)
{
    PositionComponent *positionComponent = entity.getComponent<PositionComponent>();
    MovementComponent *movementComponent = entity.getComponent<MovementComponent>();
    PositionComponent *targetPositionComponent = target.getComponent<PositionComponent>();
    if (!positionComponent || !movementComponent || !targetPositionComponent)
        return;

    int x = positionComponent->getX(), y = positionComponent->getY();
    int targetX = targetPositionComponent->getX(), targetY = targetPositionComponent->getY();
    int vx = (x < targetX) ? 2 : (x > targetX) ? -2 : 0;
    int vy = (y < targetY) ? 2 : (y > targetY) ? -2 : 0;
    movementComponent->setVx(vx);
    movementComponent->setVy(vy);
}

void MovementComponent::update(SDL_Event &event)
{
    PositionComponent *positionComponent = entity.getComponent<PositionComponent>();
    if (!positionComponent)
        return;

    positionComponent->setX(positionComponent->getX() + vx);
    positionComponent->setY(positionComponent->getY() + vy);
}

void RenderComponent::update(SDL_Event &event)
{
    PositionComponent *positionComponent = entity.getComponent<PositionComponent>();
    if (!positionComponent)
        return;

    SDL_Rect rect = {positionComponent->getX(), positionComponent->getY(), width, height};
    SDL_SetRenderDrawColor(&renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(&renderer, &rect);
}