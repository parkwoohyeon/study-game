#include "MainGame.h"
#include <iostream>
#include "hunting_ground.h"
#include "Monster.h"
#include "FightGame.h"
#include "Player.h"

//main함수에 들어갈 놈들
void MainGame::Start() {
	player.SelectJob();

}

void MainGame::Update()
{
    int menuInput = 0;

    while (true)
    {
        //system("cls");
        player.Render();
        std::cout << "1. 사냥터 2. 종료\n -> ";
        std::cin >> menuInput;

        if (menuInput == 1)
        {
            hunting.SelectGround();
            hunting.Render();

            int fightInput = 0;
            std::cout << "전투에 입장하시겠습니까? (1. 예 2. 아니오)\n -> ";
            std::cin >> fightInput;

            if (fightInput == 1)
            {
                fight.Start();
                std::cout << "DEBUG monsterType: " << hunting.GetMonsterType() << '\n';
                monster.CreateMonster(hunting.GetMonsterType());
                monster.Render();
                fight.Battle(player, monster);
                system("pause");
            }
        }
        else if (menuInput == 2)
        {
            break;
        }
    }
}
