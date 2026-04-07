#pragma once
#include "snake.h"
#include "Food.h"


class Game
{
private:
	int width;
	int height;

	int score1;
	int score2;

	int delayTime;
	bool gameover;
	int winner; // 0 = 없음, 1 = player1, 2 = player2

	Snake snake1;
	Snake snake2;
	std::vector<Food> foods; // 먹이 여러개 변경


public:
	void Init();
	void Update();
	void Run();
	void Render() const;

};

