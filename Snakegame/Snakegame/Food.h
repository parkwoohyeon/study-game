#pragma once
#include <iostream>
#include "snake.h"

enum FoodType {
	NORMAL,
	BONUS,
	STEAL
};

class Food
{
private:
	Position pos;
	FoodType type;
	

public:
	void Spawn(int width, int height, const Snake& snake1, const Snake& snake2);
	Position GetPosition() const;
	FoodType GetType() const;
	
	
};

