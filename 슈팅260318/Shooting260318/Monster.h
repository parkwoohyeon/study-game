#pragma once
#include "Struct.h"

void MonsterStart();
void MonsterTick();
void MonsterDraw();

bool CheckMonsterCollision(float bulletX, float bulletY);
bool CheckPlayerMonsterCollision(float playerX, float playerY);
int GetScore();