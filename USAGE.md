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

## Level format

Voor het inladen van een level wordt het volgende format aangehouden, dit format is niet definitief.
De waarde die is gezet voor 'prefab' wordt gebruikt om de prefab op te vragen aan de PrefabManager.
Hier worden vervolgens name, tag, active, layer, transform en children nog bij gedefinieert.
In de huidige situatie zijn al deze velden verplicht om in te vullen voor elk GameObject.

```json
{
  "objects": [
    {
      "prefab": "Character",
      "name": "Character1",
      "tag": "character",
      "active": true,
      "layer": 1,
      "transform": {
        "position": {
          "x": 1,
          "y": 1
        },
        "rotation": 0.0,
        "scale": 1.0
      },
      "children": []
    },
    {
      "prefab": "Tree",
      "name": "Tree1",
      "tag": "tree",
      "active": true,
      "layer": 1,
      "transform": {
        "position": {
          "x": 4,
          "y": 1
        },
        "rotation": 0.0,
        "scale": 1.0
      },
      "children": []
    },
    {
      "prefab": "Tree",
      "name": "Tree2",
      "tag": "tree",
      "active": true,
      "layer": 2,
      "transform": {
        "position": {
          "x": 0,
          "y": 6
        },
        "rotation": 0.0,
        "scale": 2.0
      },
      "children": [
        {
          "prefab": "Tree",
          "name": "SubTree",
          "tag": "tree",
          "active": true,
          "layer": 3,
          "transform": {
            "position": {
              "x": 2,
              "y": 7
            },
            "rotation": 0.4,
            "scale": 1.0
          },
          "children": []
        }
      ]
    }
  ]
}
```

## Physics Simulatie Gebruiken

De physics manager is voor de engine het aanspreekpunt om een wereld te starten, aan te passen en te beinvloeden.
De physics manager heeft functies die elk hun doel omschrijven. Hiermee kun je bodies aanmaken, verwijderen, uit- en
aanzetten en beinvloeden met krachten.

```
// Creates the world and populates it with the given gameobjects
void PhysicsManager::CreateWorld(std::vector<std::shared_ptr<GameObject>> gameObjects) {
    physicsFacade.PopulateWorld(std::move(gameObjects));
}

// Simulates the world for 1 step
void PhysicsManager::Step() {
    physicsFacade.Step();
}
```

De CreateWorld functie roep je als eerste aan. Vervolgens kun je de simulatie starten met de Step() functie.
Per aanroep van deze functie zet de wereld 1 stap en beweegt hij de objecten die hij bevat.

## Input Facades

De input facade maakt het mogelijk om naar key en mouse inputs te luisteren, maar ook om acties te maken, binden aan
specifieke inputs (een soort alias) en deze te gebruiken in de game.

```cpp
auto inputFacade = Engine::GetInstance().Get<IInputFacade>();

// We voegen een 'jump' action toe die we kunnen binden aan een input
inputFacade->RegisterAction("jump");

// We binden de spacebar aan de 'jump' action
inputFacade->BindKey(KeyCode::SPACE, "jump");

// We kunnen nu checken of de 'jump' action is geactiveerd
if (inputFacade->GetAction("jump")) {
    // Jump!
}
```

## Contact listeners & Behaviour Scripts

De contactlistener in de physicsfacade zorgt ervoor dat alle contacts worden afgevangen en sturen een signaal naar de
behaviorscripts
dat er een contactmoment is begonnen, eindigt of bezig is. Het enige waar de maker van de behaviorscripts rekening mee
moet houden is
het schrijven van de juiste calls naar de physics manager of andere managers. Hieronder staan de methodes van de
behaviorscripts die aangeroepen worden in de contactlistener

```
void ColliderBehaviorTest::OnTriggerEnter2D(const Collider &collider) {}

void ColliderBehaviorTest::OnTriggerExit2D(const Collider &collider) {}

void ColliderBehaviorTest::OnTriggerStay2D(const Collider &collider) {}
```