#pragma once
#include <iostream>
#include <string>
#include "Inventory.h"

class Player
{
private:
    std::string name;
    int HP;
    int MaxHP;
    int Attack;
    int Defense;

    int Level;
    int Exp;
    int MaxExp;

    Inventory inventory;

    int Money = 0;
    int WeaponBonus = 0;
    int ArmorBonus = 0;

    std::string equippedWeapon = "없음";
    std::string equippedArmor = "없음";

public:
    void SelectJob();
    void Render();

    int GetAttack();
    int GetDefense();
    int GetHP();
    int GetLevel();

    void TakeDamage(int damage);
    bool IsDead();

    void GainExp(int exp);
    void LevelUp();

    Inventory& GetInventory();

    void AddMoney(int amount);
    bool Removemoney(int amount);

    void Heal(int amount);
    void UseItem(const std::string& itemName);
};