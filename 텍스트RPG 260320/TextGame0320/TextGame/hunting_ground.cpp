#include "hunting_ground.h"

void hunting_ground::SelectGround()
{
    std::cout << "사냥터를 선택하세요 (1. 시간의 숲 2. 자쿰 신전 3. 새들이 우는 언덕 4. 주황버섯 언덕)\n -> ";
    int input = 0;
    std::cin >> input;

    switch (input)
    {
    case 1:
        place = "시간의 숲";
        placeLevel = 5;
        monsterInfo = "정령 몬스터 출몰";
        monsterType = 1;
        break;

    case 2:
        place = "자쿰 신전";
        placeLevel = 8;
        monsterInfo = "보스급 몬스터 출몰";
        monsterType = 2;
        break;

    case 3:
        place = "새들이 우는 언덕";
        placeLevel = 3;
        monsterInfo = "새 몬스터 출몰";
        monsterType = 3;
        break;

    case 4:
        place = "주황버섯 언덕";
        placeLevel = 1;
        monsterInfo = "초보자용 몬스터 출몰";
        monsterType = 4;
        break;

    default:
        std::cout << "잘못된 입력입니다. 주황버섯 언덕으로 이동합니다.\n";
        place = "주황버섯 언덕";
        placeLevel = 1;
        monsterInfo = "초보자용 몬스터 출몰";
        monsterType = 4;
        break;
    }
}

void hunting_ground::Render()
{
    std::cout << "================================================\n";
    std::cout << "사냥터 : " << place << '\n';
    std::cout << "권장 레벨 : " << placeLevel << '\n';
    std::cout << "설명 : " << monsterInfo << '\n';
}

int hunting_ground::GetMonsterType()
{
    return monsterType;
}