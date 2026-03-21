#pragma once
#include <iostream>
#include <string>
class Player
{
	std::string name;
	int HP;
	int Attack;
	int damage;

public:
	void SelectJob();
	void Render();
	int GetAttack();
	int GetHP();
	void TakeDamage(int damage);
	bool IsDead();
};


