#include "prefab_manager.hpp"
#include <gtest/gtest.h>

class PrefabManagerStub : public PrefabManager {
  public:
    // The PrefabManagerStub allows for full access to the stored prefabs.
    std::map<std::string, GameObject> GetPrefabs() {
        return this->prefabs;
    }

    void InsertPrefab(std::pair<std::string, GameObject> value)
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
    // Not testing with multiple properties, then it would become a test for the clone functionality.
    GameObject obj1("Prefab1");
    manager.RegisterPrefab(key1, obj1);

    std::map<std::string, GameObject> prefabs = manager.GetPrefabs();
    auto it1 = prefabs.find(key1);

    // Check if key was registered
    ASSERT_NE(it1, prefabs.end());

    // Check if the prefab name is the same.
    ASSERT_EQ(it1->second.GetName(), obj1.GetName());

    GameObject obj2("Prefab2");
    manager.RegisterPrefab(key2, obj2);

    prefabs = manager.GetPrefabs(); // Update the prefabs.
    auto it2 = prefabs.find(key2);

    // Check if key was registered
    ASSERT_NE(it2, prefabs.end());

    // Check if the prefab name is the same.
    ASSERT_EQ(it2->second.GetName(), obj2.GetName());

    // Check if the number of prefabs has increased.
    ASSERT_EQ(prefabs.size(), 2);
}

TEST_F(PrefabTest, GetPrefab)
{
    std::string key1 = "Key1";
    std::string key2 = "Key2";
    GameObject obj1("prefab");

    manager.InsertPrefab(std::pair<std::string, GameObject>(key1, obj1));
    manager.GetPrefab(key1); // TODO: Check why it cannot be used as a value.

    ASSERT_THROW(manager.GetPrefab(key2), std::runtime_error);
}

TEST_F(PrefabTest, HasPrefab)
{
    std::string key = "Key";
    GameObject obj("Prefab");
    manager.RegisterPrefab(key, obj);

    ASSERT_TRUE(manager.HasPrefab(key));

    ASSERT_FALSE(manager.HasPrefab("Non Existing Key"));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}