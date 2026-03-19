#include "MonsterBullet.h"
#include "DoubleBuffering.h"
#include "Defines.h"
#include "Struct.h"
static Bullet monsterBullets[30] = {};
static float monsterBulletSpeed = 1.0f;

void MonsterBulletFire(float x, float y) {
	for (int i = 0; i < 30; i++) {
		if (monsterBullets[i].Active == false) {
			monsterBullets[i].Position.x = x;
			monsterBullets[i].Position.y= y;
			monsterBullets[i].Active = true;
			break;
		}
	}
}

void MonsterBulletTick()
{
    for (int i = 0; i < 30; i++)
    {
        if (monsterBullets[i].Active)
        {
            monsterBullets[i].Position.x -= monsterBulletSpeed;

            if (monsterBullets[i].Position.x < 0)
            {
                monsterBullets[i].Active = false;
            }
        }
    }
}

void MonsterBulletDraw()
{
    for (int i = 0; i < 30; i++)
    {
        if (monsterBullets[i].Active)
        {
            ScreenPrintUI(
                (SHORT)monsterBullets[i].Position.x,
                (SHORT)monsterBullets[i].Position.y,
                "-"
            );
        }
    }
}