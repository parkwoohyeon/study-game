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

        std::cout << "\n1. 사냥터 2. 인벤토리 3. 종료\n -> ";
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
            player.ShowInventory();
            system("pause");
        }
        else if (input == 3)
        {
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