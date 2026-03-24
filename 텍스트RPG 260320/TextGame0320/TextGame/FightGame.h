#pragma once
#include "Player.h"
#include "Monster.h"

class FightGame
{
public:
    void Start();
    void Battle(Player& player, Monster& monster);
    bool CheckHit(int attackerLevel, int defenderLevel);
};