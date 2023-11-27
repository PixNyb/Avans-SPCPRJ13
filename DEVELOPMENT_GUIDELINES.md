# Development Guidelines

## Inhoudsopgave

- [Development Guidelines](#development-guidelines)
  - [Inhoudsopgave](#inhoudsopgave)
  - [Code Formatting](#code-formatting)
  - [Bestandsstructuur](#bestandsstructuur)
  - [Commentaar](#commentaar)
  - [CMake-bestanden](#cmake-bestanden)
  - [Bouwproces](#bouwproces)
  - [Testen](#testen)
  - [Git en Versiebeheer](#git-en-versiebeheer)
  - [Code Reviews](#code-reviews)
  - [Documentatie](#documentatie)

## Code Formatting

Gebruik de Clang Formatter om code te formatteren volgens de `C++ Coding Style Guide` van `LLVM`. Hier zijn enkele basisregels:

- Gebruik 4 spaties voor inspringing (geen tabbladen).
- Gebruik `PascalCase` voor functie- en variabelennamen.
- Gebruik `snake_case` voor bestandsnamen.
- Plaats accolades op een nieuwe regel voor functies en klassen.
- Voeg spaties toe rond operatoren (bijv. x = 5, niet x=5).
- Beperk regellengte tot 80-100 tekens.
- Gebruik `#ifndef`-header guards om headerbestanden te beschermen tegen dubbele inclusie.
- Gebruik `#include <...>` voor systeem- en externe bibliotheekheaders en `#include "..."` voor lokale headers.

Voor meer informatie, zie [LLVM Coding Standards](https://llvm.org/docs/CodingStandards.html).

Daarnaast kan er ook gebruik worden gemaakt van extensies voor de IDE om de code te formatteren. Voor Visual Studio Code is er bijvoorbeeld de [clangd](https://marketplace.visualstudio.com/items?itemName=llvm-vs-code-extensions.vscode-clangd) extensie.

## Bestandsstructuur

- Organiseer bronbestanden in duidelijke mappen met beschrijvende namen (bijv. `src/`, `include/`, `tests/`).
- Houd headerbestanden (`.hpp`) en implementatiebestanden (`.cpp`) apart.
- Plaats `CMakeLists.txt`-bestanden in de relevante mappen om de bronnen en doelen te definiëren.
- Voor meer informatie, zie [Modern CMake](https://cliutils.gitlab.io/modern-cmake/chapters/basics/structure.html).

## Commentaar

- Voeg commentaar toe om complexe of onduidelijke delen van de code uit te leggen.
- Voeg een licentieheader bovenaan elk bronbestand toe om auteursrecht en licentie-informatie te vermelden.
- Gebruik `//` voor enkele regel commentaar en `/* */` voor meerdere regels.
- Houd de [Doxygen commentaarstijl](https://www.doxygen.nl/manual/docblocks.html) aan voor documentatie:
  - File-level commentaar bovenaan elk bestand:
    ```cpp
    /**
    * @file <file_name>
    * @author <author (email)?>
    * @brief <brief description following the format: This file contains the (declaration|definition) of the <class_name> (class|struct|enum|union|interface)>
    * @version <version>
    * @date <date>
    *
    * <detailed description if needed, this does NOT include class-level descriptions>
    *
    * @copyright Copyright (c) 2023
    */
    ```
    - De `@author` tag kan meerdere keren voorkomen.
  - Class-level commentaar bovenaan elke klasse.
    ```cpp
    /**
    * @class <class_name>
    * @brief <brief description following the format: This class (represents|contains|defines) ...>
    *
    * <detailed description>
    */
    ```
    - Met behulp van de `@note`, `@warning`, `@bug`, `@todo` en `@see` tags kan er extra informatie toegevoegd worden.
  - Function-level commentaar boven elke functie.
    ```cpp
    /**
    * @brief <brief description following the format: This function (does|returns|calculates|...) ...>
    *
    * <detailed description>
    * @param <parameter_name> <parameter_description>
    * @return <return_description>
    */
    ```
    - Met behulp van de `@note`, `@warning`, `@bug`, `@todo` en `@see` tags kan er extra informatie toegevoegd worden.
    - Met behulp van de `@param` en `@tparam` tags kan er informatie toegevoegd worden over de parameters van de functie.

## CMake-bestanden

- Organiseer CMake-bestanden duidelijk in de projectmap.
- Gebruik een hoofd-`CMakeLists.txt`-bestand in de hoofdmap om het project te configureren en submappen toe te voegen.
- Gebruik afzonderlijke `CMakeLists.txt`-bestanden in submappen om doelen en afhankelijkheden te definiëren.
- Maak gebruik van CMake-variabelen om configuratieopties te beheren (bijv. compilerflags, versie-informatie).

## Bouwproces

- Gebruik CMake om het buildproces te automatiseren. Definieer targets en afhankelijkheden in `CMakeLists.txt`-bestanden.
- Gebruik vcpkg met het [vcpkg.json](vcpkg.json) manifest om afhankelijkheden te beheren.
- Zorg ervoor dat uw project zonder problemen kan worden gebouwd met behulp van het cmake- en make-commando.
- Voeg testdoelen toe om [unit tests](https://cmake.org/cmake/help/book/mastering-cmake/chapter/Testing%20With%20CMake%20and%20CTest.html) uit te voeren in `tests/`.
- Maak gebruik van Continuous Integration (CI) om automatische builds en tests te garanderen.

## Testen

- Schrijf unit tests waar mogelijk om de functionaliteit van de code te testen.
  - Om unit test te schrijven, maak je gebruik van het [CTest](https://cmake.org/cmake/help/latest/manual/ctest.1.html) framework van [CMake](https://cmake.org/).
  - We gebruiken ook Google Test (gtest) als het testframework voor het schrijven van de tests.
  - Dit doe je door een testbestand aan te maken in `tests/`.
  - Een testbestand bevat een `main` functie die de tests uitvoert.
  - Een testbestand is succesvol als het programma eindigt met een exit code van `0`.
- Voer unit tests uit met behulp van het `ctest` commando.

_Voor het toevoegen van nieuwe tests hoeft er naast het aanmaken van de runnable geen extra configuratie te gebeuren. CMake zal automatisch de test detecteren en uitvoeren. Mochten er nieuwe requirements zijn voor het uitvoeren van de test, dan kunnen deze toegevoegd worden aan de `tests/CMakeLists.txt` file._

## Git en Versiebeheer

- Gebruik Git voor versiebeheer en houd een **consistente** en **betekenisvolle** commitgeschiedenis bij.
- Gebruik branches voor nieuwe functies en bugfixes en voeg deze samen via pull requests.
- Vermijd het opnemen van gegenereerde bestanden en tijdelijke bestanden in uw Git-repository.
- Gebruik een `.gitignore`-bestand om bestanden en mappen uit te sluiten van versiebeheer.
- Gebruik de volgende conventies voor het aanmaken van nieuwe branches:
  - `feature/<naam>` voor nieuwe functies.
  - `bugfix/<naam>` voor bugfixes.
  - `hotfix/<naam>` voor hotfixes.
  - `release/<versie>` voor nieuwe releases.
  - `docs/<naam>` voor documentatie.
  - `test/<naam>` voor tests.

## Code Reviews

- Voer regelmatig code reviews uit om codekwaliteit en naleving van de richtlijnen te waarborgen.
- Moedig feedback aan en wees bereid om wijzigingen aan te brengen op basis van suggesties.

## Documentatie

- Voeg doelmatige documentatie toe aan de code en gebruik `doxygen` om documentatie te genereren.
- Documenteer **functies**, **klassen** en **complexe algoritmen**.
