#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include "DoubleBuffering.h"
#include "Player.h"
#include "Monster.h"
#include "Defines.h"
#include "Bullet.h"
#include "FPS.h"
#include "MonsterBullet.h"
int main()
{
    srand((unsigned int)time(NULL));

    system("mode con:cols=200 lines=50");
    ScereenInit();

    PlayerStart(10, 10);

    // 시작 화면
    ScreenPrintUI(10, 20, "  ######   ######   ######   ######   ###### ");
    ScreenPrintUI(10, 21, "  ##       ##  ##   ##  ##   ##       ##     ");
    ScreenPrintUI(10, 22, "  ####     ######   ######   ####     ####   ");
    ScreenPrintUI(10, 23, "  ##       ##  ##   ##  ##   ##       ##     ");
    ScreenPrintUI(10, 24, "  ######   ##  ##   ##  ##   ######   ###### ");

    ScreenPrintUI(10, 26, "          [  SHOOTING GAME  ]");
    ScreenPrintUI(10, 27, "----------------------------------------");
    ScreenPrintUI(10, 28, "           READY TO START...");
    ScreenFlipping();
    Sleep(1000);

    while (true)
    {

        int score = GetScore();

        if (score >= 150)
            SetPlayerLevel(4);
        else if (score >= 100)
            SetPlayerLevel(3);
        else if (score >= 50)
            SetPlayerLevel(2);
        else
            SetPlayerLevel(1);





        FPSUpdate();
        ScreenClear();

        PlayerTick();
        BulletTick();
        MonsterTick();
        MonsterBulletTick();

        PlayerDraw();
        BulletDraw();
        MonsterDraw();
        MonsterBulletDraw();

        char UI1[100] = {};
        sprintf_s(UI1, "FPS : %d", GetFPS());
        ScreenPrintUI(0, 0, UI1);

        char UI2[100] = {};
        sprintf_s(UI2, "Delta : %.4f", GetDeltaTime());
        ScreenPrintUI(0, 1, UI2);

        char UI3[100] = {};
        sprintf_s(UI3, "SCORE : %d", GetScore());
        ScreenPrintUI(0, 2, UI3);

        char UI4[100] = {};
        sprintf_s(UI4, "LEVEL : %d", GetPlayerLevel());
        ScreenPrintUI(0, 3, UI4);

        ScreenFlipping();

        Sleep(16); // 전체 프레임 속도 제한
    }

    return 0;
}