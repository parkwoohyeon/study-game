#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include "MainGame.h"

int main()
{
    srand((unsigned int)time(nullptr));

    MainGame game;
    game.Start();
    game.Update();

    return 0;
}