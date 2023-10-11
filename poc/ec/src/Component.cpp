#include "Component.hpp"
#include "Entity.hpp"

void PositionComponent::update(SDL_Event &event) {}

void InputComponent::update(SDL_Event &event) {
  MovementComponent *movementComponent =
      entity.getComponent<MovementComponent>();

  if (movementComponent == nullptr)
    return;

  if (event.type == SDL_KEYDOWN) {
    switch (event.key.keysym.sym) {
    case SDLK_UP:
      movementComponent->setVy(-5);
      break;
    case SDLK_DOWN:
      movementComponent->setVy(5);
      break;
    case SDLK_LEFT:
      movementComponent->setVx(-5);
      break;
    case SDLK_RIGHT:
      movementComponent->setVx(5);
      break;
    }
  } else if (event.type == SDL_KEYUP) {
    switch (event.key.keysym.sym) {
    case SDLK_UP:
      movementComponent->setVy(0);
      break;
    case SDLK_DOWN:
      movementComponent->setVy(0);
      break;
    case SDLK_LEFT:
      movementComponent->setVx(0);
      break;
    case SDLK_RIGHT:
      movementComponent->setVx(0);
      break;
    }
  }
}

void FollowComponent::update(SDL_Event &event) {
  PositionComponent *positionComponent =
      entity.getComponent<PositionComponent>();
  MovementComponent *movementComponent =
      entity.getComponent<MovementComponent>();
  PositionComponent *targetPositionComponent =
      target.getComponent<PositionComponent>();

  if (positionComponent == nullptr || movementComponent == nullptr ||
      targetPositionComponent == nullptr)
    return;

  int x = positionComponent->getX();
  int y = positionComponent->getY();
  int targetX = targetPositionComponent->getX();
  int targetY = targetPositionComponent->getY();

  if (x < targetX)
    movementComponent->setVx(2);
  else if (x > targetX)
    movementComponent->setVx(-2);
  else
    movementComponent->setVx(0);

  if (y < targetY)
    movementComponent->setVy(2);
  else if (y > targetY)
    movementComponent->setVy(-2);
  else
    movementComponent->setVy(0);
}

void MovementComponent::update(SDL_Event &event) {
  PositionComponent *positionComponent =
      entity.getComponent<PositionComponent>();

  if (positionComponent == nullptr)
    return;

  positionComponent->setX(positionComponent->getX() + vx);
  positionComponent->setY(positionComponent->getY() + vy);
}

void RenderComponent::update(SDL_Event &event) {
  PositionComponent *positionComponent =
      entity.getComponent<PositionComponent>();

  if (positionComponent == nullptr)
    return;

  SDL_Rect rect;
  rect.x = positionComponent->getX();
  rect.y = positionComponent->getY();
  rect.w = width;
  rect.h = height;

  SDL_SetRenderDrawColor(&renderer, color.r, color.g, color.b, color.a);
  SDL_RenderFillRect(&renderer, &rect);
}