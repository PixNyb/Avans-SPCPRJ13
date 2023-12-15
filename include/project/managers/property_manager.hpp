/**
 * @file property_manager.hpp
 * @author Maxuuuu
 * @brief This file contains the class definition for the PropertyManager.
 * @version 0.1
 * @date 14/12/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_PROPERTY_MANAGER_HPP
#define DEFUNBOBENGINE_PROPERTY_MANAGER_HPP

#include "json_handler.hpp"
#include <fmt/format.h>
#include <memory>
#include <nlohmann/json.hpp>
#include <string>
#include <type_traits>

class PropertyManager
{
  private:
    std::shared_ptr<JSONHandler> jsonHandler;

  public:
    /**
     * @brief Constructs a new PropertyManager
     * @param jHandler The JSONHandler used to read and write the property file.
     */
    PropertyManager(std::shared_ptr<JSONHandler> &jHandler);

    /**
     * @brief This function stores a int value based on a string key.
     * @param key The key which is used to identify the property.
     * @param value The value which is to be stored.
     */
    template <typename T> void StoreValue(std::string &key, T value)
    {
        if (!std::is_same<T, int>::value && !std::is_same<T, float>::value &&
            !std::is_same<T, bool>::value && !std::is_same<T, std::string>::value)
            throw std::runtime_error(fmt::format("Unsupported type was passed. Only int, float, "
                                                 "bool and string are supported. Passed type: {}",
                                                 typeid(value).name()));
    }

    template <typename T> T GetValue(std::string &key);
};

#endif // DEFUNBOBENGINE_PROPERTY_MANAGER_HPP
