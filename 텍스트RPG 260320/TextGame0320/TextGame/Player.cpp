#include "Player.h"

void Player::SelectJob()
{
    std::cout << "직업을 선택하세요(1. 검사 2. 마법사 3. 궁수 4. 도적)\n -> ";
    int input = 0;
    std::cin >> input;

    switch (input)
    {
    case 1:
        name = "검사";
        HP = 180;
        Attack = 18;
        Defense = 8;
        break;

    case 2:
        name = "마법사";
        HP = 90;
        Attack = 24;
        Defense = 3;
        break;

    case 3:
        name = "궁수";
        HP = 120;
        Attack = 20;
        Defense = 5;
        break;

    case 4:
        name = "도적";
        HP = 110;
        Attack = 21;
        Defense = 4;
        break;

    default:
        std::cout << "잘못된 입력입니다. 검사로 시작합니다.\n";
        name = "검사";
        HP = 180;
        Attack = 18;
        Defense = 8;
        break;
    }

    Level = 1;
    Exp = 0;
    MaxExp = 100;
}

void Player::Render()
{
    std::cout << "================================================\n";
    std::cout << "직업 : " << name << '\n';
    std::cout << "레벨 : " << Level << '\n';
    std::cout << "체력 : " << HP
        << "\t공격력 : " << Attack
        << "\t방어력 : " << Defense << '\n';
    std::cout << "경험치 : " << Exp << " / " << MaxExp << '\n';
}

int Player::GetAttack()
{
    return Attack;
}

int Player::GetDefense()
{
    return Defense;
}

int Player::GetHP()
{
    return HP;
}

int Player::GetLevel()
{
    return Level;
}

void Player::TakeDamage(int damage)
{
    HP -= damage;
    if (HP < 0)
    {
        HP = 0;
    }
}

bool Player::IsDead()
{
    return HP <= 0;
}

void Player::GainExp(int exp)
{
    Exp += exp;
    std::cout << exp << "의 경험치를 획득했습니다!\n";

    while (Exp >= MaxExp)
    {
        LevelUp();
    }
}

void Player::LevelUp()
{
    Exp -= MaxExp;
    Level++;
    MaxExp += 30;

    HP += 15;
    Attack += 3;
    Defense += 2;

    std::cout << "레벨업! 현재 레벨 : " << Level << '\n';
    std::cout << "능력치가 상승했습니다!\n";
}

void Player::AddItem(std::string itemName)
{
    inventory.push_back(itemName);
    std::cout << itemName << "을(를) 획득했습니다!\n";
}

void Player::ShowInventory()
{
    std::cout << "\n=========== 인벤토리 ===========\n";

    if (inventory.empty())
    {
        std::cout << "인벤토리가 비어 있습니다.\n";
        return;
    }

    for (int i = 0; i < inventory.size(); i++)
    {
        std::cout << i + 1 << ". " << inventory[i] << '\n';
    }
}