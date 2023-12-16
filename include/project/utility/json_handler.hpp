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

    /**
     * @brief Validate that the file exists and normalize the path.
     * @param filePath The file path that is to be validated.
     * @return The validated and normalized file path.
     */
    std::string ValidateFilePath(const std::string &filePath);

    /**
     * @brief Validate the file extension of the file path.
     * @param filePath The file path of which the extension is to be validated.
     */
    void ValidateExtension(const std::string &filePath);

  public:
    /**
     * @brief Constructs a new JSONHandler.
     */
    JSONHandler() : fileExtension(".json") {}

    /**
     * @brief Converts a file to a JSON object.
     * @param filePath Path to the file that is to be converted.
     * @return A JSON object.
     */
    nlohmann::json ConvertFileToJson(const std::string &filePath);

    /**
     * @brief Write a json object to a json file.
     * @param destination The file destination which is to be written to.
     * @param json The json object which is to be written to the file.
     * @return The resulting file path to which the json was written.
     */
    std::string WriteJsonToFile(const std::string &filePath, const nlohmann::json &json);
};

#endif // DEFUNBOBENGINE_JSON_HANDLER_HPP
