/**
 * @file di_container.hpp
 * @author "Melvin van Bree"
 * @brief Dependency injection container
 * @version 0.1
 * @date 10/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef AVANS_SPCPRJ13_DI_CONTAINER_HPP
#define AVANS_SPCPRJ13_DI_CONTAINER_HPP

#include <unordered_map>
#include <memory>

/**
 * @brief The scope of the instance
 */
enum class InstanceScope {
    /**
     * @brief The instance is public. Stuff like SceneManager should be public.
     */
    Public,
    /**
     * @brief The instance is engine related. Stuff like IOFacade should be engine related.
     */
    Engine
};

/**
 * @brief The default instance scope
 */
const InstanceScope DEFAULT_INSTANCE_SCOPE  = InstanceScope::Public;

/**
 * @brief The dependency injection container
 * @details This container is used to store private or public instances for the game dev like SceneManager etc.
 * @note Refer to InstanceScope for more information about the scope of the instance.
 */
class DIContainer {
  private:
    std::unordered_map<InstanceScope, std::unordered_map<std::size_t, std::shared_ptr<void>>> instances;

  public:

    /**
     * @brief Registers an instance
     * @tparam T The type of the instance, this is what the instance is bound to. So you should use abstract base types here if there are any.
     * @param instance The instance to register
     * @param scope The scope of the instance. Refer to InstanceScope for more information.
     * @warning You can bind any type to any instance, but you should only bind abstract base types to instances.
     */
    template <typename T>
    void registerInstance(std::shared_ptr<T> instance, InstanceScope scope = DEFAULT_INSTANCE_SCOPE) {
        instances[scope][typeid(T).hash_code()] = instance;
    }

    /**
     * @brief Resolves an instance
     * @tparam T The type of the instance
     * @param scope The scope of the instance. Refer to InstanceScope for more information.
     * @return std::shared_ptr<T> Nullptr if the instance is not found, otherwise the instance
     */
    template <typename T>
    std::shared_ptr<T> resolve(InstanceScope scope = DEFAULT_INSTANCE_SCOPE) {
        auto& scopeInstances = instances[scope];

        auto it = scopeInstances.find(typeid(T).hash_code());
        if (it != scopeInstances.end()) {
            return std::static_pointer_cast<T>(it->second);
        }
        return nullptr;
    }
};

#endif // AVANS_SPCPRJ13_DI_CONTAINER_HPP
