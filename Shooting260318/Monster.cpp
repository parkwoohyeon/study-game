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
#include "MonsterBullet.h"
#include "FPS.h"

enum MonsterType
{
    MONSTER_SMALL = 0,
    MONSTER_MEDIUM,
    MONSTER_BIG,
    MONSTER_MAX
};

static Monster monsters[10] = {};
static int spawnCount = 0;
static int moveCount = 0;
static int score = 0;

void MonsterStart()
{
    for (int i = 0; i < 10; i++)
    {
        if (monsters[i].Active == false)
        {
            monsters[i].Position.x = DF_BG_SIZE_X - 10;
            monsters[i].Position.y = (float)(rand() % (DF_BG_SIZE_Y - 10) + 5);
            monsters[i].Active = true;
            monsters[i].Type = rand() % MONSTER_MAX;

            // 기본 방향: 왼쪽 이동
            monsters[i].Direction.x = -1.0f;

            // 타입별 초기 위아래 방향 다르게
            switch (monsters[i].Type)
            {
            case MONSTER_SMALL:
                monsters[i].Direction.y = (float)((rand() % 3) - 1); // -1, 0, 1
                break;

            case MONSTER_MEDIUM:
                monsters[i].Direction.y = (float)((rand() % 3) - 1); // -1, 0, 1
                break;

            case MONSTER_BIG:
                monsters[i].Direction.y = 0.0f; // 큰 몬스터는 거의 직선
                break;
            }

            break;
        }
    }
}

void MonsterTick()
{
    spawnCount++;
    moveCount++;

    // 일정 주기로 몬스터 생성
    if (spawnCount >= 20)
    {
        MonsterStart();
        spawnCount = 0;
    }

    for (int i = 0; i < 10; i++)
    {
        if (monsters[i].Active)
        {
            switch (monsters[i].Type)
            {
            case MONSTER_SMALL:
                // 빠르고 자주 방향 바뀜
                if (moveCount % 2 == 0)
                {
                    monsters[i].Position.x += monsters[i].Direction.x;
                    monsters[i].Position.y += monsters[i].Direction.y;
                }

                if (rand() % 20 == 0)
                {
                    monsters[i].Direction.y = (float)((rand() % 3) - 1);
                }

                if (moveCount % 35 == 0)
                {
                    MonsterBulletFire(monsters[i].Position.x - 1, monsters[i].Position.y);
                }
                break;

            case MONSTER_MEDIUM:
                // 보통 속도, 적당히 흔들림
                if (moveCount % 3 == 0)
                {
                    monsters[i].Position.x += monsters[i].Direction.x;
                    monsters[i].Position.y += monsters[i].Direction.y;
                }

                if (rand() % 35 == 0)
                {
                    monsters[i].Direction.y = (float)((rand() % 3) - 1);
                }

                if (moveCount % 50 == 0)
                {
                    MonsterBulletFire(monsters[i].Position.x - 1, monsters[i].Position.y);
                }
                break;

            case MONSTER_BIG:
                // 느리고 직선 위주, 가끔만 위아래
                if (moveCount % 5 == 0)
                {
                    monsters[i].Position.x += monsters[i].Direction.x;
                    monsters[i].Position.y += monsters[i].Direction.y;
                }

                if (rand() % 80 == 0)
                {
                    monsters[i].Direction.y = (float)((rand() % 3) - 1);
                }

                if (moveCount % 70 == 0)
                {
                    MonsterBulletFire(monsters[i].Position.x - 1, monsters[i].Position.y);
                }
                break;
            }

            // 위쪽 벽에 닿으면 튕김
            if (monsters[i].Position.y < 0)
            {
                monsters[i].Position.y = 0;
                monsters[i].Direction.y *= -1;
            }

            // 아래쪽 벽에 닿으면 튕김
            if (monsters[i].Position.y > DF_BG_SIZE_Y - 2)
            {
                monsters[i].Position.y = DF_BG_SIZE_Y - 2;
                monsters[i].Direction.y *= -1;
            }

            // 왼쪽 화면 밖으로 나가면 제거
            if (monsters[i].Position.x < -3)
            {
                monsters[i].Active = false;
            }
        }
    }

    if (moveCount > 100000)
    {
        moveCount = 0;
    }
}

void MonsterDraw()
{
    for (int i = 0; i < 10; i++)
    {
        if (monsters[i].Active)
        {
            const char* shape = "<#>";

            switch (monsters[i].Type)
            {
            case MONSTER_SMALL:
                shape = "<!>";
                break;

            case MONSTER_MEDIUM:
                shape = "[X]";
                break;

            case MONSTER_BIG:
                shape = "{O}";
                break;
            }

            ScreenPrintUI(
                (SHORT)monsters[i].Position.x,
                (SHORT)monsters[i].Position.y,
                shape
            );
        }
    }
}

bool CheckMonsterCollision(float bulletX, float bulletY)
{
    for (int i = 0; i < 10; i++)
    {
        if (monsters[i].Active)
        {
            if ((int)bulletY == (int)monsters[i].Position.y)
            {
                if ((int)bulletX >= (int)monsters[i].Position.x &&
                    (int)bulletX <= (int)monsters[i].Position.x + 2)
                {
                    monsters[i].Active = false;

                    switch (monsters[i].Type)
                    {
                    case MONSTER_SMALL:
                        score += 10;
                        break;

                    case MONSTER_MEDIUM:
                        score += 20;
                        break;

                    case MONSTER_BIG:
                        score += 30;
                        break;
                    }

                    return true;
                }
            }
        }
    }

    return false;
}

bool CheckPlayerMonsterCollision(float playerX, float playerY)
{
    for (int i = 0; i < 10; i++)
    {
        if (monsters[i].Active)
        {
            if ((int)monsters[i].Position.y == (int)playerY)
            {
                int monsterLeft = (int)monsters[i].Position.x;
                int monsterRight = monsterLeft + 2;

                int playerLeft = (int)playerX;
                int playerRight = playerLeft + 2;

                if (!(playerRight < monsterLeft || playerLeft > monsterRight))
                {
                    monsters[i].Active = false;
                    return true;
                }
            }
        }
    }

    return false;
}

int GetScore()
{
    return score;
}