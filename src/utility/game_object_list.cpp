//
// Created by melvi on 20/11/2023.
//

#include "game_object_list.hpp"

#include <utility>

// Node
bool GameObjectNode::hasParent() const {
    return cur->GetParent() != nullptr;
}

// Iterator
GameObjectListIterator &GameObjectListIterator::operator++()
{
    if (currentNode) {
        currentNode = currentNode->child;
    }
    return *this;
}
const GameObjectListIterator GameObjectListIterator::operator++(int)
{
    GameObjectListIterator tmp = *this;
    ++(*this);
    return tmp;
}
GameObjectListIterator &GameObjectListIterator::operator--()
{
    if (currentNode) {
        currentNode = currentNode->parent;
    }
    return *this;
}
const GameObjectListIterator GameObjectListIterator::operator--(int)
{
    GameObjectListIterator tmp = *this;
    --(*this);
    return tmp;
}
bool GameObjectListIterator::operator==(const GameObjectListIterator &other) const
{
    return currentNode == other.currentNode;
}
bool GameObjectListIterator::operator!=(const GameObjectListIterator &other) const
{
    return !(*this == other);
}
std::shared_ptr<GameObjectNode> GameObjectListIterator::operator*() const {
    return currentNode;
}

// Game object lists
void GameObjectList::BuildList(const std::weak_ptr<GameObject>& gameObject)
{
    auto originObject = gameObject.lock();
    origin->cur = originObject;

    auto curNode = origin;
    // As long as it has a parent, continue
    while(curNode->hasParent()){
        // Set parent curNode
        auto curObject = curNode->cur;
        if(!curObject) break;

        auto parentNode = std::make_shared<GameObjectNode>();
        parentNode->cur = curObject->GetParent();
        parentNode->child = curNode;

        curNode->parent = parentNode;
        curNode = curNode->parent;
    }

    root = curNode;
}
GameObjectList::GameObjectList(const std::weak_ptr<GameObject>& gameObject)
{
    origin = std::make_shared<GameObjectNode>();
    root = std::make_shared<GameObjectNode>();
    BuildList(gameObject);
}
std::shared_ptr<GameObjectNode> GameObjectList::Root() {
    return root;
}
std::shared_ptr<GameObjectNode> GameObjectList::Origin() {
    return origin;
}
GameObjectListIterator GameObjectList::begin() const {
    return GameObjectListIterator(root);
}
GameObjectListIterator GameObjectList::end() const {
    return GameObjectListIterator(nullptr);
}
