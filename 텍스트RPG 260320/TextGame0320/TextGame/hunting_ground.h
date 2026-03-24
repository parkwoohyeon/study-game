#pragma once
#include <iostream>
#include <string>

class hunting_ground
{
private:
    std::string place;
    int placeLevel;
    std::string monsterInfo;
    int monsterType;

public:
    void SelectGround();
    void Render();
    int GetMonsterType();
};