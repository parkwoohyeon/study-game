#include <Windows.h>
#include "Player.h"
#include "Bullet.h"
#include "DoubleBuffering.h"
#include "Defines.h"

static Player player = {};
static int fireDelay = 0;   // 연사 속도 조절용
static int playerLevel= 1;

int GetPlayerLevel() {
    return playerLevel;
}

void SetPlayerLevel(int level) {
    playerLevel = level;
}



void PlayerStart(float x, float y)
{
    player.Position.x = x;
    player.Position.y = y;
}

void PlayerTick()
{
    // 이동
    if (GetAsyncKeyState(VK_LEFT) & 0x8000)
    {
        player.Position.x -= 1;
        if (player.Position.x < 0)
            player.Position.x = 0;
    }

    if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
    {
        player.Position.x += 1;
        if (player.Position.x > DF_BG_SIZE_X - 4)
            player.Position.x = DF_BG_SIZE_X - 4;
    }

    if (GetAsyncKeyState(VK_UP) & 0x8000)
    {
        player.Position.y -= 1;
        if (player.Position.y < 0)
            player.Position.y = 0;
    }

    if (GetAsyncKeyState(VK_DOWN) & 0x8000)
    {
        player.Position.y += 1;
        if (player.Position.y > DF_BG_SIZE_Y - 2)
            player.Position.y = DF_BG_SIZE_Y - 2;
    }

    // 발사 쿨타임 감소
    if (fireDelay > 0)
        fireDelay--;

    // 발사
    if ((GetAsyncKeyState(VK_SPACE) & 0x8000) && fireDelay == 0)
    {
        switch (playerLevel)
        {
        case 1:
            BulletFire(player.Position.x + 3, player.Position.y);
            break;

        case 2:
            BulletFire(player.Position.x + 3, player.Position.y);
            BulletFire(player.Position.x + 3, player.Position.y + 1);
            break;

        case 3:
            BulletFire(player.Position.x + 3, player.Position.y - 1);
            BulletFire(player.Position.x + 3, player.Position.y);
            BulletFire(player.Position.x + 3, player.Position.y + 1);
            break;

        default:
            BulletFire(player.Position.x + 3, player.Position.y - 1);
            BulletFire(player.Position.x + 3, player.Position.y);
            BulletFire(player.Position.x + 3, player.Position.y + 1);
            break;
        }

        fireDelay = 5;
    }
}

void PlayerDraw()
{
    ScreenPrintUI(
        (SHORT)player.Position.x,
        (SHORT)player.Position.y,
        "|=>"
    );
}