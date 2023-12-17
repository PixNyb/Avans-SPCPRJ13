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

/**
 * @class PropertyManager
 * @brief Manages various properties which are stored in a JSON file.
 *
 * This class is responsible for managing properties of the game. These properties are stored in a
 * JSON file, the path to which is passed from the game. Only a few properties can be stored in this
 * PropertyManager, these types of properties are: int, float, bool and string
 */
class PropertyManager
{
  private:
    std::shared_ptr<JSONHandler>
        jsonHandler; ///< A JSONHandler used to read and write the property file.

    std::string fileExtension; ///< The expected file extension of the properties file.

    /**
     * @brief Validates whether the type passed is supported by the PropertyManager.
     * @tparam T The type which is passed.
     * @return A bool indicating whether the type is supported.
     */
    template <typename T> bool IsSupportedType()
    {
        return (std::is_same<T, int>::value || std::is_same<T, float>::value ||
                std::is_same<T, bool>::value || std::is_same<T, std::string>::value);
    }

  public:
    /**
     * @brief Constructs a new PropertyManager
     * @param jHandler The JSONHandler used to read and write the property file.
     */
    explicit PropertyManager(std::shared_ptr<JSONHandler> &jHandler);

    /**
     * @brief This function stores a value based on a string key.
     * @tparam T The type of the value which is to be stored.
     * @param filePath The path of the property file which is to be edited.
     * @param key The key which is used to identify the property.
     * @param value The value which is to be stored.
     */
    template <typename T> void StoreValue(std::string &filePath, std::string &key, T value)
    {
        if (!IsSupportedType<T>())
            throw std::runtime_error(fmt::format("Unsupported type was passed. Only int, float, "
                                                 "bool and string are supported. Passed type: {}",
                                                 typeid(T).name()));

        if (key.length() == 0)
            throw std::runtime_error("An empty key was provided.");

        auto propertyFile = jsonHandler->ConvertFileToJson(filePath);
        if (propertyFile.is_null() || !propertyFile.is_object())
            throw std::runtime_error("The file did not contain a valid json.");

        try
        {
            propertyFile[key] = value;
        }
        catch (std::exception &e)
        {
            // Propagate exception.
            throw std::runtime_error(e.what());
        }

        jsonHandler->WriteJsonToFile(filePath, propertyFile);
    }

    /**
     * @brief This function retrieves a value based on a string key.
     * @tparam T The type of the value which is to be retrieved.
     * @param filePath The path of the property file which it is to be retrieved from.
     * @param key The key which is used to retrieve the property.
     * @return The value that was retrieved.
     */
    template <typename T> T GetValue(std::string &filePath, std::string &key)
    {
        if (!IsSupportedType<T>())
            throw std::runtime_error(fmt::format("Unsupported type was passed. Only int, float, "
                                                 "bool and string are supported. Passed type: {}",
                                                 typeid(T).name()));

        if (key.length() == 0)
            throw std::runtime_error("An empty key was provided.");

        auto propertyFile = jsonHandler->ConvertFileToJson(filePath);

        T value;
        try
        {
            value = propertyFile.at(key).template get<T>();
        }
        catch (std::exception &e)
        {
            // Propagate exception.
            throw std::runtime_error(e.what());
        }

        return value;
    }
};

#endif // DEFUNBOBENGINE_PROPERTY_MANAGER_HPP
