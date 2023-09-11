# SPCPRJ13 Repository

Welkom in de repository van SPCPRJ13. Dit is de repository waarin de code van de `DeFunBobEngine` game engine staat. Deze game engine is gemaakt voor het vak `SPCPRJ13` van de opleiding HBO-ICT van Avans Hogeschool 's-Hertogenbosch.

## Projectdetails

- **Projectnaam**: DeFunBobEngine
- **Taal**: C++
- **Platform**: Windows/Linux/MacOS

## ClickUp Board

Voor het bijhouden van de voortgang van het project wordt er gebruik gemaakt van [ClickUp](https://app.clickup.com/9012037397/v/l/4-90120089132-1). Dit is een online project management tool. In deze tool worden alle taken bijgehouden en kan de voortgang van het project worden bijgehouden.

## Aan de slag

### Vereisten

- C++ compiler (GCC, Clang, MSVC)
- CMake
- Git
- Doxygen (en Graphviz)

### Installatie

- Clone de repository

```bash
git clone git@github.com:PixNyb/Avans-SPCPRJ13.git
```

- Gebruik CMake om de code te compileren

```bash
cmake -S . -B build && cmake --build build
```

### Doxygen

De documentatie van de code wordt gegenereerd met behulp van [Doxygen](https://www.doxygen.nl/index.html). De documentatie is te vinden in de `docs` map. Om de documentatie te genereren moet het volgende commando worden uitgevoerd:

```sh
doxygen Doxyfile
```

*Denk eraan dat [Graphviz](https://graphviz.org/) geïnstalleerd moet zijn om de UML-diagrammen te genereren, en dat doxygen niet automatisch in CI/CD wordt uitgevoerd. Dit moet dus handmatig worden gedaan.*

## Development Guidelines

De development guidelines zijn gedefiniëerd in [DEVELOPMENT_GUIDELINES.md](DEVELOPMENT_GUIDELINES.md).
