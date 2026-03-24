#include "Monster.h"

void Monster::CreateMonster(int type)
{
    switch (type)
    {
    case 1:
        name = "정령";
        Level = 5;
        HP = 100;
        Attack = 18;
        Defense = 7;
        ExpReward = 55;
        break;

    case 2:
        name = "자쿰의 불꽃";
        Level = 8;
        HP = 180;
        Attack = 28;
        Defense = 12;
        ExpReward = 120;
        break;

    case 3:
        name = "까마귀";
        Level = 3;
        HP = 60;
        Attack = 13;
        Defense = 4;
        ExpReward = 30;
        break;

    case 4:
        name = "주황버섯";
        Level = 1;
        HP = 35;
        Attack = 8;
        Defense = 2;
        ExpReward = 15;
        break;

    default:
        name = "알 수 없는 몬스터";
        Level = 1;
        HP = 1;
        Attack = 1;
        Defense = 0;
        ExpReward = 1;
        break;
    }
}

void Monster::Render()
{
    std::cout << "================ 몬스터 =================\n";
    std::cout << "이름 : " << name << '\n';
    std::cout << "레벨 : " << Level << '\n';
    std::cout << "HP : " << HP
        << "\t공격력 : " << Attack
        << "\t방어력 : " << Defense << '\n';
}

std::string Monster::GetName()
{
    return name;
}

int Monster::GetAttack()
{
    return Attack;
}

int Monster::GetDefense()
{
    return Defense;
}

int Monster::GetHP()
{
    return HP;
}

int Monster::GetLevel()
{
    return Level;
}

int Monster::GetExpReward()
{
    return ExpReward;
}

void Monster::TakeDamage(int damage)
{
    HP -= damage;
    if (HP < 0)
    {
        HP = 0;
    }
}

bool Monster::IsDead()
{
    return HP <= 0;
}