#pragma once
#include "entt/entt.hpp"
#include "scene.h"

class GameObject
{
  public:
    GameObject() = default;
    GameObject(entt::entity handle, std::shared_ptr<Scene> &scene);
    GameObject(const GameObject &other) = default;

    //    template<typename T, typename... Args>
    //    T& addComponent(Args&&... args) {
    //        if(_scene->registry().any_of<T>(_handle)){
    //            return _scene->registry().get<T>(_handle);
    //        }
    //        auto& component = _scene->registry().emplace<T>(_handle, std::forward<Args>(args)...);
    //        return component;
    //    };
    //
    //    template<typename T>
    //    bool hasComponent(){
    //        return _scene->registry().any_of<T>(_handle);
    //    }
    //
    //    template<typename T>
    //    void removeComponent(){
    //        if(_scene->registry().any_of<T>(_handle)){
    //            _scene->registry().remove<T>(_handle);
    //        }
    //    }

    entt::entity handle() { return this->_handle; }

  private:
    bool _isActive;
    entt::entity _handle;
    std::shared_ptr<Scene> _scene{nullptr};
};
