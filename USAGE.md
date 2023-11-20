# Hoe de Engine te gebruiken?

In dit bestand staat uitgebreide documentatie over het gebruik van de DeFunBobEngine game engine.

## Window aanmaken
Voor het aanmaken van een window moeten we eerst zorgen dat de Engine klasse is geintialiseerd,
vanuit daar kunnen we de GraphicsFacade aanroepen om een Window aan te maken. Daarna moet je ook een Render aanmaken waaraan content toegevoegd kan worden.

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
