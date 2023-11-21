#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "mouse_listener.hpp"
#include "key_listener.hpp"

class IInputFacade {
  public:
    virtual ~IInputFacade() = default;

    virtual void Update() = 0;
    virtual void RegisterMouseListener(std::unique_ptr<MouseListener> mouseListener) = 0;
    virtual void RegisterKeyListener(std::unique_ptr<KeyListener> keyListener) = 0;
    virtual bool ActionPressed(const ActionType &actionType) const = 0;
    virtual bool ActionReleased(const ActionType &actionType) const = 0;
    virtual void Bind(const Event &key, const ActionType &actionType) = 0;
};

class MockInputFacade : public IInputFacade {
  public:
    MOCK_METHOD(void, Update, (), (override));
    MOCK_METHOD(void, RegisterMouseListener, (std::unique_ptr<MouseListener>), (override));
    MOCK_METHOD(void, RegisterKeyListener, (std::unique_ptr<KeyListener>), (override));
    MOCK_METHOD(bool, ActionPressed, (const ActionType &), (const, override));
    MOCK_METHOD(bool, ActionReleased, (const ActionType &), (const, override));
    MOCK_METHOD(void, Bind, (const Event &, const ActionType &), (override));
};

class IInputFacadeTest : public testing::Test {
  protected:
    std::unique_ptr<MockInputFacade> mockInputFacade;

    void SetUp() override {
        mockInputFacade = std::make_unique<MockInputFacade>();
    }
};

TEST_F(IInputFacadeTest, BindTest) {
    auto mockKeyEvent = KeyEvent(KeyCode::UP_ARROW, EventType::KEYPRESSED);

//    EXPECT_CALL(*mockInputFacade, Bind(*mockKeyEvent, ActionType::PAUSE)).Times(1);

    mockInputFacade->Bind(mockKeyEvent, ActionType::JUMP);
}

TEST_F(IInputFacadeTest, UpdateTest) {
    EXPECT_CALL(*mockInputFacade, Update()).Times(1);
    mockInputFacade->Update();
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
};