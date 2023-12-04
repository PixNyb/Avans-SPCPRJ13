#include "prefab_manager.hpp"
#include <gtest/gtest.h>

class PrefabManagerStub : public PrefabManager
{
  public:
    // The PrefabManagerStub allows for full access to the stored prefabs.
    std::map<std::string, std::shared_ptr<GameObject>> GetPrefabs() { return this->prefabs; }

    void InsertPrefab(const std::pair<std::string, std::shared_ptr<GameObject>> &value)
    {
        this->prefabs.insert(value);
    }
};

class PrefabTest : public ::testing::Test
{
  public:
    PrefabTest() = default;

    PrefabManagerStub manager;

    void SetUp() override
    {
        // Resets the PrefabManager for every test.
        manager = PrefabManagerStub();
    }
};

TEST_F(PrefabTest, RegisterPrefab)
{
    std::string key1 = "Key1";
    std::string key2 = "Key2";
    // Not testing with multiple properties, then it would become a test for the clone
    // functionality.
    auto obj1 = std::make_shared<GameObject>("Prefab1");
    manager.RegisterPrefab(key1, obj1);

    std::map<std::string, std::shared_ptr<GameObject>> prefabs = manager.GetPrefabs();
    auto it1 = prefabs.find(key1);

    // Check if key was registered
    ASSERT_NE(it1, prefabs.end());

    // Check if the prefab name is the same.
    ASSERT_EQ(it1->second->GetName(), obj1->GetName());

    auto obj2 = std::make_shared<GameObject>("Prefab2");
    manager.RegisterPrefab(key2, obj2);

    prefabs = manager.GetPrefabs(); // Update the prefabs.
    auto it2 = prefabs.find(key2);

    // Check if key was registered
    ASSERT_NE(it2, prefabs.end());

    // Check if the prefab name is the same.
    ASSERT_EQ(it2->second->GetName(), obj2->GetName());

    // Check if the number of prefabs has increased.
    ASSERT_EQ(prefabs.size(), 2);
}

TEST_F(PrefabTest, GetPrefab)
{
    std::string key1 = "Key1";
    std::string key2 = "Key2";
    auto obj1 = std::make_shared<GameObject>("prefab");

    manager.InsertPrefab(std::pair<std::string, std::shared_ptr<GameObject>>(key1, obj1));
    auto prefab = manager.GetPrefab(key1);
    // Check that the name of the returned prefab is the same.
    ASSERT_EQ(prefab->GetName(), obj1->GetName());

    // Check that it is not the exact same object.
    ASSERT_NE(prefab, obj1);

    // Check that an error is thrown when an invalid key is given.
    ASSERT_THROW(manager.GetPrefab(key2), std::runtime_error);
}

TEST_F(PrefabTest, HasPrefab)
{
    std::string key = "Key";
    auto obj = std::make_shared<GameObject>("Prefab");
    manager.InsertPrefab(std::pair<std::string, std::shared_ptr<GameObject>>(key, obj));

    // Check that a registered prefab is present.
    ASSERT_TRUE(manager.HasPrefab(key));

    // Check that a non-existing prefab is not present.
    ASSERT_FALSE(manager.HasPrefab("Non Existing Key"));
}

TEST_F(PrefabTest, RemovePrefab)
{
    std::string key1 = "Key1";
    std::string key2 = "Key2";
    manager.InsertPrefab(
        std::pair<std::string, std::shared_ptr<GameObject>>(key1, std::make_shared<GameObject>()));
    manager.InsertPrefab(
        std::pair<std::string, std::shared_ptr<GameObject>>(key2, std::make_shared<GameObject>()));

    manager.RemovePrefab(key1);
    auto prefabs = manager.GetPrefabs();

    // Check if the number of prefabs has updated. 2 => 1
    ASSERT_EQ(prefabs.size(), 1);

    // Check that the prefab registered to the key was removed.
    ASSERT_TRUE(prefabs.find(key1) == prefabs.end());

    manager.RemovePrefab("Non Existing Key");
    // Check that removing a non-existent key does nothing.
    ASSERT_EQ(manager.GetPrefabs().size(), 1);
}

TEST_F(PrefabTest, ClearPrefabs)
{
    manager.InsertPrefab(std::pair<std::string, std::shared_ptr<GameObject>>(
        "Key1", std::make_shared<GameObject>()));
    manager.InsertPrefab(std::pair<std::string, std::shared_ptr<GameObject>>(
        "Key2", std::make_shared<GameObject>()));

    // Check that there are prefabs registered.
    ASSERT_EQ(manager.GetPrefabs().size(), 2);

    manager.ClearPrefabs();

    // Check that the prefabs were cleared.
    ASSERT_EQ(manager.GetPrefabs().size(), 0);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}