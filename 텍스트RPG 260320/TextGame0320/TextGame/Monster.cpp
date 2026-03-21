#include "Monster.h"
#include <iostream>

//몬스터 생성 함수
void Monster::CreateMonster(int type)
{
    switch (type)
    {
    case 1:
        name = "정령";
        HP = 100;
        Attack = 15;
        break;
    case 2:
        name = "자쿰의 불꽃";
        HP = 500;
        Attack = 30;
        break;
    case 3:
        name = "까마귀";
        HP = 80;
        Attack = 10;
        break;
    case 4:
        name = "주황버섯";
        HP = 40;
        Attack = 5;
        break;

    }
}


void Monster::Render()
{
    std::cout << "================ 몬스터 =================\n";
    std::cout << "이름 : " << name << '\n';
    std::cout << "HP : " << HP << '\n';
    std::cout << "공격력 : " << Attack << '\n';
}

int Monster::GetAttack()
{
    return Attack;
}

int Monster::GetHP()
{
    return HP;
}

void Monster::TakeDamage(int damage)
{
    HP -= damage;
}

bool Monster::IsDead()
{
    return HP <= 0;
}