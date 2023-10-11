# Entity Component

## Verantwoordelijken

| Naam            | Studentnummer |
| --------------- | ------------- |
| Roël Couwenberg | 2165296       |
| Max Groenendaal | 2169888       |
| Martijn Vermeer | 2171451       |

## User story

### Omschrijving

Entity Component is een variatie op het welbekende ECS (Entity Component System) design pattern.
In deze POC is er geen gebruik gemaakt van systemen en zijn en Entities zelf verantwoordelijk voor het updaten van hun componenten.

### Doel

Aantonen dat we met verschillende componenten een entity in kunnen richten waarbij het gedrag van de entity bepaald wordt door de componenten.

### Criteria

- Een entity bestaat uit meerdere componenten.
  - Een entity kan bestaan uit verschillende soorten componenten.
- Een entity kan componenten bevatten die het gedrag van de entity bepalen.
  - De entities maken gebruik van een position component om hun positie te bepalen en een movement component om hun beweging te bepalen.
