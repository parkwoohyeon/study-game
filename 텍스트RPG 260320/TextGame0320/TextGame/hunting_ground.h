#pragma once
#include<string>
#include <iostream>

class hunting_ground

{
private:
	std::string place;
	int placeLevel;
	std::string monster;
	FightGame fight;

public:
	void SelectGround();
	void Render();


};
