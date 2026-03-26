#include "MainGame.h"
#include <iostream>

void MainGame::Start()
{
    player.SelectJob();
}

void MainGame::Update()
{
    int input = 0;

    while (true)
    {
        system("cls");
        player.Render();

        std::cout << "\n========================================\n";
        std::cout << "               MAIN MENU\n";
        std::cout << "========================================\n";
        std::cout << "[1] 사냥터\n";
        std::cout << "[2] 인벤토리\n";
        std::cout << "[3] 상점\n";
        std::cout << "[4] 종료\n";
        std::cout << "========================================\n";
        std::cout << "선택 >> ";
        std::cin >> input;

        if (input == 1)
        {
            hunting.SelectGround();
            hunting.Render();

            int fightInput = 0;
            std::cout << "\n전투에 입장하시겠습니까? (1. 예 2. 아니오)\n -> ";
            std::cin >> fightInput;

            if (fightInput == 1)
            {
                fight.Start();
                monster.CreateMonster(hunting.GetMonsterType());
                monster.Render();
                fight.Battle(player, monster);
                system("pause");
            }
        }
        else if (input == 2)
        {
            int invenInput = 0;

            while (true)
            {
                system("cls");
                player.Render();
                player.GetInventory().ShowItems();

                std::cout << "\n0. 뒤로 가기\n";
                std::cout << "아이템 선택 : ";
                std::cin >> invenInput;

                if (invenInput == 0)
                {
                    break;
                }

                if (invenInput < 1 || invenInput > player.GetInventory().GetItemCount())
                {
                    std::cout << "잘못된 입력입니다.\n";
                    system("pause");
                    continue;
                }

                std::string item = player.GetInventory().GetItem(invenInput - 1);
                player.UseItem(item);
                system("pause");
            }
        }
        else if (input == 3)
        {
            store.EnterShop(player);
            system("pause");
        }
        else if (input == 4) {
            std::cout << "게임을 종료합니다.\n";
            break;
        }
        else
        {
            std::cout << "잘못된 입력입니다.\n";
            system("pause");
        }
    }
}