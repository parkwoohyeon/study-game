#pragma once
#include "snake.h"
#include "Food.h"
class Game
{
private:
	int width;
	int height;
	int score;
	bool gameover;
	
	Snake snake;
	Food food;


public:
	void Init();
	void Update();
	void Run();
	void Render() const;

};

