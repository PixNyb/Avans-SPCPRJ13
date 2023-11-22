#include "sdl_input_facade.hpp"
#include "gtest/gtest.h"
#include <SDL.h>
#include <atomic>
#include <string>
#include <thread>

class SDLInputFacadeTest : public ::testing::Test
{
  public:
    SDLInputFacadeTest() : sdlInputFacade() {}
    std::atomic<bool> running = true;
    std::thread t;

    void SetUp() override
    {
        SDL_Init(SDL_INIT_EVENTS);
        t = std::thread(&SDLInputFacadeTest::Loop, this);
    }

    void Loop()
    {
        while (running)
            sdlInputFacade.Update();
    }

    void TearDown() override
    {
        running = false;
        t.join();
    }

    void MockKey(KeyCode keyCode, bool pressed)
    {
        SDL_Event event;

        event.type = pressed ? SDL_KEYDOWN : SDL_KEYUP;
        event.key.keysym.scancode = static_cast<SDL_Scancode>(keyCode);

        SDL_PushEvent(&event);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    void MockMouseClick(MouseButton mouseButton, bool pressed)
    {
        SDL_Event event;

        event.type = pressed ? SDL_MOUSEBUTTONDOWN : SDL_MOUSEBUTTONUP;
        event.button.button = static_cast<Uint8>(mouseButton);

        SDL_PushEvent(&event);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    void MockMouseMove(int x, int y)
    {
        SDL_Event event;

        event.type = SDL_MOUSEMOTION;
        event.motion.x = x;
        event.motion.y = y;

        SDL_PushEvent(&event);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

  protected:
    SDLInputFacade sdlInputFacade;
};

TEST_F(SDLInputFacadeTest, TestAnyKey)
{
    auto key = KeyCode::A;

    MockKey(key, false);
    EXPECT_EQ(sdlInputFacade.AnyKey(), false);

    MockKey(key, true);
    EXPECT_EQ(sdlInputFacade.AnyKey(), true);

    MockKey(key, false);
    EXPECT_EQ(sdlInputFacade.AnyKey(), false);
}

TEST_F(SDLInputFacadeTest, TestGetMousePosition)
{
    MockMouseMove(0, 0);
    EXPECT_EQ(sdlInputFacade.GetMousePosition(), Point(0, 0));

    MockMouseMove(10, 20);
    EXPECT_EQ(sdlInputFacade.GetMousePosition(), Point(10, 20));
}

TEST_F(SDLInputFacadeTest, TestGetAxis) { EXPECT_EQ(sdlInputFacade.GetAxis(), 0.0); }

TEST_F(SDLInputFacadeTest, TestGetKey)
{
    auto key = KeyCode::A;
    auto key2 = KeyCode::B;

    MockKey(key, false);
    MockKey(key2, false);
    EXPECT_EQ(sdlInputFacade.GetKey(KeyCode::A), false);
    EXPECT_EQ(sdlInputFacade.GetKey(KeyCode::B), false);
    EXPECT_EQ(sdlInputFacade.AnyKey(), false);

    MockKey(key, true);
    EXPECT_EQ(sdlInputFacade.GetKey(KeyCode::A), true);
    EXPECT_EQ(sdlInputFacade.GetKey(KeyCode::B), false);
    EXPECT_EQ(sdlInputFacade.AnyKey(), true);

    MockKey(key, false);
    EXPECT_EQ(sdlInputFacade.GetKey(KeyCode::A), false);
    EXPECT_EQ(sdlInputFacade.GetKey(KeyCode::B), false);
    EXPECT_EQ(sdlInputFacade.AnyKey(), false);

    MockKey(key2, true);
    EXPECT_EQ(sdlInputFacade.GetKey(KeyCode::A), false);
    EXPECT_EQ(sdlInputFacade.GetKey(KeyCode::B), true);
    EXPECT_EQ(sdlInputFacade.AnyKey(), true);
}

TEST_F(SDLInputFacadeTest, TestGetMouseButton)
{
    auto mouseButton = MouseButton::LEFT;

    MockMouseClick(mouseButton, false);
    EXPECT_EQ(sdlInputFacade.GetMouseButton(MouseButton::LEFT), false);

    MockMouseClick(mouseButton, true);
    EXPECT_EQ(sdlInputFacade.GetMouseButton(MouseButton::LEFT), true);

    MockMouseClick(mouseButton, false);
    EXPECT_EQ(sdlInputFacade.GetMouseButton(MouseButton::LEFT), false);
}

TEST_F(SDLInputFacadeTest, TestRegisterAction)
{
    auto action = std::string("action");

    EXPECT_NO_THROW(sdlInputFacade.RegisterAction(action));
    EXPECT_THROW(sdlInputFacade.RegisterAction(action), std::runtime_error);

    sdlInputFacade.UnregisterAction(action);
}

TEST_F(SDLInputFacadeTest, TestUnregisterAction)
{
    auto action = std::string("action");

    EXPECT_NO_THROW(sdlInputFacade.RegisterAction(action));
    EXPECT_NO_THROW(sdlInputFacade.UnregisterAction(action));
    EXPECT_THROW(sdlInputFacade.UnregisterAction(action), std::runtime_error);
}

TEST_F(SDLInputFacadeTest, TestGetActions)
{
    auto action = std::string("action");

    EXPECT_NO_THROW(sdlInputFacade.RegisterAction(action));
    EXPECT_EQ(sdlInputFacade.GetActions().size(), 1);
    EXPECT_EQ(sdlInputFacade.GetActions()[0], action);

    sdlInputFacade.UnregisterAction(action);
}

TEST_F(SDLInputFacadeTest, TestBindKey)
{
    auto action = std::string("action");
    auto action2 = std::string("action2");

    EXPECT_THROW(sdlInputFacade.BindKey(KeyCode::A, action), std::runtime_error);

    EXPECT_NO_THROW(sdlInputFacade.RegisterAction(action));
    EXPECT_NO_THROW(sdlInputFacade.BindKey(KeyCode::A, action));
    EXPECT_THROW(sdlInputFacade.BindKey(KeyCode::A, action), std::runtime_error);

    EXPECT_NO_THROW(sdlInputFacade.RegisterAction(action2));
    EXPECT_NO_THROW(sdlInputFacade.BindKey(KeyCode::B, action2));
    EXPECT_THROW(sdlInputFacade.BindKey(KeyCode::B, action2), std::runtime_error);
    EXPECT_THROW(sdlInputFacade.BindKey(KeyCode::B, action), std::runtime_error);

    sdlInputFacade.UnregisterAction(action);
    sdlInputFacade.UnregisterAction(action2);
}

TEST_F(SDLInputFacadeTest, TestUnbindKey)
{
    auto action = std::string("action");

    EXPECT_NO_THROW(sdlInputFacade.RegisterAction(action));
    EXPECT_NO_THROW(sdlInputFacade.BindKey(KeyCode::A, action));
    EXPECT_NO_THROW(sdlInputFacade.UnbindKey(KeyCode::A));
    EXPECT_THROW(sdlInputFacade.UnbindKey(KeyCode::A), std::runtime_error);

    sdlInputFacade.UnregisterAction(action);
}

TEST_F(SDLInputFacadeTest, TestBindMouseButton)
{
    auto action = std::string("action");
    auto action2 = std::string("action2");

    EXPECT_THROW(sdlInputFacade.BindMouseButton(MouseButton::LEFT, action), std::runtime_error);

    EXPECT_NO_THROW(sdlInputFacade.RegisterAction(action));
    EXPECT_NO_THROW(sdlInputFacade.BindMouseButton(MouseButton::LEFT, action));
    EXPECT_THROW(sdlInputFacade.BindMouseButton(MouseButton::LEFT, action), std::runtime_error);

    EXPECT_NO_THROW(sdlInputFacade.RegisterAction(action2));
    EXPECT_NO_THROW(sdlInputFacade.BindMouseButton(MouseButton::RIGHT, action2));
    EXPECT_THROW(sdlInputFacade.BindMouseButton(MouseButton::RIGHT, action2), std::runtime_error);
    EXPECT_THROW(sdlInputFacade.BindMouseButton(MouseButton::RIGHT, action), std::runtime_error);

    sdlInputFacade.UnregisterAction(action);
    sdlInputFacade.UnregisterAction(action2);
}

TEST_F(SDLInputFacadeTest, TestUnbindMouseButton)
{
    auto action = std::string("action");

    EXPECT_NO_THROW(sdlInputFacade.RegisterAction(action));
    EXPECT_NO_THROW(sdlInputFacade.BindMouseButton(MouseButton::LEFT, action));
    EXPECT_NO_THROW(sdlInputFacade.UnbindMouseButton(MouseButton::LEFT));
    EXPECT_THROW(sdlInputFacade.UnbindMouseButton(MouseButton::LEFT), std::runtime_error);

    sdlInputFacade.UnregisterAction(action);
}

TEST_F(SDLInputFacadeTest, TestGetActionForKey)
{
    auto action = std::string("action");

    EXPECT_NO_THROW(sdlInputFacade.RegisterAction(action));
    EXPECT_NO_THROW(sdlInputFacade.BindKey(KeyCode::A, action));
    EXPECT_EQ(sdlInputFacade.GetActionForKey(KeyCode::A), action);
    EXPECT_THROW(sdlInputFacade.GetActionForKey(KeyCode::B), std::runtime_error);

    sdlInputFacade.UnregisterAction(action);
}

TEST_F(SDLInputFacadeTest, TestGetActionForMouseButton)
{
    auto action = std::string("action");

    EXPECT_NO_THROW(sdlInputFacade.RegisterAction(action));
    EXPECT_NO_THROW(sdlInputFacade.BindMouseButton(MouseButton::LEFT, action));
    EXPECT_EQ(sdlInputFacade.GetActionForMouseButton(MouseButton::LEFT), action);
    EXPECT_THROW(sdlInputFacade.GetActionForMouseButton(MouseButton::RIGHT), std::runtime_error);

    sdlInputFacade.UnregisterAction(action);
}

TEST_F(SDLInputFacadeTest, TestAnyAction)
{
    auto action = std::string("action");
    auto action2 = std::string("action2");

    EXPECT_NO_THROW(sdlInputFacade.RegisterAction(action));
    EXPECT_NO_THROW(sdlInputFacade.RegisterAction(action2));
    EXPECT_EQ(sdlInputFacade.AnyAction(), false);

    EXPECT_NO_THROW(sdlInputFacade.BindKey(KeyCode::A, action));
    EXPECT_NO_THROW(sdlInputFacade.BindMouseButton(MouseButton::LEFT, action2));
    EXPECT_EQ(sdlInputFacade.AnyAction(), false);

    MockKey(KeyCode::A, true);
    MockMouseClick(MouseButton::LEFT, true);
    EXPECT_EQ(sdlInputFacade.AnyAction(), true);

    MockKey(KeyCode::A, false);
    MockMouseClick(MouseButton::LEFT, false);
    EXPECT_EQ(sdlInputFacade.AnyAction(), false);

    MockKey(KeyCode::A, false);
    MockMouseClick(MouseButton::LEFT, true);
    EXPECT_EQ(sdlInputFacade.AnyAction(), true);

    sdlInputFacade.UnregisterAction(action);
}

TEST_F(SDLInputFacadeTest, TestGetAction)
{
    auto action = std::string("action");
    auto action2 = std::string("action2");

    EXPECT_NO_THROW(sdlInputFacade.RegisterAction(action));
    EXPECT_NO_THROW(sdlInputFacade.RegisterAction(action2));
    EXPECT_EQ(sdlInputFacade.GetAction(action), false);
    EXPECT_EQ(sdlInputFacade.GetAction(action2), false);

    EXPECT_NO_THROW(sdlInputFacade.BindKey(KeyCode::A, action));
    EXPECT_NO_THROW(sdlInputFacade.BindMouseButton(MouseButton::LEFT, action2));
    EXPECT_EQ(sdlInputFacade.GetAction(action), false);
    EXPECT_EQ(sdlInputFacade.GetAction(action2), false);

    MockKey(KeyCode::A, true);
    MockMouseClick(MouseButton::LEFT, true);
    EXPECT_EQ(sdlInputFacade.GetAction(action), true);
    EXPECT_EQ(sdlInputFacade.GetAction(action2), true);

    MockKey(KeyCode::A, false);
    MockMouseClick(MouseButton::LEFT, false);
    EXPECT_EQ(sdlInputFacade.GetAction(action), false);
    EXPECT_EQ(sdlInputFacade.GetAction(action2), false);

    sdlInputFacade.UnregisterAction(action);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}