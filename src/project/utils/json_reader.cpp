//
// Created by maxro on 11/11/2023.
//

#include <fstream>
#include "json/json.h"
#include "json_reader.hpp"

Json::Value JSONReader::ConvertFileToJson(const std::string &filePath) {
    std::ifstream file(filePath, std::ifstream::binary);
    Json::Value json;
    file >> json;

    return json;
}
