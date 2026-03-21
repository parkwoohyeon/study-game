#pragma once
#include <string>
#include <iostream>
class Monster
{

private:

	std::string name;
	int HP;
	int Attack;

public:

	void CreateMonster(int type);
	void Render();
	int GetAttack();
	int GetHP();
	void TakeDamage(int damage);
	bool IsDead();
};

