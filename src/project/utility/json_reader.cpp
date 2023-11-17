/**
* @file json_reader.cpp
* @author Maxuuuu
* @brief Implementation of the JSONReader.
* @version 0.1
* @date 11/11/2023
*
* @copyright Copyright (c) 2023
*
*/

#include "json_reader.hpp"
#include <fstream>
#include <nlohmann/json.hpp>

nlohmann::json JSONReader::ConvertFileToJson(const std::string &filePath) {
    std::ifstream file(filePath, std::ifstream::binary);

    return nlohmann::json::parse(file);
}
