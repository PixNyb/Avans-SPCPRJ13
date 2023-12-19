/**
 * @file level_name_generator.cpp
 * @author "Melvin van Bree"
 * @brief A file containing the LevelNameGenerator class.
 * @version 0.1
 * @date 19/12/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "level_name_generator.hpp"
#include <fmt/format.h>
#include <random>

namespace RandomLevelWords
{
static const std::vector<std::string> verbs = {
    "heroic",  "daring",  "courageous", "brave",     "fearless",
    "valiant", "gallant", "bold",       "audacious",
};

static const std::vector<std::string> nouns = {"adventure",
                                               "quest"
                                               "expedition",
                                               "voyage",
                                               "trip",
                                               "funbob",
                                               "bob"};
} // namespace RandomLevelWords

std::string LevelNameGenerator::Generate(int id)
{
    // Generate random number without using rand
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000);

    int randomVerbIndex = static_cast<int>(dis(gen) % RandomLevelWords::verbs.size());
    int randomNounIndex = static_cast<int>(dis(gen) % RandomLevelWords::nouns.size());
    int randomNumber = dis(gen);

    std::string name = fmt::format("{}_{}_{}_{}", id, RandomLevelWords::verbs[randomVerbIndex],
                                   RandomLevelWords::nouns[randomNounIndex], randomNumber);

    return name;
}