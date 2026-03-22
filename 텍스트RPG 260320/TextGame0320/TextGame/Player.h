#pragma once
#include <iostream>
#include <string>
class Player
{
private:

	std::string name;
	int HP;
	int Attack;
	int damage;
	int Level;
	int Exp;
	int MaxExp;


public:
	void SelectJob();
	void Render();
	int GetAttack();
	int GetHP();
	void TakeDamage(int damage);
	bool IsDead();
	void GainExp(int exp); //경험치를 휙득하는 함수
	void Levelup(); //"렙업 했을때 실제 능력치 올리는 함수"
	int GetLevel();// 현재 레벨을 외부에 알려주는 함수
	int GetExp(); //현재 경험치를 외부에 보여주는 함수
	int GetMaxExp();//다음 레벨업 까지 필요한 최대 경험치 반환
};


