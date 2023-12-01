# Hoe de Engine te gebruiken?

In dit bestand staat uitgebreide documentatie over het gebruik van de DeFunBobEngine game engine.

## Window aanmaken

Voor het aanmaken van een window moeten we eerst zorgen dat de Engine klasse is geintialiseerd,
vanuit daar kunnen we de GraphicsFacade aanroepen om een Window aan te maken. Daarna moet je ook een Render aanmaken
waaraan content toegevoegd kan worden.

TODO: Verder uitwerken als straks alles op zijn plek staat (woensdag)

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