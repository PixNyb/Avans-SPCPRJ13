#include "level_factory.hpp"
#include <gtest/gtest.h>
#include <optional>

class LevelFactoryStub : public LevelFactory
{
  public:
    explicit LevelFactoryStub(std::shared_ptr<PrefabManager> &manager) : LevelFactory(manager)
    {}

    std::vector<std::shared_ptr<GameObject>> PublicAddObjects(Scene &scene, const nlohmann::json &objectsJson)
    {
        return this->AddObjects(scene, objectsJson);
    }

    [[nodiscard]] Transform PublicConvertTransform(const nlohmann::json &transformJson) const
    {
        return this->ConvertTransform(transformJson);
    }
};

class LevelTest : public ::testing::Test
{
  public:
    // Factory is already defined here because it has no base constructor.
    LevelTest() : factory {CreatePrefabManager()}
    {}

    // The PrefabManager is stored here so that it can be passed as a reference.
    std::shared_ptr<PrefabManager> prefabManager;

    LevelFactoryStub factory;

    void SetUp() override
    {
        // Resets the LevelFactory for every test.
        factory = LevelFactoryStub(CreatePrefabManager());
    }

  private:
    // This is wrapped in a function so that it can be used for the base constructor.
    std::shared_ptr<PrefabManager> &CreatePrefabManager() {
        prefabManager = std::make_shared<PrefabManager>();

        return prefabManager;
    }
};

TEST_F(LevelTest, ConvertTransform)
{
    // Define the expected end result.
    Transform other = Transform(Point(4, 1), 0.0, 1.0);

    // Create a transform json.
    nlohmann::json transformJson = {
        {"position",
          {
              {"x", other.position.x},
              {"y", other.position.y}
          }
        },
        {"rotation", other.rotation},
        {"scale", other.scale}
    };

    // Result of the conversion.
    Transform transform = factory.PublicConvertTransform(transformJson);
    // Check that the converted Transform is equal to the input.
    ASSERT_EQ(transform, other);

    // Incorrect format, missing rotation and scale.
    nlohmann::json incorrectFormat = {
        {"position", {{"x", other.position.x}, {"y", other.position.y}}}
    };

    // Assert that an error is thrown when invalid input is given.
    ASSERT_ANY_THROW(factory.PublicConvertTransform(incorrectFormat));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}