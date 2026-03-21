#include "Player.h"
#include <iostream>
#include "MainGame.h"

//직업 선택하는 함수
void Player::SelectJob()
{
    std::cout << "직업을 선택하세요 (1. 전사 2. 마법사 3. 궁수 4. 도적)\n -> ";

    int Input = 0;
    std::cin >> Input;

    switch (Input)
    {
    case 1:
        name = "검사";
        HP = 200;
        Attack = 20;
        break;
    case 2:
        name = "마법사";
        HP = 50;
        Attack = 15;
        break;
    case 3:
        name = "궁수";
        HP = 100;
        Attack = 13;
        break;
    case 4:
        name = "도적";
        HP = 120;
        Attack = 17;
        break;
    default:
        std::cout << "잘못된 입력입니다.\n";
        break;
    }
}

//직업의 정보를 알려주는 함수
void Player::Render()
{
    std::cout << "================================================\n";
    std::cout << "직업 이름 : " << name << '\n';
    std::cout << "체력 : " << HP << "\t공격력 : " << Attack << '\n';
}

int Player::GetAttack()
{
    return Attack;
}

int Player::GetHP()
{
    return HP;
}

void Player::TakeDamage(int damage)
{
    HP -= damage;
}

bool Player::IsDead()
{
    return HP <= 0;
}