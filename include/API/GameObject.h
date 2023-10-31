//
// Created by Robin on 30-10-2023.
//

#ifndef AVANS_SPCPRJ13_GAMEOBJECT_H
#define AVANS_SPCPRJ13_GAMEOBJECT_H

#include <string>
#include <vector>

class GameObject {
private:
    std::string name;
    bool active;
    int tag;
    int layer;


public:
    GameObject();
    ~GameObject();

    // Getters and Setters
    std::string getName() const;
    void setName(const std::string& name);

    bool isActive() const;
    void setActive(bool active);

    // Association with other classes
    void AddComponent(/*...*/);
    bool isActiveInWorld() const;
    bool isActiveSelf() const;
};


#endif //AVANS_SPCPRJ13_GAMEOBJECT_H
