/**
 * @file property_manager.hpp
 * @author Maxuuuu
 * @brief This file contains the implementation of the PropertyManager class.
 * @version 0.1
 * @date 15/12/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "property_manager.hpp"

PropertyManager::PropertyManager(std::shared_ptr<JSONHandler> &jHandler)
    : jsonHandler(jHandler), fileExtension(".json")
{
}

std::string PropertyManager::ValidatePath(std::string &filePath)
{
    if (filePath.length() < fileExtension.length() ||
        (0 != filePath.compare(filePath.length() - fileExtension.length(), fileExtension.length(),
                               fileExtension)))
        throw std::runtime_error(
            fmt::format("The file is of a unsupported type. Expected type: '{}'", fileExtension));

    auto normPath = std::filesystem::absolute(filePath).string();
    if (!std::filesystem::exists(normPath))
        throw std::runtime_error(fmt::format("Path was not found: {}", normPath));

    return normPath;
}