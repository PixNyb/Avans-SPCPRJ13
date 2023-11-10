/**
 * @file di_container.hpp
 * @author "Melvin van Bree"
 * @brief TODO
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

class DIContainer {
  private:
    std::unordered_map<std::size_t, std::shared_ptr<void>> instances;

  public:
    template <typename T>
    void registerInstance(std::shared_ptr<T> instance) {
        instances[typeid(T).hash_code()] = instance;
    }

    template <typename T>
    std::shared_ptr<T> resolve() {
        auto it = instances.find(typeid(T).hash_code());
        if (it != instances.end()) {
            return std::static_pointer_cast<T>(it->second);
        }
        return nullptr;
    }
};

#endif // AVANS_SPCPRJ13_DI_CONTAINER_HPP
