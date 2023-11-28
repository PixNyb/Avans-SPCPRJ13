# Hoe de Engine te gebruiken?

In dit bestand staat uitgebreide documentatie over het gebruik van de DeFunBobEngine game engine.

## Window aanmaken

Voor het aanmaken van een window moeten we eerst zorgen dat de Engine klasse is geintialiseerd,
vanuit daar kunnen we de GraphicsFacade aanroepen om een Window aan te maken. Daarna moet je ook een Render aanmaken
waaraan content toegevoegd kan worden.

Voorbeeld:

```cpp
// Engine
auto engine = Engine::GetInstance();
engine->SetFPSLimit(240);
auto sceneManager = engine->Get<SceneManager>();

// Graphics
auto graphicsFacade = engine->Get<IOFacade>();
graphicsFacade->CreateWindow("Sandbox", 600, 400);
graphicsFacade->CreateRenderer();
```

## Sprites aanmaken en renderen

Voor het aanmaken van een sprite moet je Sprite component aanmaken, deze kun je daarna toeveoegen aan een gameobject.

Voorbeeld:

```cpp
auto boxComponent = std::make_shared<GameObject>();
boxComponent->SetName("Box");
boxComponent->AddComponent(boxCollider);
boxComponent->SetTransform(Transform(Point(0, 0), 0, 1));
    
auto sprite = std::make_shared<GameObject>();
sprite->SetName("Sprite");
sprite->SetParent(boxComponent);
    
auto spriteComponent = std::make_shared<Sprite>();
spriteComponent->SetSprite("lego_spritesheet.png");
sprite->AddComponent(spriteComponent);
```

Om een spritesheet te gebruiken moet je eerst een spritesheet aanmaken, dit door gebruik te maken van de Animator met de
AnimationStates.
Daarna kun je een behaviour script aanmaken waarin je de animator aanroept om de juiste state te switchen.

Zie hieronder een voorbeeld:

```cpp
// Create animation states
AnimationState walkingState(0, 5, 0.1f); // Walking frames with a delay of 0.1s between frames
AnimationState jumpState(6, 8, 0.15f);   // Jumping frames with a delay of 0.15s between frames
AnimationState runState(9, 13, 0.08f);   // Running frames with a delay of 0.08s between frames

// Set up the animator and add states
auto animator = std::make_shared<Animator>();
animator->AddState("walking", walkingState);
animator->AddState("jump", jumpState);
animator->AddState("running", runState);

// Create the animation controller and attach it to the GameObject
auto animationController = std::make_shared<AnimationControllerScript>(animator);
sprite->AddComponent(animationController);
```