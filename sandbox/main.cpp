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
#include <cfloat>
#include <iostream>
#include <utility>

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
    graphicsFacade->CreateWindow("Sandbox", 500, 500);
    graphicsFacade->CreateRenderer();

    // Scene
    auto scene = std::make_shared<Scene>();

    // Prepare all components
    auto component = std::make_shared<CircleCollider>();
    component->Radius(30);
    auto boxComponent = std::make_shared<BoxCollider>();
    boxComponent->Width(30);
    boxComponent->Height(30);

    // Circle
    auto obj = scene->CreateGameObject().lock();
    obj->SetName("circle");
    obj->AddComponent(component);
    obj->SetTransform(Transform(Point(0,0), 0, 1));

    // Box
    auto obj2 = scene->CreateGameObject().lock();
    obj2->SetName("box");
    obj2->AddComponent(boxComponent);
    obj2->SetTransform(Transform(Point(0,0), 0, 1));

    // Scaling behaviour scripts
    auto behaviourScript = std::make_shared<TestBehaviourScript>(obj);
    obj->AddComponent(behaviourScript);

    auto behaviourScriptB = std::make_shared<TestBehaviourScript>(obj2);
    obj2->AddComponent(behaviourScriptB);

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