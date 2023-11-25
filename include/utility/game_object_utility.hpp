/**
 * @file game_object_utility.hpp
 * @author "Melvin van Bree"
 * @brief Game Object utility
 * @version 0.1
 * @date 25/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_INCLUDE_UTILITY_GAME_OBJECT_UTILITY_HPP
#define DEFUNBOBENGINE_INCLUDE_UTILITY_GAME_OBJECT_UTILITY_HPP

#include "core_constants.hpp"
#include "game_object.hpp"
#include <functional>
#include <iostream>

class GameObjectUtility
{
  public:
    /**
     * @brief Processes game objects recursively based on a predicate.
     * @param gameObject The game object to start the recursion from
     * @param callback The callback to execute on each eligible game object
     * @param predicate The predicate to determine whether a game object should be processed
     * @param maxDepth The maximum depth to process
     * @param currentDepth The current depth of the recursion
     */
    static void ProcessObjectsRecursively(
        const std::shared_ptr<GameObject> &gameObject,
        const std::function<void(std::shared_ptr<GameObject>)> &callback,
        const std::function<bool(const std::shared_ptr<GameObject> &)> &predicate,
        int maxDepth = CoreConstants::Engine::MAX_NESTED_CHILDREN, int currentDepth = 0)
    {
        if (currentDepth >= maxDepth)
        {
            // Safety check to prevent infinite recursion
            std::cerr << "Max depth reached. Aborting recursion for GameObject: "
                      << gameObject->GetName() << std::endl;
            return;
        }

        if (!gameObject || !predicate(gameObject))
            return;

        callback(gameObject);

        for (const auto &gameObjectNode : gameObject->GetChildren())
        {
            // Skip inactive or undesired game objects
            if (!gameObjectNode || !predicate(gameObjectNode))
                continue;

            // Safety check to prevent recursive relationships
            if (gameObjectNode.get() == gameObject.get())
            {
                std::cerr << "Recursive relationship detected. Aborting recursion for GameObject: "
                          << gameObject->GetName() << std::endl;
                continue;
            }

            ProcessObjectsRecursively(gameObjectNode, callback, predicate, maxDepth,
                                      currentDepth + 1);
        }
    }

    /**
     * @brief Processes all active game objects recursively.
     * @param gameObject The game object to start the recursion from
     * @param callback The callback to execute on each active game object
     * @param maxDepth The maximum depth to process
     * @param currentDepth The current depth of the recursion
     */
    static void ProcessActiveObjectsRecursively(
        const std::shared_ptr<GameObject> &gameObject,
        const std::function<void(std::shared_ptr<GameObject>)> &callback,
        int maxDepth = CoreConstants::Engine::MAX_NESTED_CHILDREN, int currentDepth = 0)
    {
        auto isActivePredicate = [](const std::shared_ptr<GameObject> &obj)
        { return obj && obj->IsActive(); };

        ProcessObjectsRecursively(gameObject, callback, isActivePredicate, maxDepth, currentDepth);
    }
};

#endif // DEFUNBOBENGINE_INCLUDE_UTILITY_GAME_OBJECT_UTILITY_HPP
