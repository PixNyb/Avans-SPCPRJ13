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

#include "behaviour_script.hpp"
#include "box_collider.hpp"
#include "camera.hpp"
#include "circle_collider.hpp"
#include "engine.hpp"
#include "graphics_facade.hpp"
#include "scene.hpp"
#include "scene_manager.hpp"
#include "time.hpp"
#include "sprite.hpp"
#include "animation_state.hpp"
#include "animator.hpp"
#include <cfloat>
#include <iostream>
#include <utility>


#include <filesystem>
namespace fs = std::filesystem;

class FPSBehaviourScript: public BehaviourScript {
    private:
    std::shared_ptr<Text> gameObject;
    public:
    explicit FPSBehaviourScript(std::shared_ptr<Text> gameObject): BehaviourScript(),
                                                                             gameObject
                                                                            (std::move(gameObject)) {
    }

    void OnUpdate() override
    {
        gameObject->SetText("FPS: " + std::to_string(Engine::GetInstance()->GetFPS()));
    }
};

class TestBehaviourScript : public BehaviourScript {
  private:
    std::shared_ptr<GameObject> gameObject;
    float ticks = 0;
  public:

    explicit TestBehaviourScript(std::shared_ptr<GameObject> gameObject): BehaviourScript(),
                                                                           gameObject
                                                                          (std::move(gameObject)) {
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
    AnimationState idleState(10, 0.1f);  // Example: 10 frames, each shown for 0.1 seconds
    AnimationState runningState(10, 0.05f);

    // Set up the animator and add states
    auto animator = std::make_shared<Animator>();
    animator->AddState("idle", idleState);
    animator->AddState("running", runningState);

    // Attach the animator to a game object
//    auto player = scene->CreateGameObject().lock();
//    player->SetName("Player");
//    player->AddComponent(animator);
//    animator->SetState("idle");

    auto boxCollider = std::make_shared<BoxCollider>();
    boxCollider->Height(40);
    boxCollider->Width(40);

    auto boxComponent = std::make_shared<GameObject>();
    boxComponent->SetName("Box");
    boxComponent->AddComponent(boxCollider);
    boxComponent->SetTransform(Transform(Point(0,0),0, 1));

    // Create the sprite GameObject and set its parent
    auto sprite = std::make_shared<GameObject>();
    sprite->SetName("Sprite");
    sprite->SetParent(boxComponent);

    // Add components to the sprite (e.g., Sprite component)
    auto spriteComponent = std::make_shared<Sprite>();
    spriteComponent->SetSprite("/Users/robinpijnappels/Documents/Projects/04 - Avans Projects/01 - Minor C++/Project/Avans-SPCPRJ13/sandbox/menu_final.png");
    sprite->AddComponent(spriteComponent);

    scene->AddGameObject(boxComponent);
    scene->AddGameObject(sprite);


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