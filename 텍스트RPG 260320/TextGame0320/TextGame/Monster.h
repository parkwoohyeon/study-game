#pragma once
#include <string>
#include <iostream>
class Monster
{

private:

	std::string name;
	int HP;
	int Attack;
	int ExpReward;


public:

	void CreateMonster(int type);
	void Render();
	int GetAttack();
	int GetHP();
	void TakeDamage(int damage);
	bool IsDead();
	int GetExpReward();// 몬스터를 잡았을 때 주는 경험치 반환을 하는 함수
};

