#pragma once
#include <iostream>
#include "snake.h"

class Food
{
private:
	Position pos;

public:
	void Spawn(int width, int height, const Snake& snake);
	Position GetPosition() const;
	bool IsOnBody(int x, int y) const;
	
};

