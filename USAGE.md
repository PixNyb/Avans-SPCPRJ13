# Hoe de Engine te gebruiken?

In dit bestand staat uitgebreide documentatie over het gebruik van de DeFunBobEngine game engine.

## Window aanmaken

Voor het aanmaken van een window moeten we eerst zorgen dat de Engine klasse is geintialiseerd,
vanuit daar kunnen we de GraphicsFacade aanroepen om een Window aan te maken. Daarna moet je ook een Render aanmaken
waaraan content toegevoegd kan worden.

TODO: Verder uitwerken als straks alles op zijn plek staat (woensdag)

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

## Input manager Gebruiken

De SDLInputFacade is verantwoordelijk voor het afhandelen van SDL-events en het beheren van gebruikersinvoer.

```
// Een exemplaar van de SDLInputFacade, verantwoordelijk voor het afhandelen van SDL-events.
std::unique_ptr<SDLInputFacade> inputManager = std::make_unique<SDLInputFacade>();

// Bind de specifieke toetsaanslag en gebeurtenistype aan de ActionType (bijv. JUMP).
inputManager->Bind(KeyEvent(KeyCode::UP_ARROW, EventType::KEYPRESSED), ActionType::JUMP);

// Simuleer het updaten van het inputManager, bijvoorbeeld per frame in een spelloop.
inputManager->Update();
```