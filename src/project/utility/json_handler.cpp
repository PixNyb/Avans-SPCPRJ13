/**
 * @file json_reader.cpp
 * @author Maxuuuu
 * @brief Implementation of the JSONHandler.
 * @version 0.1
 * @date 11/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "json_handler.hpp"
#include "fmt/format.h"
#include <fstream>
#include <nlohmann/json.hpp>

nlohmann::json JSONHandler::ConvertFileToJson(const std::string &filePath)
{
    // Normalize the destination path and validate whether it exists.
    auto normPath = ValidateFilePath(filePath);

    std::ifstream file(normPath, std::ifstream::binary);

    return nlohmann::json::parse(file);
}

std::string JSONHandler::WriteJsonToFile(const std::string &filePath, const nlohmann::json &json)
{
    // Normalize the destination path and validate whether it exists.
    auto normPath = ValidateFilePath(filePath);

    std::ofstream file(normPath);

    // The parameter 4 in dump indicates how deep of an indent should be made when formatting the
    // json file. An indentation is used to make the level files more readable to the human eye.
    file << json.dump(4);

    file.close();

    return normPath;
}

std::string JSONHandler::ValidateFilePath(const std::string &filePath)
{
    if (filePath.length() < fileExtension.length() ||
        (0 != filePath.compare(filePath.length() - fileExtension.length(), fileExtension.length(),
                               fileExtension)))
        throw std::runtime_error(
            fmt::format("The file is of a unsupported type. Expected type: '{}'", fileExtension));

    auto normPath = std::filesystem::absolute(filePath).string();
    if (!std::filesystem::exists(filePath))
        throw std::runtime_error(fmt::format("Path was not found: {}", filePath));

    return normPath;
}