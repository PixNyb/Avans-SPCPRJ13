//
// Created by maxro on 11/11/2023.
//

#include <fstream>
#include "nlohmann/json.hpp"
#include "json_reader.hpp"

nlohmann::json JSONReader::ConvertFileToJson(const std::string &filePath) {
    std::ifstream file(filePath, std::ifstream::binary);

    return nlohmann::json::parse(file);
}
