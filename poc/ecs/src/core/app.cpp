#include "app.h"
#include "position.h"
#include "box.h"
#include "input.h"
#include "movement_system.h"
#include "input_manager.h"
#include "player_control_system.h"
#include "game_object.h"
#include "render_system.h"
#include "scene_system.h"

App::App() {
    _window = nullptr;
    _renderer = nullptr;
    _screenHeight = SCREEN_HEIGHT;
    _screenWidth = SCREEN_WIDTH;
    _state = AppState::PAUSED;
    _primary_registry = entt::registry {};
}

App::~App() {
    _window = nullptr;
    _renderer = nullptr;
    _state = AppState::EXIT;
}

void App::start() {
    initSystems();
    test();
    _state = AppState::RUNNING;

    unsigned int previousTime = SDL_GetTicks();
    unsigned int currentTime;
    unsigned int elapsedTime;
    float deltaTime;

    // TODO: Move into some settings thing
    const int TARGET_FPS = 240;
    const int FRAME_DURATION = 1000 / TARGET_FPS;

    while(_state == AppState::RUNNING){
        currentTime = SDL_GetTicks();
        elapsedTime = currentTime - previousTime;
        deltaTime = (float)elapsedTime / 1000.0f;

        if (elapsedTime < FRAME_DURATION)
            SDL_Delay(FRAME_DURATION - elapsedTime);

        // Input events
        InputManager::poll();
        if (InputManager::hasQuit()) _state = AppState::EXIT;

        update(deltaTime);

        previousTime = currentTime;
    }
}

void App::initSystems() {
    SDL_Init(SDL_INIT_EVERYTHING);
    _window = SDL_CreateWindow("App", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);

    // TODO: Do some checking and error handling

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

    auto sys = std::make_shared<SceneSystem>();
    _primary_registry.ctx().emplace<std::shared_ptr<SceneSystem>>(sys);

    _systems.push_back(new PlayerControlSystem());
    _systems.push_back(new MovementSystem());
}

// Meant to test entities
void App::test() {

//    // Prepare entities
    auto entity = _primary_registry.create();

    _primary_registry.emplace<InputComponent>(entity);
    _primary_registry.emplace<PositionComponent>(entity, Position2D { 50, 50 });
    _primary_registry.emplace<Box2DComponent>(entity, Box2DComponent { 50, 50 });

    auto entityB = _primary_registry.create();

//    _primary_registry.emplace<InputComponent>(entityB);
    _primary_registry.emplace<PositionComponent>(entityB, Position2D { 100, 100 });
    _primary_registry.emplace<Box2DComponent>(entityB, Box2DComponent { 50, 50 });

    auto entityC = _primary_registry.create();

    _primary_registry.emplace<InputComponent>(entityC);
    _primary_registry.emplace<PositionComponent>(entityC, Position2D { 300, 150 });
    _primary_registry.emplace<Box2DComponent>(entityC, Box2DComponent { 75, 25 });
}

void App::update(float delta) {
    for (auto system : _systems) {
        system->onUpdate(_primary_registry, delta);
    }

    RenderSystem::beginRenderingCycle(*_renderer);
    RenderSystem::render(*_renderer, _primary_registry);
    RenderSystem::endRenderingCycle(*_renderer);
}