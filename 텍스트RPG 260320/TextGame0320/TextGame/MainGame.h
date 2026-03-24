#pragma once
#include "Player.h"
#include "Monster.h"
#include "hunting_ground.h"
#include "FightGame.h"

class MainGame
{
private:
    Player player;
    Monster monster;
    hunting_ground hunting;
    FightGame fight;

public:
    void Start();
    void Update();
};