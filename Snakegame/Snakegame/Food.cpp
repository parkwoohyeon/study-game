#include "Food.h"
#include <iostream>
#include <vector>

void Food::Spawn(int width, int height, const Snake& snake)
{
	while (true)
	{
		int x = rand() % width;
		int y = rand() % height;

		if (!snake.IsOnBody(x, y)) {
			pos.x = x;
			pos.y = y;
			break;
		}
	}
}

Position Food::GetPosition() const 
{
	return pos;
}