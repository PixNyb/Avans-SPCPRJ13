# Hoe de Engine te gebruiken?

In dit bestand staat uitgebreide documentatie over het gebruik van de DeFunBobEngine game engine.

## Inhoudsopgave

- [Hoe de Engine te gebruiken?](#hoe-de-engine-te-gebruiken)
  - [Inhoudsopgave](#inhoudsopgave)
  - [1. Window aanmaken](#1-window-aanmaken)
  - [Sprites aanmaken en renderen](#sprites-aanmaken-en-renderen)
  - [3. Level format](#3-level-format)
  - [4. Physics Simulatie Gebruiken](#4-physics-simulatie-gebruiken)
  - [5. Input Facades](#5-input-facades)
  - [6. Contact listeners \& Behaviour Scripts](#6-contact-listeners--behaviour-scripts)
  - [7. HUD (Head-Up Display) aanmaken](#7-hud-head-up-display-aanmaken)
  - [8. Pathfinding](#8-pathfinding)

## 1. Window aanmaken

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

## 2. Prefabs gebruiken

De PrefabManager kan gebruikt worden om prefabs te registeren en op te halen.

```cpp
void RegisterPrefab(const std::string &id, const GameObject &prefab);
```

Door middel van de functie RegisterPrefab kan er een nieuw GameObject als prefab geregistreert worden.
Hierbij dient er ook een uniek id meegegeven te worden zodat dit later bij het laden van een level opgevraagd kan
worden.

```cpp
std::shared_ptr<GameObject> GetPrefab(std::string id);
```

Om vervolgens een prefab weer op te halen kan er gebruik gemaakt worden van de GetPrefab functie.
Hieraan wordt een id meegegeven om de prefab te specificeren. Er wordt hier een nieuwe copy van het GameObject
teruggegeven.

## 3. Level format

Voor het inladen van een level wordt het volgende format aangehouden, dit format is niet definitief.
Eerst wordt camera gedefinieerd, hierbij wordt een width en height meegegeven.
Vervolgens worden alle GameObjecten geplaatst in de objects array.
De waarde die is gezet voor 'prefab' wordt gebruikt om de prefab op te vragen aan de PrefabManager.
Hier worden vervolgens name, active, layer, transform en children nog bij gedefinieert.
In de huidige situatie zijn al deze velden verplicht om in te vullen voor elk GameObject.

```json
{
  "camera": {
    "width": 500,
    "height": 500
  },
  "objects": [
    {
      "prefab": "Character",
      "name": "Character1",
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

## 4. Physics Simulatie Gebruiken

De physics manager is voor de engine het aanspreekpunt om een wereld te starten, aan te passen en te beinvloeden.
De physics manager heeft functies die elk hun doel omschrijven. Hiermee kun je bodies aanmaken, verwijderen, uit- en
aanzetten en beinvloeden met krachten.

```cpp
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

De objecten binnen Box2d kunnen van 3 types zijn:

- Static

Static bodies zijn objecten die vaststaan in de wereld en hebben dus geen velocity en reageren niet op zwaartekracht.
Static bodies kunnen wel handmatg verplaatst worden naar een andere locatie in de wereld met de UpdateTransform functie
van de PhysicsManager.

- Kinematic

Kinematic bodies kunnen in tegenstelling tot static bodies wel bewegen. Ze reageren niet op zwaartekracht en kunnen niet
bewogen door krachten van botsingen. De enige manier om een kinematic body te bewegen is door zijn velocity te setten
met de functie UpdateVelocity.

- Dynamic

Dynamic bodies zijn volledig gesimuleerd en zullen zich gedragen zoals een object in de echte wereld dat doet. Deze kun
je bewegen door meerdere functies te gebruiken: UpdateVelocity(), AddLinearForce() en AddForce().

## 5. Input Facades

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

## 6. Contact listeners & Behaviour Scripts

De contactlistener in de physicsfacade zorgt ervoor dat alle contacts worden afgevangen en sturen een signaal naar de
behaviorscripts
dat er een contactmoment is begonnen, eindigt of bezig is. Het enige waar de maker van de behaviorscripts rekening mee
moet houden is
het schrijven van de juiste calls naar de physics manager of andere managers. Hieronder staan de methodes van de
behaviorscripts die aangeroepen worden in de contactlistener

```cpp
void ColliderBehaviorTest::OnTriggerEnter2D(const Collider &collider) {}

void ColliderBehaviorTest::OnTriggerExit2D(const Collider &collider) {}

void ColliderBehaviorTest::OnTriggerStay2D(const Collider &collider) {}
```

## 7. HUD (Head-Up Display) aanmaken

Het HUD is georganiseerd in een of meerdere hoofdcontainers. Elke hoofdcontainer container is
verder onderverdeeld in subcontainers, wat zorgt voor een gestructureerde indeling van de UI-elementen.

```cpp
    // Het creëren van een hud dat wordt toegevoegd aan de scene
    auto hud = std::make_shared<HUD>(LayoutType::VERTICAL, GameConstants::General::WINDOW_WIDTH,
                                     GameConstants::General::WINDOW_HEIGHT);
    AddGameObject(hud);
    hud->DrawHud(*engine);
    hud->SetActive(true);

    //Het aanmaken van de HUD structuur gebeurt in de hud.cpp.
    // - LayoutType wordt gebruikt voor de horizontale of verticale uitlijning van de ui objecten.
    // - Op de parameter na de layout kan een container worden gehalveerd met een kommagetal.
    // - Anchor wordt gebruikt voor de positie van de ui objecten binnen een container
    // - Point kan worden gebruikt om een offset mee te geven aan alle uiobjecten binnen een container.

    // Het aanmaken van een container
    auto containerTop =
        std::make_shared<UIContainer>(LayoutType::HORIZONTAL, 0, Anchor::CENTER, Point(0, 0));
    containerTop->SetParent(shared_from_this());

    // Het aanmaken van een sub container
    auto containerTopLeft =
        std::make_shared<UIContainer>(LayoutType::VERTICAL, 0, Anchor::CENTER, Point(0, 0));

    // Het aanmaken van een tweede sub container
    auto containerTopRight =
        std::make_shared<UIContainer>(LayoutType::HORIZONTAL, 0, Anchor::TOP_CENTER, Point(0, 20));

    // Het toevoegen van de sub containers aan de gemaakte container
    containerTop->AddContainerChild(containerTopLeft);
    containerTop->AddContainerChild(containerTopRight);

    // Het aanmaken van een tweede container werkt op dezelfde manier met sub containers
    auto containerBottom =
        std::make_shared<UIContainer>(LayoutType::HORIZONTAL, 0, Anchor::CENTER, Point(0, 0));
    containerBottom->SetParent(shared_from_this());

    // Het toevoegen van de containers aan de HUD
    AddContainerChild(containerTop);
    AddContainerChild(containerBottom);

    // Daarna het renderen van de HUD met de gemaakte containers
    RenderHud();
```

## 8. Pathfinding

De pathfinding wordt gedaan door de A* algoritme. De A* algoritme is een algoritme dat de kortste route berekent tussen een start en eindpoint. De verschillende standaardcomponenten zijn als volgt te gebruiken:

```cpp
    auto floorPathfindable = std::make_shared<Pathfindable>(floor);
    floor->AddComponent(floorPathfindable);
    auto blockPathfindable = std::make_shared<Pathfindable>(block);
    block->AddComponent(blockPathfindable);
    auto block1Pathfindable = std::make_shared<Pathfindable>(block1);
    block1->AddComponent(block1Pathfindable);

    auto enemyPathfinding = std::make_shared<Pathfinding>(enemy, "Player");
    enemy->AddComponent(enemyPathfinding);
```