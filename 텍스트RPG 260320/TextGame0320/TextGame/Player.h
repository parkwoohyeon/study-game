#pragma once
#include <iostream>
#include <string>
#include <vector>

class Player
{
private:
    std::string name;
    int HP;
    int Attack;
    int Defense;

    int Level;
    int Exp;
    int MaxExp;

    std::vector<std::string> inventory;

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

    void AddItem(std::string itemName);
    void ShowInventory();
};