/**
 * @file game_object_list.hpp
 * @brief This file contains the GameObjectList class definition.
 * @version 0.1
 * @date 2023-11-08
 *
 * This file contains the GameObjectList class definition. The GameObjectList class represents a list of GameObjects in a parent-child hierarchy.
 * It is used to keep track of the parent-child relationships between GameObjects in the game world.
 */

#ifndef DEFUNBOBENGINE_GAME_OBJECT_LIST_HPP
#define DEFUNBOBENGINE_GAME_OBJECT_LIST_HPP

#include "game_object.hpp"
#include <memory>
#include <utility>
#include <string>

class GameObject;

/**
 * @brief The GameObjectNode class represents a node in a GameObjectList.
 */
class GameObjectNode {
  public:
    std::shared_ptr<GameObjectNode> parent; //< The parent node
    std::shared_ptr<GameObject> cur; //< The current game object
    std::shared_ptr<GameObjectNode> child; //< The child node

    /**
     * @brief Checks if the node has a parent
     * @return True if the node has a parent, otherwise false
     */
    [[nodiscard]] bool hasParent() const;
};

/**
 * @brief The GameObjectListIterator class represents a bi-directional iterator for a
 * GameObjectList.
 *
 * Forwards and backwards iteration is supported.
 * Forwards iteration starts at the root node and ends at the origin node.
 * Backwards iteration starts at the origin node and ends at the root node.
 */
class GameObjectListIterator {
  private:
    std::shared_ptr<GameObjectNode> currentNode;

  public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = std::shared_ptr<GameObjectNode>;
    using difference_type = std::ptrdiff_t;
    using pointer = std::shared_ptr<GameObjectNode>;
    using reference = std::shared_ptr<GameObjectNode>&;  // Corrected type

    // Constructor
    explicit GameObjectListIterator(std::shared_ptr<GameObjectNode> node) : currentNode(std::move(node)) {}

    GameObjectListIterator& operator++();
    const GameObjectListIterator operator++(int);
    GameObjectListIterator& operator--();
    const GameObjectListIterator operator--(int);
    bool operator==(const GameObjectListIterator& other) const;
    bool operator!=(const GameObjectListIterator& other) const;
    std::shared_ptr<GameObjectNode>& operator*();
};

/**
 * @brief The GameObjectList class represents a list of GameObjects in a parent-child hierarchy.
 */
class GameObjectList
{
  private:
    std::shared_ptr<GameObjectNode> root; ///< The root node of the list
    std::shared_ptr<GameObjectNode> origin; ///< The origin node of the list

  public:
    /**
     * @brief Builds the list from a game object
     * @param gameObject The game object to build the list from
     */
    explicit GameObjectList(const std::weak_ptr<GameObject>& gameObject);

    /**
     * @brief Returns the root node of the list
     * @return The root node
     */
    std::shared_ptr<GameObjectNode> Root();

    /**
     * @brief Returns the origin node of the list
     * @return The origin node
     */
    std::shared_ptr<GameObjectNode> Origin();

    /**
     * @brief Finds a node by name
     * @param name Name of the node
     * @return The node if found, otherwise an empty pointer
     */
    std::shared_ptr<GameObjectNode> FindNode(const std::string& name);

    /**
     * @brief Finds a node by reference
     * @param ref Reference of the node
     * @return The node if found, otherwise an empty pointer
     */
    std::shared_ptr<GameObjectNode> FindNode(const GameObject* red);

    /**
     * Iterator starting at the root
     * @return The iterator
     */
    [[nodiscard]] GameObjectListIterator begin() const;

    /**
     * Iterator starting at the original game object
     * @return The iterator
     */
    [[nodiscard]] GameObjectListIterator end() const;
};

#endif // DEFUNBOBENGINE_GAME_OBJECT_LIST_HPP
