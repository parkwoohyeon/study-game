#include "FightGame.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void FightGame::Start()
{
    std::cout << "================================================\n";
    std::cout << "전투에 입장하셨습니다.\n";
}

bool FightGame::CheckHit(int attackerLevel, int defenderLevel)
{
    int hitChance = 85 + (attackerLevel - defenderLevel) * 5;

    if (hitChance < 30)
    {
        hitChance = 30;
    }

    if (hitChance > 95)
    {
        hitChance = 95;
    }

    int roll = rand() % 100 + 1;
    return roll <= hitChance;
}

void FightGame::Battle(Player& player, Monster& monster)
{
    while (true)
    {
        int input = 0;

        std::cout << "\n================ 전투 =================\n";
        std::cout << "플레이어 HP : " << player.GetHP() << '\n';
        std::cout << "몬스터 HP : " << monster.GetHP() << '\n';
        std::cout << "1. 공격 2. 도망 3. 인벤토리\n -> ";
        std::cin >> input;

        if (input == 1)
        {
            std::cout << "\n플레이어 공격!\n";

            if (CheckHit(player.GetLevel(), monster.GetLevel()))
            {
                int damage = player.GetAttack() - monster.GetDefense();
                if (damage < 1)
                {
                    damage = 1;
                }

                monster.TakeDamage(damage);
                std::cout << monster.GetName() << "에게 " << damage << "의 피해를 주었습니다.\n";
            }
            else
            {
                std::cout << "플레이어 공격이 빗나갔습니다!\n";
            }

            if (monster.IsDead())
            {
                std::cout << "몬스터 처치!\n";
                player.GainExp(monster.GetExpReward());
                break;
            }

            std::cout << "\n몬스터 공격!\n";

            if (CheckHit(monster.GetLevel(), player.GetLevel()))
            {
                int damage = monster.GetAttack() - player.GetDefense();
                if (damage < 1)
                {
                    damage = 1;
                }

                player.TakeDamage(damage);
                std::cout << "플레이어가 " << damage << "의 피해를 입었습니다.\n";
            }
            else
            {
                std::cout << "몬스터 공격이 빗나갔습니다!\n";
            }

            if (player.IsDead())
            {
                std::cout << "플레이어 사망...\n";
                break;
            }
        }
        else if (input == 2)
        {
            std::cout << "전투에서 도망쳤습니다.\n";
            break;
        }
        else if (input == 3)
        {
            player.ShowInventory();
        }
        else
        {
            std::cout << "잘못된 입력입니다.\n";
        }
    }
}