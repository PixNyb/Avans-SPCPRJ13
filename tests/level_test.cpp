#include "level_factory.hpp"
#include <gtest/gtest.h>
#include <optional>

class LevelFactoryStub : public LevelFactory
{
  public:
    explicit LevelFactoryStub(std::shared_ptr<PrefabManager> &manager) : LevelFactory(manager) {}

    Transform PublicConvertTransform(const nlohmann::json &transformJson) const
    {
        return this->ConvertTransform(transformJson);
    }

    std::shared_ptr<Camera> PublicConvertCamera(const nlohmann::json &cameraJson) const
    {
        return this->ConvertCamera(cameraJson);
    }
};

class LevelTest : public ::testing::Test
{
  public:
    // Factory is already defined here because it has no base constructor.
    LevelTest() : factory{CreatePrefabManager()} {}

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
    std::shared_ptr<PrefabManager> &CreatePrefabManager()
    {
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
        {"position", {{"x", other.position.x}, {"y", other.position.y}}},
        {"rotation", other.rotation},
        {"scale", other.scale}};

    // Result of the conversion.
    Transform transform = factory.PublicConvertTransform(transformJson);

    // Check that the converted Transform is equal to the input.
    ASSERT_EQ(transform, other);

    // Incorrect format, missing rotation and scale.
    nlohmann::json incorrectFormat = {
        {"position", {{"x", other.position.x}, {"y", other.position.y}}}};

    // Assert that an error is thrown when invalid input is given.
    ASSERT_ANY_THROW(factory.PublicConvertTransform(incorrectFormat));
}

TEST_F(LevelTest, ConvertCamera)
{
    // Define the expected end result.
    auto other = std::make_unique<Camera>();
    other->SetAspectWidth(500);
    other->SetAspectHeight(500);

    // Create a camera json.
    nlohmann::json cameraJson = {{"width", other->GetAspectWidth()},
                                 {"height", other->GetAspectHeight()}};

    // Result of the conversion.
    std::shared_ptr<Camera> camera = factory.PublicConvertCamera(cameraJson);

    // Check that the convert camera has the same properties.
    ASSERT_EQ(camera->GetAspectWidth(), other->GetAspectWidth());
    ASSERT_EQ(camera->GetAspectHeight(), other->GetAspectHeight());

    // Incorrect format, missing height.
    nlohmann::json incorrectFormat = {{"width", other->GetAspectWidth()}};

    // Assert that an error is thrown when invalid input is given.
    ASSERT_ANY_THROW(factory.PublicConvertCamera(incorrectFormat));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}