#include "game_object.hpp"
#include "game_object_utility.hpp"
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
    std::shared_ptr<GameObject> child = std::make_shared<GameObject>("TestObject");
    child->SetParent(parent);
    ASSERT_EQ(child->GetParent(), parent);
}

TEST(GameObjectTest, TestParents)
{
    std::shared_ptr<GameObject> root = std::make_shared<GameObject>("Root");
    std::shared_ptr<GameObject> child = std::make_shared<GameObject>("Child");
    std::shared_ptr<GameObject> grandChild = std::make_shared<GameObject>("GrandChild");

    child->SetParent(root);
    grandChild->SetParent(child);

    ASSERT_EQ(grandChild->GetParent(), child);
    ASSERT_EQ(child->GetParent(), root);
    ASSERT_EQ(root->GetParent(), nullptr);
}

TEST(GameObjectTest, TestParents_NewParentsDeleteChildrenOfOriginalParent)
{
    std::shared_ptr<GameObject> root = std::make_shared<GameObject>("Root");
    std::shared_ptr<GameObject> rootB = std::make_shared<GameObject>("RootB");

    std::shared_ptr<GameObject> child = std::make_shared<GameObject>("ChildA");

    child->SetParent(root);

    auto rootChildrenA = root->GetChildren();
    bool rootHasChildA =
        std::find(rootChildrenA.begin(), rootChildrenA.end(), child) != rootChildrenA.end();
    ASSERT_EQ(rootHasChildA, true);

    child->SetParent(rootB);

    auto rootChildrenB = root->GetChildren();
    bool rootHasChildB =
        std::find(rootChildrenB.begin(), rootChildrenB.end(), child) != rootChildrenB.end();
    ASSERT_EQ(rootHasChildB, false);
}

TEST(GameObjectTest,
     TestGameObjectUtil_ProcessActiveObjectsRecursively_InactiveChildCannotFindGrandChild)
{
    std::shared_ptr<GameObject> root = std::make_shared<GameObject>("Root");
    std::shared_ptr<GameObject> child = std::make_shared<GameObject>("Child");
    std::shared_ptr<GameObject> grandChild = std::make_shared<GameObject>("GrandChild");

    child->SetParent(root);
    grandChild->SetParent(child);

    child->SetActive(false);

    bool foundGrandChild = false;
    GameObjectUtility::TraverseActiveGameObjects(
        root,
        [&foundGrandChild](const std::shared_ptr<GameObject> &gameObject)
        {
            if (gameObject->GetName() == "GrandChild")
                foundGrandChild = true;
        });

    ASSERT_EQ(foundGrandChild, false);
}

TEST(GameObjectTest,
     TestGameObjectUtil_ProcessActiveObjectsRecursively_ActiveChildCanFindGrandChild)
{
    std::shared_ptr<GameObject> root = std::make_shared<GameObject>("Root");
    std::shared_ptr<GameObject> child = std::make_shared<GameObject>("Child");
    std::shared_ptr<GameObject> grandChild = std::make_shared<GameObject>("GrandChild");

    child->SetParent(root);
    grandChild->SetParent(child);

    bool foundGrandChild = false;
    GameObjectUtility::TraverseActiveGameObjects(
        root,
        [&foundGrandChild](const std::shared_ptr<GameObject> &gameObject)
        {
            if (gameObject->GetName() == "GrandChild")
                foundGrandChild = true;
        });

    ASSERT_EQ(foundGrandChild, true);
}

// TODO: Unfinished test currently fails, either finish the test or remove it.
// TEST(GameObjectTest, TestAddComponent)
//{
//    std::shared_ptr<Component> component = std::make_shared<Component>();
//    GameObject obj("TestObject");
//    obj.AddComponent(component);
// Here you should test if the component was added correctly
// This depends on how you implemented the AddComponent method
//}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}