#include "Bullet.h"
#include "DoubleBuffering.h"
#include "Defines.h"
#include "Monster.h"
#include "Collision.h"
static Bullet bullets[300] = {};
static float bulletSpeed = 1.0f;

void BulletFire(float x, float y)
{
    for (int i = 0; i < 300; i++)
    {
        if (bullets[i].Active == false)
        {
            bullets[i].Position.x = x;
            bullets[i].Position.y = y;
            bullets[i].Active = true;
            break;
        }
    }
}

void BulletTick()
{
    for (int i = 0; i < 300;i++)
    {
        if (bullets[i].Active)
        {
            bullets[i].Position.x += bulletSpeed;
            if (CheckMonsterCollision(bullets[i].Position.x, bullets[i].Position.y))
            {
                bullets[i].Active = false;
            }

            if (bullets[i].Position.x > DF_BG_SIZE_X - 1)
            {
                bullets[i].Active = false;
            }
        }
    }
}

void BulletDraw()
{
    for (int i = 0; i < 300; i++)
    {
        if (bullets[i].Active)
        {
            ScreenPrintUI(
                (SHORT)bullets[i].Position.x,
                (SHORT)bullets[i].Position.y,
                ">"
            );
        }
    }
}

bool ClashAdnBullet(const Transform* const Target){
    for(int i = 0; i < )

}