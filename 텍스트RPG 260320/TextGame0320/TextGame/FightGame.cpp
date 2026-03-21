#include "FightGame.h"
#include <iostream>
#include "Player.h"
#include "Monster.h"

// 게임 입장을 했을 때 함수
void FightGame::Start() {

	std::cout << "================================================\n";
	std::cout << "전투에 입장하셨습니다\n";
	

}

//전투 구현 함수
void FightGame::Battle(Player& player, Monster& monster)
{
    while (true)
    {
        std::cout << "\n===== 전투 시작 =====\n";

        system("pause");

        std::cout << "플레이어 공격!\n";
        monster.TakeDamage(player.GetAttack());

        if (monster.IsDead())
        {
            std::cout << "몬스터 처치!\n";
            break;
        }

        std::cout << "몬스터 공격!\n";
        player.TakeDamage(monster.GetAttack());

        if (player.IsDead())
        {
            std::cout << "플레이어 사망...\n";
            break;
        }

        std::cout << "\n[플레이어 HP] : " << player.GetHP() << '\n';
        std::cout << "[몬스터 HP] : " << monster.GetHP() << '\n';
    }
}