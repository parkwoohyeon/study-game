#pragma once
#include "Player.h"
#include "hunting_ground.h"
#include "FightGame.h"
class MainGame

{
	
private :
	Player player;
	hunting_ground hunting;
	Monster monster;
	FightGame fight;

public:

	void Start();
	void Update();

};

