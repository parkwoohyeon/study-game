#include "snake.h"
#include <iostream>
#include <vector>


void Snake::Init(int startX, int startY)
{
    body.clear();
    body.push_back({ startX, startY });
    body.push_back({ startX - 1, startY });
    body.push_back({ startX - 2, startY });

    growCount = 0;
}


void Snake::Move(Direction dir)
{

    Position head = body.front();

    switch (dir)
    {
    case UP:    head.y--; break;
    case DOWN:  head.y++; break;
    case LEFT:  head.x--; break;
    case RIGHT: head.x++; break;
    default: break;
    }

    body.insert(body.begin(), head);

    if (growCount > 0)
    {
        growCount--;
    }
    else
    {
        body.pop_back();
    }
}



void Snake::Grow(int amount) 
{
    growCount += amount;

}



// food한태 snake의 위치를 알려주는 함수(랜덤으로 생성될 때 food랑 snake랑 겹치면 안되니깐 여기서 검사를 한번 해줘야함)
bool Snake::IsOnBody(int x, int y) const
{
    for (const auto& part : body)
    {
        if (part.x == x && part.y == y)
            return true;
    }
    return false;
}

// 머리 제외 몸통만 검사
bool Snake::IsOnBodyExceptHead(int x, int y) const
{
    for (size_t i = 1; i < body.size(); i++)
    {
        if (body[i].x == x && body[i].y == y)
            return true;
    }
    return false;
}




Position Snake :: GetHead() const //어쩌피 위치만 알려주고 상태는 안바뀌니깐 const씀
{
	return body[0];
}

const std::vector<Position>& Snake::GetBody() const
{
	return body;
}


int Snake::GetLength() const
{
    return (int)body.size();
}


//상대가 steal을 먹었을때 길이를 줄이는 함수
void Snake::Shrink(int amount)
{
    for (int i = 0; i < amount; i++) {
        if(body.size() > 3) // 최소 길이 유지
        {
            body.pop_back();
        }
    }

    
}