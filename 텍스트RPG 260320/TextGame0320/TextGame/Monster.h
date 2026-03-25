#pragma once
#include <iostream>
#include <string>

class Monster
{
private:
    std::string name;
    int HP;
    int Attack;
    int Defense;
    int Level;
    int ExpReward;
    int gold;

public:
    void CreateMonster(int type);
    void Render();

    std::string GetName();
    int GetAttack();
    int GetDefense();
    int GetHP();
    int GetLevel();
    int GetExpReward();

    void TakeDamage(int damage);
    bool IsDead();

    int GetMoney();


};
