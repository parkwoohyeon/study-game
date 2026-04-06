#include "Game.h"
#include "Food.h"
#include "snake.h"
#include <iostream>
#include <Windows.h>

void GoToXY(int x, int y)
{
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

void SetColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


void Game::Init()
{
    system("mode con cols=120 lines 35");

    width = 100;
    height = 30;
	score = 0;
	gameover = false;

	snake.Init();
	food.Spawn(width, height, snake);

}


void Game::Update()
{
    bool moved = false;

    if (GetAsyncKeyState('W') & 0x8000)
    {
        snake.Move(UP);
        moved = true;
    }
    else if (GetAsyncKeyState('S') & 0x8000)
    {
        snake.Move(DOWN);
        moved = true;
    }
    else if (GetAsyncKeyState('A') & 0x8000)
    {
        snake.Move(LEFT);
        moved = true;
    }
    else if (GetAsyncKeyState('D') & 0x8000)
    {
        snake.Move(RIGHT);
        moved = true;
    }

    if (!moved)
        return;

    Position head = snake.GetHead();
    Position foodpos = food.GetPosition();

    if (head.x == foodpos.x && head.y == foodpos.y)
    {
        snake.Grow();
        score++;
        food.Spawn(width, height, snake);
    }

    if (head.x < 0 || head.x >= width || head.y < 0 || head.y >= height)
    {
        gameover = true;
    }
}


void Game::Run()
{
    Init();

    while (!gameover)
    {
        Update();
        GoToXY(0, 0);
        Render();
        Sleep(50);
    }

    GoToXY(0, height + 4);
    SetColor(12);
    std::cout << "GAME OVER!\n";
    SetColor(15);
    std::cout << "Final Score : " << score << '\n';
    SetColor(7);
}




void Game::Render() const
{
    Position head = snake.GetHead();
    Position foodPos = food.GetPosition();

    for (int y = -1; y <= height; y++)
    {
        for (int x = -1; x <= width; x++)
        {
            if (x == -1 || x == width || y == -1 || y == height)
            {
                SetColor(11);
                std::cout << "■";
            }
            else if (x == foodPos.x && y == foodPos.y)
            {
                SetColor(12);
                std::cout << "★";
            }
            else if (x == head.x && y == head.y)
            {
                SetColor(14);
                std::cout << "@";
            }
            else if (snake.IsOnBody(x, y))
            {
                SetColor(10);
                std::cout << "O";
            }
            else
            {
                SetColor(7);
                std::cout << " ";
            }
        }
        std::cout << '\n';
    }

    SetColor(15);
    std::cout << "Score : " << score << '\n';
    std::cout << "Move  : W A S D\n";

    SetColor(7);
}