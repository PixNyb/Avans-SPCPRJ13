#include "game_object.hpp"
#include "gtest/gtest.h"

TEST(GameObjectTest, TestName)
{
    GameObject obj("TestObject");
    ASSERT_EQ(obj.GetName(), "TestObject");
    obj.SetName("NewName");
    ASSERT_EQ(obj.GetName(), "NewName");
}

TEST(GameObjectTest, TestTag)
{
    GameObject obj("TestObject");
    obj.SetTag("TestTag");
    ASSERT_EQ(obj.GetTag(), "TestTag");
}

TEST(GameObjectTest, TestLayer)
{
    GameObject obj("TestObject");
    obj.SetLayer(1);
    ASSERT_EQ(obj.GetLayer(), 1);
}

TEST(GameObjectTest, TestTransform)
{
    GameObject obj("TestObject");
    Transform t;
    obj.SetTransform(t);
    auto transform = obj.GetTransform();
    ASSERT_EQ(transform.position.x, 0);
    ASSERT_EQ(transform.position.y, 0);
    ASSERT_EQ(transform.rotation, 0);
    ASSERT_EQ(transform.scale, 1);
}

TEST(GameObjectTest, TestActive)
{
    GameObject obj("TestObject");
    obj.SetActive(true);
    ASSERT_EQ(obj.IsActive(), true);
    obj.SetActive(false);
    ASSERT_EQ(obj.IsActive(), false);
}

TEST(GameObjectTest, TestParent)
{
    std::shared_ptr<GameObject> parent = std::make_shared<GameObject>("ParentObject");
    GameObject obj("TestObject");
    obj.SetParent(parent);
    ASSERT_EQ(obj.GetParent(), parent);
}

TEST(GameObjectTest, TestAddComponent)
{
    std::shared_ptr<Component> component = std::make_shared<Component>();
    GameObject obj("TestObject");
    obj.AddComponent(component);
    // Here you should test if the component was added correctly
    // This depends on how you implemented the AddComponent method
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}