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
    std::ifstream file(filePath, std::ifstream::binary);

    return nlohmann::json::parse(file);
}

std::string JSONHandler::WriteJsonToFile(const std::string &destination,
                                         const std::string &fileName, const nlohmann::json &json)
{
    // Normalize the destination path and validate whether it exists.
    auto normDestination = std::filesystem::absolute(destination).string();
    if (!std::filesystem::exists(normDestination))
        throw std::runtime_error(fmt::format("Path was not found: {}", normDestination));

    // Create and normalize final file path to which the json is to be written.
    auto path = std::filesystem::absolute(normDestination + fileName + fileExtension).string();

    std::ofstream file(path);

    // The parameter 4 in dump indicates how deep of an indent should be made when formatting the
    // json file. An indentation is used to make the level files more readable to the human eye.
    file << json.dump(4);

    file.close();

    return path;
}
