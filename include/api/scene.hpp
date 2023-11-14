/// @file

#ifndef AVANS_SPCPRJ13_SCENE_H
#define AVANS_SPCPRJ13_SCENE_H

#include "game_object.hpp"
#include <memory>
#include <vector>

/**
 * @brief Class representing a scene which can be rendered by the Camera.
 */
class Scene
{
  public:
    /**
     * @brief This function is called by a Camera to render the scene on the engine.
     */
    virtual void RenderScene(){
        // TODO: Write implementation.
    };

    virtual ~Scene() = default;

    /**
    * @brief Updates all game objects in the scene.
    * @param deltaTime The time passed since the last frame.
     */
    virtual void Update(float deltaTime){
        // TODO: Call an update on game object?
    }

    /**
     * @brief This property contains all the Game Object that are contained in this scene.
     */
    std::vector<std::shared_ptr<GameObject>> contents;

    /**
     * @brief Adds a game object, might be required for stuff like prefabs
     */
    void AddGameObject(const std::shared_ptr<GameObject> &gameObject);

    /**
     * @brief Creates a game object and adds it to the scene, should be the preferred method of creating game objects for clear ownership
     * @return The created game object as a weak pointer because the created game object is owned by the scene
     */
    std::weak_ptr<GameObject> CreateGameObject();

    /**
     * @brief Creates a game object and adds it to the scene, should be the preferred method of creating game objects for clear ownership
     * @tparam GameObjectType The type of game object to create.
     * @tparam Args The types of arguments to forward to the GameObject constructor.
     * @param args The arguments to forward to the GameObject constructor.
     * @return The created game object as a weak pointer because the created game object is owned by the scene.
     */
    template <typename GameObjectType, typename... Args>
    std::weak_ptr<GameObjectType> CreateGameObject(Args&&... args);

    /**
     * @brief Gets all game objects by type
     * @tparam T Type of the game object
     * @return A vector containing all game objects of the specified type
     */
    template<typename T>
    std::vector<std::weak_ptr<T>> GetAllByType();

    /**
     * @brief Finds a game object by name
     * @param name Name of the game object
     * @return The game object if found, otherwise an empty pointer
     */
    std::weak_ptr<GameObject> findGameObjectByName(const std::string &name);

    /**
     * @brief Finds game objects by tag
     * @param tag Tag of the game objects
     * @return The game objects if found, otherwise an empty vector
     */
    std::vector<std::weak_ptr<GameObject>> findGameObjectByTag(const std::string &tag);

    /**
     * @brief Removes a game object by name
     * @param name Name of the game object
     * @return True if the game object was found and removed, otherwise false
     */
    bool removeGameObjectByName(const std::string &name);

    /**
     * @brief Removes a game object by tag
     * @param tag Tag of the game object
     * @return True if the game object was found and removed, otherwise false
     */
    bool removeGameObjectByTag(const std::string &tag);

    /**
     * @brief Removes all game objects from the scene
     */
    void Clear();

    /**
     * @brief Returns the amount of game objects in the scene
     * @return Amount of game objects in the scene
     */
    [[nodiscard]] size_t GetGameObjectCount() const { return contents.size(); }

    /**
     * @brief Sets the active status of a specific game object by name.
     * @param name Name of the game object.
     * @param isActive The new active status.
     * @return True if the game object was found and the status was updated, otherwise false.
     */
    bool SetActiveStatus(const std::string &name, bool isActive);
};

#endif // AVANS_SPCPRJ13_SCENE_H
