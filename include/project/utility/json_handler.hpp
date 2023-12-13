/**
 * @file json_reader.hpp
 * @author Maxuuuu
 * @brief Converts data sources to json
 * @version 0.1
 * @date 11/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_JSON_HANDLER_HPP
#define DEFUNBOBENGINE_JSON_HANDLER_HPP

#include <nlohmann/json.hpp>

/**
 * @class JSONHandler
 * @brief Converts JSON files to a readable JSON object.
 *
 * This class is capable of converting JSON files to readable JSON objects.
 */
class JSONHandler
{
  private:
    /**
     * @brief The accepted file extension for a json file.
     */
    std::string fileExtension;

  public:
    /**
     * @brief Constructs a new JSONHandler.
     */
    JSONHandler() = default;

    /**
     * @brief Converts a file to a JSON object.
     * @param filePath Path to the file that is to be converted.
     * @return A JSON object.
     */
    nlohmann::json ConvertFileToJson(const std::string &filePath);

    /**
     * @brief Write a json object to a json file.
     * @param destination The folder which the file is to be written to.
     * @param fileName The name which the file should have.
     * @param json The json object which is tob e written to the file.
     * @return The resulting file path to which the json was written.
     */
    std::string WriteJsonToFile(const std::string &destination, const std::string &fileName,
                                const nlohmann::json &json);
};

#endif // DEFUNBOBENGINE_JSON_HANDLER_HPP
