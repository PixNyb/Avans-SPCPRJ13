/**
 * @file main.cpp
 * @author "Melvin van Bree"
 * @brief Used as a sandbox to test code without have to open up a game.
 * @version 0.1
 * @date 10/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "animation_state.hpp"
#include "animator.hpp"
#include "behaviour_script.hpp"
#include "box_collider.hpp"
#include "camera.hpp"
#include "circle_collider.hpp"
#include "engine.hpp"
#include "graphics_facade.hpp"
#include "scene.hpp"
#include "scene_manager.hpp"
#include "sprite.hpp"
#include "time.hpp"
#include <cfloat>
#include <iostream>
#include <utility>

#include <filesystem>
namespace fs = std::filesystem;

class FPSBehaviourScript : public BehaviourScript
{
  private:
    std::shared_ptr<Text> gameObject;

  public:
    explicit FPSBehaviourScript(std::shared_ptr<Text> gameObject)
        : BehaviourScript(), gameObject(std::move(gameObject))
    {
    }

    void OnUpdate() override
    {
        gameObject->SetText("FPS: " + std::to_string(Engine::GetInstance()->GetFPS()));
    }
};

class AnimationControllerScript : public BehaviourScript
{
  private:
    std::shared_ptr<Animator> animator;
    std::string currentState;
    float timer;

  public:
    explicit AnimationControllerScript(std::shared_ptr<Animator> animator)
        : animator(std::move(animator)), currentState("walking"), timer(0.0f)
    {
    }

    void OnStart() override
    {
        // Set initial state to walking
        animator->SetState("walking");
    }

    void OnUpdate() override
    {
        // Update the timer with the delta time
        timer += Time::GetDeltaTime();

        // Here you can implement your game logic to decide which animation state should be active
        // For example, this could be based on user input, character velocity, or other game state
        // variables

        // Let's say we want to switch states every 2 seconds for demonstration purposes
        if (currentState == "walking" && timer >= 2.0f)
        {
            animator->SetState("jump");
            currentState = "jump";
        }
        else if (currentState == "jump" && timer >= 2.0f)
        {
            animator->SetState("running");
            currentState = "running";
        }
        else if (currentState == "running" && timer >= 2.0f)
        {
            animator->SetState("falling");
            currentState = "falling";
        }
        else if (currentState == "falling" && timer >= 2.0f)
        {
            animator->SetState("laying");
            currentState = "laying";
        }
        else if (currentState == "laying" && timer >= 2.0f)
        {
            animator->SetState("walking");
            currentState = "walking";
        }

        // Reset the timer if it's time to switch states
        if (timer >= 2.0f)
        {
            timer = 0.0f;
        }
    }
};

class TestBehaviourScript : public BehaviourScript
{
  private:
    std::shared_ptr<GameObject> gameObject;
    float ticks = 0;

  public:
    explicit TestBehaviourScript(std::shared_ptr<GameObject> gameObject)
        : BehaviourScript(), gameObject(std::move(gameObject))
    {
    }

    void OnUpdate() override
    {
        float speedPerSecond = 1.5f;

        // Get delta time
        float delta = Time::GetDeltaTime() * Time::TimeScale();

        // Increment ticks with the adjusted speed
        ticks += speedPerSecond * delta;

        if (ticks >= FLT_MAX - 1)
            ticks = 0;

        // Compute oscillation based on time
        float oscillation = std::sin(ticks);

        // Compute new scale using the oscillation
        float newScale = 3 + 2 * oscillation;

        // Update the radius
        auto transform = gameObject->GetTransform();
        gameObject->SetTransform(Transform(transform.position, transform.rotation, newScale));
    }
};

int main(int argc, char *argv[])
{
    std::cout << "Sandbox" << std::endl;

    // Engine
    auto engine = Engine::GetInstance();
    engine->SetFPSLimit(240);
    auto sceneManager = engine->Get<SceneManager>();

    // Graphics
    auto graphicsFacade = engine->Get<IOFacade>();
    graphicsFacade->CreateWindow("Sandbox", 600, 400);
    graphicsFacade->CreateRenderer();

    // Scene
    auto scene = std::make_shared<Scene>();

    // Create animation states
    AnimationState walkingState(0, 5, 0.1f); // Walking frames with a delay of 0.1s between frames
    AnimationState jumpState(6, 8, 0.15f);   // Jumping frames with a delay of 0.15s between frames
    AnimationState runState(9, 13, 0.08f);   // Running frames with a delay of 0.08s between frames
    AnimationState fallState(14, 16, 0.12f); // Falling frames with a delay of 0.12s between frames
    AnimationState layState(17, 19, 0.2f);   // Laying frames with a delay of 0.2s between frames

    // Set up the animator and add states
    auto animator = std::make_shared<Animator>();
    animator->AddState("walking", walkingState);
    animator->AddState("jump", jumpState);
    animator->AddState("running", runState);
    animator->AddState("falling", fallState);
    animator->AddState("laying", layState);

    auto color = Color::white();

    auto boxCollider = std::make_shared<BoxCollider>();
    boxCollider->Height(300);
    boxCollider->Width(250);

    auto boxComponent = std::make_shared<GameObject>();
    boxComponent->SetName("Box");
    boxComponent->AddComponent(boxCollider);
    // TODO: fix points on screen to take up whole screen
    boxComponent->SetTransform(Transform(Point(-100, -200), 0, 1));

    // Create the sprite GameObject and set its parent
    auto sprite = std::make_shared<GameObject>();
    sprite->SetName("Sprite");
    sprite->SetParent(boxComponent);

    // Attach the animator to the sprite
    sprite->AddComponent(animator);
    animator->SetState("walking");
    animator->SetState("jump");

    // Add components to the sprite (e.g., Sprite component)
    auto spriteComponent = std::make_shared<Sprite>();
    spriteComponent->SetSprite(
        "/Users/robinpijnappels/Documents/Projects/04 - Avans Projects/01 - Minor "
        "C++/Project/Avans-SPCPRJ13/poc/sdl-render/assets/lego_spritesheet.png");
    sprite->AddComponent(spriteComponent);

    scene->AddGameObject(boxComponent);
    scene->AddGameObject(sprite);

    // Create the animation controller and attach it to the GameObject
    auto animationController = std::make_shared<AnimationControllerScript>(animator);
    sprite->AddComponent(animationController);

    // Camera
    auto camera = std::make_shared<Camera>();
    camera->SetAspectHeight(500);
    camera->SetAspectWidth(500);
    camera->SetTransform(Transform(Point(0, 0), 0, 1));
    scene->SetCamera(camera);

    // FPS Counter
    auto fpsCounterLabel = std::make_shared<Text>();
    fpsCounterLabel->SetHeight(80);
    fpsCounterLabel->SetWidth(200);
    fpsCounterLabel->SetFontSize(30);
    fpsCounterLabel->SetTextColor(Color::green());
    fpsCounterLabel->SetTransform(Transform(Point(20, 20), 0, 1));

    auto behaviourScriptC = std::make_shared<FPSBehaviourScript>(fpsCounterLabel);
    fpsCounterLabel->AddComponent(behaviourScriptC);
    scene->AddGameObject(fpsCounterLabel);

    sceneManager->SetScene(scene);

    engine->Start();

    return 1;
}