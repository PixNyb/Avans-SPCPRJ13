#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "engine.hpp"
#include "i_input_facade.hpp"
#include "input_facade.hpp"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

class MockSDLInputFacade : public SDLInputFacade {
  public:
    MockSDLInputFacade(std::unique_ptr<IInputFacade> inputHandler) : SDLInputFacade() {}

    MOCK_METHOD0(Update, void());

    MOCK_METHOD0(UpdateKeyEvents, void());

    MOCK_METHOD0(UpdateMouseEvents, void());

    MOCK_METHOD1(RegisterMouseListener, void(std::unique_ptr<IMouseListener>));

    MOCK_METHOD1(RegisterKeyListener, void(std::unique_ptr<IKeyListener>));

    MOCK_CONST_METHOD1(ActionPressed, bool(const ActionType&));

    MOCK_CONST_METHOD1(ActionReleased, bool(const ActionType&));

    MOCK_METHOD2(Bind, void(const Event&, const ActionType&));
};

class SDLInputFacadeTest : public testing::Test {
  protected:
    std::unique_ptr<MockSDLInputFacade> mockInputFacade;

    void SetUp() override {
        mockInputFacade = std::make_unique<MockSDLInputFacade>();
    }
};

TEST(SDLInputFacadeTest, KeyPressEventHandled) {
    // Set expectations
    EXPECT_CALL(*mockInputFacade, Bind(testing::_, ActionType::JUMP)).Times(1);
    EXPECT_CALL(*mockInputFacade, ActionPressed(ActionType::JUMP)).WillOnce(testing::Return(true));

    // Verify expectations
    testing::Mock::VerifyAndClearExpectations(mockInputFacade.get());
}

TEST(SDLInputFacadeTest, MousePressEventHandled) {
    // Set expectations
    EXPECT_CALL(*mockInputFacade, Bind(testing::_, ActionType::PAUSE)).Times(1);
    EXPECT_CALL(*mockInputFacade, ActionPressed(ActionType::PAUSE)).WillOnce(testing::Return(true));

    // Simulate mouse press
    SimulateMousePress(KeyCode::MOUSE_LEFT);

    // Verify expectations
    testing::Mock::VerifyAndClearExpectations(mockInputFacade.get());
}

int main(int argc, char *argv[])
{
    // Initialize Google Test
    testing::InitGoogleTest(&argc, argv);

    // Run the tests
    return RUN_ALL_TESTS();
}