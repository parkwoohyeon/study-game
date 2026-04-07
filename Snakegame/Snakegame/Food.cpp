#include "Food.h"
#include <iostream>
#include <cstdlib>


void Food::Spawn(int width, int height, const Snake& snake1, const Snake& snake2)
{
    while (true)
    {
        int x = rand() % width;
        int y = rand() % height;

        if (!snake1.IsOnBody(x, y) && !snake2.IsOnBody(x, y))
        {
            pos.x = x;
            pos.y = y;

            //20% 확률로 보너스 먹이
            int r = rand() % 100;

            if (r < 10)
                type = STEAL;      // 10%
            else if (r < 30)
                type = BONUS;      // 20%
            else
                type = NORMAL;     // 70%

            break;
        }
    }
}

Position Food::GetPosition() const
{
    return pos;
}

FoodType Food::GetType() const {
    return type;
}