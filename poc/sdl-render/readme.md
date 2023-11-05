# SDL2 Image Renderer POC

## Overzicht

Deze applicatie is een demonstratie van het renderen van afbeeldingen en vormen met SDL2 en de SDL_image uitbreidingsbibliotheek in C++. Het laadt een PNG-afbeelding als een achtergrond en toont deze in een venster, samen met een getekende rechthoek.

## Vereisten
- SDL2-bibliotheek
- SDL2_image uitbreidingsbibliotheek
- Een C++ compiler (zoals GCC, Clang, MSVC, etc.)


## Installatie
1. Zorg dat SDL2 en SDL2_image op uw systeem zijn geïnstalleerd. Deze kunnen geïnstalleerd worden via een pakketbeheerder of vanaf de officiële SDL-website.
2. Kloon deze repository of download de bronbestanden.
3. Compileer het programma met uw C++ compiler en link tegen de SDL2-bibliotheek.


## Functionaliteiten
- Spriteheet Animeren
De applicatie maakt het mogelijk om animaties uit een sprite sheet te halen en deze in real-time af te spelen. Dit stelt gebruikers in staat om complexe animaties te creëren met een minimale hoeveelheid assets.
Gebruikers kunnen de animatiesnelheid controleren en tussen verschillende animaties schakelen op basis van spellogica of gebruikersinteractie.
Afbeeldingen Laten Zien
- Ondersteunt het laden en weergeven van diverse afbeeldingsformaten, waaronder PNG, JPEG, en GIF.
Afbeeldingen kunnen worden getransformeerd door schaling, rotatie, en kleuraanpassingen toe te passen, waardoor dynamische visuele effecten mogelijk zijn.
SDL2-Blokken Tonen

- Maakt het mogelijk om geometrische vormen zoals rechthoeken en vierkanten te tekenen, die gebruikt kunnen worden voor UI-elementen, debug doeleinden of als onderdeel van de gameplay.
Biedt de mogelijkheid om de opvulkleur en randkleur van vormen aan te passen, wat bijdraagt aan een meer gepersonaliseerde en visueel aantrekkelijke interface.


## Bestanden
- Renderer.hpp: Headerbestand voor de renderer klasse.
- Spritesheet.hpp: Headerbestand voor de spritesheet klasse.
- assets/indianaBob.png: Voorbeeld PNG-afbeelding die als achtergrond wordt gebruikt.