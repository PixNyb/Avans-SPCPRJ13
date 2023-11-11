/**
 * @file json_reader.hpp
 * @author max groenendaal
 * @brief Converts data sources to json
 * @version 0.1
 * @date 11/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_JSON_READER_HPP
#define DEFUNBOBENGINE_JSON_READER_HPP

#include "json/value.h"

class JSONReader {
public:
    JSONReader() = default;

    /**
     * @brief Converts a file to a JSON object.
     * @param filePath Path to the file that is to be converted.
     * @return A JSON object.
     */
    Json::Value ConvertFileToJson(const std::string &filePath);

};

#endif //DEFUNBOBENGINE_JSON_READER_HPP
