#include "game_object.h"

GameObject::GameObject(entt::entity handle, std::shared_ptr<Scene> &scene)
    : _handle(handle), _scene(scene), _isActive(true)
{
}