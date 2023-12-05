/**
 * @file iscene_factory.hpp
 * @author Maxuuuu
 * @brief Abstract factory for creating scenes.
 * @version 0.1
 * @date 11/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_ISCENE_FACTORY_HPP
#define DEFUNBOBENGINE_ISCENE_FACTORY_HPP

#include "scene.hpp"
#include <nlohmann/json.hpp>

/**
 * @class ISceneFactory
 * @brief An interface for a scene factory.
 *
 * This interface defines a base for a scene factory.
 * It has a CreateScene function which can be used to create a scene based on a JSON object.
 */
class ISceneFactory
{
  public:
    /**
     * @brief Construct a new AbstractSceneFactory.
     */
    ISceneFactory() = default;

    /**
     * @brief Destroy the AbstractSceneFactory.
     */
    virtual ~ISceneFactory() = default;

    /**
     * @brief Creates a scene based on a provided JSON.
     * @param sceneJson The scene JSON.
     * @return The scene constructed based on the JSON.
     */
    virtual std::shared_ptr<Scene> CreateScene(nlohmann::json sceneJson) = 0;
};

#endif // DEFUNBOBENGINE_ISCENE_FACTORY_HPP
