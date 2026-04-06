#pragma once
#include <iostream>
#include <vector>


struct Position
{
	int x;
	int y;
};

enum Direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Snake
{
private:
	std::vector<Position> body;
	bool grow;
	
public:
	void Init();
	void Move(Direction dir);
	bool IsOnBody(int x, int y) const; //food에게 위치를 알려주는 함수
	void Grow(); // food 만났을 때만 꼬리 제거를 멈추는 함수
	Position GetHead() const; // game한태 head위치 알려주는 함수
	const std::vector<Position>& GetBody() const; // snake의 전체 위치를 알려주는 함수



};


