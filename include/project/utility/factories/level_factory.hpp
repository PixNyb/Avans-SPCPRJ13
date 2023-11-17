/**
* @file level_factory.hpp
* @author Maxuuuu
* @brief Creates levels
* @version 0.1
* @date 11/11/2023
*
* @copyright Copyright (c) 2023
*
*/

#ifndef DEFUNBOBENGINE_LEVEL_FACTORY_HPP
#define DEFUNBOBENGINE_LEVEL_FACTORY_HPP

#include "abstract_scene_factory.hpp"
#include "prefab_manager.hpp"
#include <memory>

class LevelFactory : public AbstractSceneFactory {
  private:
    std::shared_ptr<PrefabManager> prefabManager;

    std::vector<std::shared_ptr<GameObject>> addObjects(Scene &scene, const nlohmann::json& objectsJson);

  public:
    /**
     * @brief Constructor for the level factory.
     * @param PrefabManager Provides the PrefabManager from where the prefabs are to be retrieved.
     */
    explicit LevelFactory(std::shared_ptr<PrefabManager> &PrefabManager);

    /**
     * @brief Creates a scene based on a JSON format.
     * @param sceneJson The level JSON.
     * @return The scene created based on the level JSON.
     */
    [[nodiscard]] Scene CreateScene(nlohmann::json sceneJson) override;
};

#endif // DEFUNBOBENGINE_LEVEL_FACTORY_HPP
