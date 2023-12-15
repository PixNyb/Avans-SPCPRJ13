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
    /**
     * @brief A JSONHandler used to read and write the property file.
     */
    std::shared_ptr<JSONHandler> jsonHandler;

    /**
     * @brief The expected file extension of the properties file.
     */
    std::string fileExtension;

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

    /**
     * @brief Validate the path that was passed and return it normalised..
     * @param filePath The file path that is to be validated.
     * @return The validated and normalised file path.
     */
    std::string ValidatePath(std::string &filePath);

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

        auto normPath = ValidatePath(filePath);

        if (key.length() == 0)
            throw std::runtime_error("An empty key was provided.");

        auto propertyFile = jsonHandler->ConvertFileToJson(normPath);
        propertyFile[key] = value;

        // TODO: Add file storage.
        // jsonHandler->WriteJsonToFile();
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

        auto normPath = ValidatePath(filePath);

        if (key.length() == 0)
            throw std::runtime_error("An empty key was provided.");

        auto propertyFile = jsonHandler->ConvertFileToJson(normPath);

        return propertyFile.at(key).template get<T>();
    }
};

#endif // DEFUNBOBENGINE_PROPERTY_MANAGER_HPP
