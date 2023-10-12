# Entity Component System

## Gebruik
Het belangrijkste bestand is te vinden onder /src/core/app.cpp.
### ECS Structuur
- Systems
  - Render
  - Movement (converteert input naar movement)
  - Player control (input)
  - Scene (niet af en uitgecomment)
- Entiteiten
  - A
  - B
  - C
- Componenten
  - InputComponent
  - PositionComponent
  - Box2DComponent


## **Omschrijving**

Het opzetten van een ECS is van essentieel belang voor onze game-engine.

Dit maakt onze game-engine namelijk zeer uitbreidbaar en flexibel.

Wel is dit een vrij complexe architectuur waarbij je jezelf snel in je voet schiet.

## **Doel**

Aantonen dat er middels een ECS een scheiding is tussen data (componenten), gedrag (systemen) en entiteiten (unieke ID's of objecten).

Door deze scheiding kunnen we efficiënter en modulairder programmeren, wat ons in staat stelt om snel nieuwe features te implementeren en uit te breiden.

## **Criteria**

- Data (component) is gescheiden van gedrag en entiteiten.

- Een systeem (gedrag) is gescheiden van data en entiteiten.

- Entiteiten zijn gescheiden van data en gedrag.

- Er zijn op zijn minst 2 entiteiten.

- Er is op zijn minst 1 component gekoppeld.

- Een entiteit heeft op zijn minst 3 testbare gedragingen (die niet op elkaar lijken) waarmee wij aan kunnen tonen dat de architectuur werkt.

- Het geheel wordt beheerd d.m.v. een component manager.