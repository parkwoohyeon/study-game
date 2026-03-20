#pragma once
#include <Windows.h>

struct Vector2
{
    float x;
    float y;
};

typedef struct Transform
{
    Vector2 Position;
    Vector2 Direction;
    bool Active;
} Player, Bullet;

struct Monster
{
    Vector2 Position;
    Vector2 Direction;
    bool Active;
    int Type;
};