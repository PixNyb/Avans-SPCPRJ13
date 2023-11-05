# Physics POC met SDL2

## Overzicht

Deze Proof of Concept (POC) is ontwikkeld als een demonstratie van de fysica-engine voor een game-ontwikkelingsplatform, met gebruik van de Simple DirectMedia Layer (SDL2) bibliotheek. Het illustreert zwaartekracht, botsingen, en gebruikersinteracties binnen een eenvoudige grafische omgeving.

## Vereisten

- SDL2-bibliotheek geïnstalleerd op uw systeem.
- Een C++ compiler (zoals GCC, Clang, MSVC, etc.).

## Installatie

1. Zorg ervoor dat SDL2 op uw systeem is geïnstalleerd. U kunt het downloaden van de [SDL website](https://www.libsdl.org/download-2.0.php) of installeren via een pakketbeheerder.
2. Kloon deze repository of download de bronbestanden.
3. Compileer het programma met uw C++ compiler en link tegen de SDL2-bibliotheek.

   Voorbeeld met `g++`:

   ```sh
   g++ -std=c++11 -o SDL_Physics_POC main.cpp -lSDL2
   ```

## Functionaliteiten

- Zwaartekracht: Het vierkant valt door de zwaartekracht en stuitert terug wanneer het de vloer raakt.
- Kleurverandering: Door op de spatiebalk te drukken, verandert de kleur van het vierkant willekeurig.
- Springen: Door shift ingedrukt te houden terwijl u op de spatiebalk drukt, kan het vierkant springen.
- Pijltoetsen: Gebruik de pijltoetsen om het vierkant te bewegen.
- Muisinteractie: Klikken en slepen verplaatst het vierkant naar de positie van de cursor.

## Besturing

- Pijl omhoog: Beweeg het vierkant omhoog.
- Pijl omlaag: Beweeg het vierkant omlaag (niet door de vloer).
- Pijl links: Beweeg het vierkant naar links.
- Pijl rechts: Beweeg het vierkant naar rechts.
- Spatiebalk: Verander de kleur van het vierkant.
- Shift + Spatiebalk: Laat het vierkant springen.
- Muisklik en slepen: Plaats het vierkant op de muiscursorlocatie.

## Uitvoering
Na het compileren kan de POC worden uitgevoerd door het uitvoerbare bestand te starten. De applicatie zal een venster openen waarin u direct kunt interageren met het vierkant en de functionaliteiten van de fysica-engine kunt testen.