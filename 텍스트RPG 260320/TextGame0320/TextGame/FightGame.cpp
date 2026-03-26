#include "FightGame.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void FightGame::Start()
{
    std::cout << "================================================\n";
    std::cout << "                  BATTLE START\n";
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

        std::cout << "\n================================================\n";
        std::cout << "                    BATTLE\n";
        std::cout << "================================================\n";
        std::cout << "플레이어 HP : " << player.GetHP() << '\n';
        std::cout << monster.GetName() << " HP : " << monster.GetHP() << '\n';
        std::cout << "------------------------------------------------\n";
        std::cout << "[1] 공격\n";
        std::cout << "[2] 도망\n";
        std::cout << "[3] 아이템 사용\n";
        std::cout << "선택 >> ";
        std::cin >> input;

        if (input == 1)
        {
            std::cout << "\n>> 플레이어의 공격!\n";

            if (CheckHit(player.GetLevel(), monster.GetLevel()))
            {
                int damage = player.GetAttack() - monster.GetDefense();
                if (damage < 1)
                {
                    damage = 1;
                }

                bool isCritical = (rand() % 100 < 20); // 20%
                if (isCritical)
                {
                    damage *= 2;
                    std::cout << ">> 크리티컬 히트!!\n";
                }

                monster.TakeDamage(damage);
                std::cout << ">> " << monster.GetName() << "에게 " << damage << "의 피해를 주었다!\n";
            }
            else
            {
                std::cout << ">> 공격이 빗나갔다!\n";
            }

            if (monster.IsDead())
            {
                std::cout << "\n>> " << monster.GetName() << " 처치 성공!\n";
                player.GainExp(monster.GetExpReward());
                player.AddMoney(monster.GetMoney());

                // 드랍 확률
                if (rand() % 100 < 35)
                {
                    player.GetInventory().AddItem("포션");
                    std::cout << ">> 몬스터가 포션을 떨어뜨렸다!\n";
                }

                break;
            }

            std::cout << "\n>> " << monster.GetName() << "의 공격!\n";

            if (CheckHit(monster.GetLevel(), player.GetLevel()))
            {
                int damage = monster.GetAttack() - player.GetDefense();
                if (damage < 1)
                {
                    damage = 1;
                }

                bool isCritical = (rand() % 100 < 10); // 몬스터는 10%
                if (isCritical)
                {
                    damage *= 2;
                    std::cout << ">> 몬스터의 강한 일격!!\n";
                }

                player.TakeDamage(damage);
                std::cout << ">> 플레이어가 " << damage << "의 피해를 입었다.\n";
            }
            else
            {
                std::cout << ">> 몬스터의 공격이 빗나갔다!\n";
            }

            if (player.IsDead())
            {
                std::cout << "\n>> 플레이어 사망...\n";
                break;
            }
        }
        else if (input == 2)
        {
            int escapeChance = rand() % 100;

            if (escapeChance < 50)
            {
                std::cout << ">> 도망에 성공했다!\n";
                break;
            }
            else
            {
                std::cout << ">> 도망에 실패했다!\n";

                std::cout << "\n>> " << monster.GetName() << "의 공격!\n";

                if (CheckHit(monster.GetLevel(), player.GetLevel()))
                {
                    int damage = monster.GetAttack() - player.GetDefense();
                    if (damage < 1)
                    {
                        damage = 1;
                    }

                    player.TakeDamage(damage);
                    std::cout << ">> 플레이어가 " << damage << "의 피해를 입었다.\n";
                }
                else
                {
                    std::cout << ">> 몬스터의 공격이 빗나갔다!\n";
                }

                if (player.IsDead())
                {
                    std::cout << "\n>> 플레이어 사망...\n";
                    break;
                }
            }
        }
        else if (input == 3)
        {
            player.GetInventory().ShowItems();

            if (player.GetInventory().IsEmpty())
            {
                continue;
            }

            int itemInput = 0;
            std::cout << "\n0. 취소\n";
            std::cout << "사용할 아이템 번호 >> ";
            std::cin >> itemInput;

            if (itemInput == 0)
            {
                continue;
            }

            if (itemInput < 1 || itemInput > player.GetInventory().GetItemCount())
            {
                std::cout << ">> 잘못된 입력입니다.\n";
                continue;
            }

            std::string item = player.GetInventory().GetItem(itemInput - 1);
            player.UseItem(item);

            // 아이템 사용 후 몬스터 턴
            if (!monster.IsDead())
            {
                std::cout << "\n>> " << monster.GetName() << "의 공격!\n";

                if (CheckHit(monster.GetLevel(), player.GetLevel()))
                {
                    int damage = monster.GetAttack() - player.GetDefense();
                    if (damage < 1)
                    {
                        damage = 1;
                    }

                    player.TakeDamage(damage);
                    std::cout << ">> 플레이어가 " << damage << "의 피해를 입었다.\n";
                }
                else
                {
                    std::cout << ">> 몬스터의 공격이 빗나갔다!\n";
                }

                if (player.IsDead())
                {
                    std::cout << "\n>> 플레이어 사망...\n";
                    break;
                }
            }
        }
        else
        {
            std::cout << ">> 잘못된 입력입니다.\n";
        }
    }
}