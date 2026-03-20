#include "hunting_ground.h"
#include <iostream>
#include "FightGame.h"
#include "MainGame.h"

// 사냥터를 생성하는 함수 
void hunting_ground::SelectGround() {
	std::cout << "사냥터를 선택하세요 (1. 시간의 숲 2. 자쿰 신전 3. 새들이 우는 언덕 4. 주황버섯 언덕)\n ->";
	int Input = 0;
	std::cin >> Input;
	switch (Input)

	{
		case 1 :
			place = "시간의 숲";
			placeLevel = 4;
			monster = "정령 몬스터 출몰";
			break;

		case 2:
			place = "자쿰 신전";
			placeLevel = 6;
			monster = "자쿰 보스 성장을 많이 하고 도전해라";
			break;

		case 3:
			place = "새들이 우는 언덕";
			placeLevel = 3;
			monster = "새 몬스터 출몰";
			break;

		case 4:
			place = "주황버섯 언덕";
			placeLevel = 1;
			monster = "주황버섯 나옴 초보자용";
			break;








	}

	

}


// 사냥터의 정보를 보여주는 함수
void hunting_ground ::Render()
{
	std::cout << "================================================\n";
	std::cout << "사냥터 : " << place << '\n';
	std::cout << "난이도 : "  << placeLevel << "\t 몬스터 :  " << monster << '\n';
	std::cout << "================================================\n";
	std::cout << "전투에 입장 하시겠습니까? (1. 입장한다 2. 조금만 더 생각하고 온다)\n ->";
	int Input = 0;
	std::cin >> Input;
	if (Input == 1) {
		fight.Start();
		
	}
}

int monsterType;

int GetMonsterType()
{
	return monsterType;
}