#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <SDL2/SDL.h>

class Entity;

class Component {
public:
  Component(Entity &entity) : entity(entity) {}
  ~Component() {}
  virtual void update(SDL_Event &event) = 0;

protected:
  Entity &entity;
};

class PositionComponent : public Component {
public:
  PositionComponent(Entity &entity, int x, int y)
      : Component(entity), x(x), y(y) {}
  ~PositionComponent() {}
  void update(SDL_Event &event) override;
  void setX(int x) { this->x = x; }
  void setY(int y) { this->y = y; }
  int getX() const { return x; }
  int getY() const { return y; }

private:
  int x;
  int y;
};

class InputComponent : public Component {
public:
  InputComponent(Entity &entity) : Component(entity) {}
  ~InputComponent() {}
  void update(SDL_Event &event) override;
};

class FollowComponent : public Component {
public:
  FollowComponent(Entity &entity, Entity &target)
      : Component(entity), target(target) {}
  ~FollowComponent() {}
  void update(SDL_Event &event) override;

private:
  Entity &target;
};

class MovementComponent : public Component {
public:
  MovementComponent(Entity &entity) : Component(entity) {}
  ~MovementComponent() {}
  void update(SDL_Event &event) override;
  void setVx(int vx) { this->vx = vx; }
  void setVy(int vy) { this->vy = vy; }
  int getVx() const { return vx; }
  int getVy() const { return vy; }

private:
  int vx = 0;
  int vy = 0;
};

class RenderComponent : public Component {
public:
  RenderComponent(Entity &entity, int width, int height, SDL_Color color,
                  SDL_Renderer &renderer)
      : Component(entity), width(width), height(height), color(color),
        renderer(renderer) {}
  ~RenderComponent() {}
  void update(SDL_Event &event) override;

private:
  int width;
  int height;
  SDL_Color color;
  SDL_Renderer &renderer;
};

#endif