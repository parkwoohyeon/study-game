#pragma once
#include "Player.h"
#include "Monster.h"
#include "hunting_ground.h"
#include "FightGame.h"
#include "Store.h"
class MainGame
{
private:
    Player player;
    Monster monster;
    hunting_ground hunting;
    FightGame fight;
    Store store;

public:
    void Start();
    void Update();
};