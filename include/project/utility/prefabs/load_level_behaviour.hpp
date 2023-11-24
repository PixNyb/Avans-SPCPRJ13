/**
 * @file load_level_behaviour.hpp
 * @author Maxuuuu
 * @brief Defines behaviour which triggers a new level to be loaded.
 * @version 0.1
 * @date 22/11/2023
 *
 * @copright Copyright (c) 2023
 */

#ifndef DEFUNBOBENGINE_LOAD_LEVEL_BEHAVIOUR_HPP
#define DEFUNBOBENGINE_LOAD_LEVEL_BEHAVIOUR_HPP

#include "behaviour_script.hpp"
#include "level_manager.hpp"
#include <memory>

class LoadLevelBehaviour : public BehaviourScript {
  private:
    /**
     * @brief A LevelManager which can be used to load the level.
     */
    std::shared_ptr<LevelManager> levelManager;

    /**
     * @brief A level id which defines the level that is to be loaded.
     */
    int levelId;

  public:
    /**
     * @brief Construct a new LoadLevelBehaviour component.
     * @param manager The LevelManager which can be used to load the new level.
     * @param id The id of the level which is to be loaded.
     */
    LoadLevelBehaviour(std::shared_ptr<LevelManager> &manager, int id);

    /**
     * @brief Enables the component behaviour.
     */
    void OnStart() override;

    /**
     * @brief Triggers the loading of the new level.
     */
    void OnTriggerEnter2D(const Collider &collider) override;

};

#endif // DEFUNBOBENGINE_LOAD_LEVEL_BEHAVIOUR_HPP
