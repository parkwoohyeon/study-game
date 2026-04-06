#include "snake.h"
#include <iostream>
#include <vector>


void Snake::Init()
{
    body.clear();
    body.push_back({ 5, 3 });
    body.push_back({ 4, 3 });
    body.push_back({ 3, 3 });

    
    grow = false;
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

    if (!grow)
        body.pop_back();
    else
        grow = false;
}



void Snake::Grow() 
{
	grow = true;

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






Position Snake :: GetHead() const //어쩌피 위치만 알려주고 상태는 안바뀌니깐 const씀
{
	return body[0];
}

const std::vector<Position>& Snake::GetBody() const
{
	return body;
}