#include "button_factory.hpp"
#include "gtest/gtest.h"

TEST(ButtonFactoryTest, TestButtonFactory)
{
    bool clicked = false;
    const float width = 100.0f;
    const float height = 100.0f;
    const int fontSize = 10;
    const std::string buttonText = "Button click";

    std::shared_ptr<Button> button =
        ButtonFactory::CreateButton(width, height, fontSize, buttonText);

    ASSERT_TRUE(button != nullptr);
    EXPECT_EQ(button->GetWidth(), width);
    EXPECT_EQ(button->GetHeight(), height);
    EXPECT_EQ(button->GetTag(), buttonText);

    button->OnClick([&clicked]() { clicked = true; });

    auto clickListener = std::make_shared<ButtonClickListener>(*button);
    clickListener->Attach();
    clickListener->OnMouseClicked();
    clickListener->Detach();

    EXPECT_TRUE(clicked);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}