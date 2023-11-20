//
// Created by melvi on 20/11/2023.
//

#ifndef DEFUNBOBENGINE_GAME_OBJECT_LIST_HPP
#define DEFUNBOBENGINE_GAME_OBJECT_LIST_HPP

#include "game_object.hpp"
#include <memory>
#include <utility>

class GameObjectNode {
  public:
    std::shared_ptr<GameObjectNode> parent;
    std::shared_ptr<GameObject> cur;
    std::shared_ptr<GameObjectNode> child;

    [[nodiscard]] bool hasParent() const;
};

class GameObjectListIterator {
  private:
    std::shared_ptr<GameObjectNode> currentNode;

  public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = std::shared_ptr<GameObjectNode>;
    using difference_type = std::ptrdiff_t;
    using pointer = std::shared_ptr<GameObjectNode>;
    using reference = std::shared_ptr<GameObjectNode>;

    // Constructor
    explicit GameObjectListIterator(std::shared_ptr<GameObjectNode> node) : currentNode(std::move(node)) {}

    GameObjectListIterator& operator++();
    const GameObjectListIterator operator++(int);
    GameObjectListIterator& operator--();
    const GameObjectListIterator operator--(int);
    bool operator==(const GameObjectListIterator& other) const;
    bool operator!=(const GameObjectListIterator& other) const;
    std::shared_ptr<GameObjectNode> operator*() const;
};

class GameObjectList
{
  private:
    std::shared_ptr<GameObjectNode> root;
    std::shared_ptr<GameObjectNode> origin;

    void BuildList(const std::weak_ptr<GameObject>& gameObject);
  public:
    explicit GameObjectList(const std::weak_ptr<GameObject>& gameObject);
    std::shared_ptr<GameObjectNode> Root();
    std::shared_ptr<GameObjectNode> Origin();
    [[nodiscard]] GameObjectListIterator begin() const;
    [[nodiscard]] GameObjectListIterator end() const;
};

#endif // DEFUNBOBENGINE_GAME_OBJECT_LIST_HPP
