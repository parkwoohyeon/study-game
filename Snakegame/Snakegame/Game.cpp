#include "Game.h"
#include "Food.h"
#include "snake.h"
#include <iostream>
#include <Windows.h>
#include <algorithm>

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
    score1 = 0;
    score2 = 0;
    gameover = false;
    winner = 0;

    delayTime = 80;

    snake1.Init(10, 10);
    snake2.Init(80, 20);

    foods.clear();
    foods.resize(15);

    for (auto& food : foods)
    {
        food.Spawn(width, height, snake1, snake2);
    }
}


void Game::Update()
{
    bool moved1 = false;
    bool moved2 = false;

    // 플레이어1 : WASD
    if (GetAsyncKeyState('W') & 0x8000)
    {
        snake1.Move(UP);
        moved1 = true;
    }
    else if (GetAsyncKeyState('S') & 0x8000)
    {
        snake1.Move(DOWN);
        moved1 = true;
    }
    else if (GetAsyncKeyState('A') & 0x8000)
    {
        snake1.Move(LEFT);
        moved1 = true;
    }
    else if (GetAsyncKeyState('D') & 0x8000)
    {
        snake1.Move(RIGHT);
        moved1 = true;
    }

    // 플레이어2 : 방향키
    if (GetAsyncKeyState(VK_UP) & 0x8000)
    {
        snake2.Move(UP);
        moved2 = true;
    }
    else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
    {
        snake2.Move(DOWN);
        moved2 = true;
    }
    else if (GetAsyncKeyState(VK_LEFT) & 0x8000)
    {
        snake2.Move(LEFT);
        moved2 = true;
    }
    else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
    {
        snake2.Move(RIGHT);
        moved2 = true;
    }

    if (!moved1 && !moved2)
        return;

    Position head1 = snake1.GetHead();
    Position head2 = snake2.GetHead();
    

    // 여러 먹이 처리
    for (auto& food : foods)
    {
        Position foodPos = food.GetPosition();

        if (head1.x == foodPos.x && head1.y == foodPos.y)
        {

            if (food.GetType() == BONUS)
            {
                score1 += 3;
                snake1.Grow(3);
            }
            else if (food.GetType() == STEAL)
            {
                score1 += 2;

                if (score2 > 0) 
                {
                    score2 -= 1;
                    snake2.Shrink(1);

                }
                    

                snake1.Grow(2);
            }
            else
            {
                score1 += 1;
                snake1.Grow(1);
            }
                food.Spawn(width, height, snake1, snake2);
        }
        else if (head2.x == foodPos.x && head2.y == foodPos.y)
        {
            

            if (food.GetType() == BONUS)
            {
                score2 += 3;
                snake2.Grow(3);
            }
            else if (food.GetType() == STEAL)
            {
                score2 += 2;
                if (score1 > 0) 
                {
                    score1 -= 1;
                    snake1.Shrink(1);
                }
                    

                snake2.Grow(2);
            }
            else
            {
                score2 += 1;
                snake2.Grow(1);
            }
                

            food.Spawn(width, height, snake1, snake2);
        }
    }

    // 점수 높을수록 속도 증가
    int maxScore = max(score1, score2);
    delayTime = 80 - (maxScore / 5) * 10;
    if (delayTime < 30)
        delayTime = 30;

    // 벽 충돌
    if (head1.x < 0 || head1.x >= width || head1.y < 0 || head1.y >= height)
    {
        winner = 2;
        gameover = true;
        return;
    }

    if (head2.x < 0 || head2.x >= width || head2.y < 0 || head2.y >= height)
    {
        winner = 1;
        gameover = true;
        return;
    }

    //충돌 발생 여부만 체크
    bool collision = false;

    //머리끼리 충돌 했을때
    if (head1.x == head2.x && head1.y == head2.y) {
        collision = true;
    }

    //플레이어1 머리가 플레이어2 몸에 닿음
    if (snake2.IsOnBodyExceptHead(head1.x, head1.y)) {
        collision = true;
    }

    //플레이어2 머리가 플레이어1 몸에 닿음
    if (snake1.IsOnBodyExceptHead(head2.x, head2.y)) {
        collision = true;
    }



    
    if (collision)
    {
        int len1 = snake1.GetLength();
        int len2 = snake2.GetLength();

        if (len1 > len2)
        {
            winner = 1;
            gameover = true;
            return;
        }
        else if (len2 > len1)
        {
            winner = 2;
            gameover = true;
            return;
        }
        else
        {
            return;
        }
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
        Sleep(delayTime);
    }

    GoToXY(0, height + 4);

    SetColor(12);
    std::cout << "GAME OVER!\n";

    SetColor(14);
    std::cout << "Player 1 Score : " << score1 << '\n';

    SetColor(13);
    std::cout << "Player 2 Score : " << score2 << '\n';

    SetColor(15);
    if (winner == 1)
        std::cout << "Winner : Player 1\n";
    else if (winner == 2)
        std::cout << "Winner : Player 2\n";
    else
        std::cout << "No Winner\n";

    SetColor(7);
}

void Game::Render() const
{
    Position head1 = snake1.GetHead();
    Position head2 = snake2.GetHead();

    for (int y = -1; y <= height; y++)
    {
        for (int x = -1; x <= width; x++)
        {
            bool isFood = false;
            FoodType foodType = NORMAL;

            for (const auto& food : foods)
            {
                Position foodPos = food.GetPosition();
                if (x == foodPos.x && y == foodPos.y)
                {
                    isFood = true;
                    foodType = food.GetType();
                    break;
                }
            }

            if (x == -1 || x == width || y == -1 || y == height)
            {
                SetColor(11);
                std::cout << "■";
            }
            else if (isFood)
            {
                if (foodType == BONUS)
                {
                    SetColor(13);
                    std::cout << "◆";
                }
                else if (foodType == STEAL)
                {
                    SetColor(12);
                    std::cout << "$";
                }
                else
                {
                    SetColor(14);
                    std::cout << "★";
                }
            }
            else if (x == head1.x && y == head1.y)
            {
                SetColor(14);
                std::cout << "@";
            }
            else if (x == head2.x && y == head2.y)
            {
                SetColor(13);
                std::cout << "#";
            }
            else if (snake1.IsOnBody(x, y))
            {
                SetColor(10);
                std::cout << "O";
            }
            else if (snake2.IsOnBody(x, y))
            {
                SetColor(9);
                std::cout << "X";
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
    std::cout << "P1 Score : " << score1 << "    Move : W A S D\n";
    std::cout << "P2 Score : " << score2 << "    Move : Arrow Keys\n";
    std::cout << "Speed Delay : " << delayTime << '\n';
    std::cout << "Normal : ★(+1)   Bonus : ◆(+3)   Steal : $(+2 / enemy -1)\n";

    SetColor(7);
}