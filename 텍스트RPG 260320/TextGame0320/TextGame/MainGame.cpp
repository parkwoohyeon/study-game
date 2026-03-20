#include "MainGame.h"
#include <iostream>
#include "hunting_ground.h"



//main함수에 들어갈 놈들
void MainGame::Start() {
	player.SelectJob();

}

void MainGame :: Update() {
	int input = 0;


	while (true) {
		system("cls");
		player.Render();
		std::cout << "1. 사냥터 2. 종료 \n ->" << std::endl;
		std::cin >> input;

		if (input == 1) {
			hunting.SelectGround();
			hunting.Render();
			break;
		}




		if (input == 2) {
			break;
		}
	}

}
