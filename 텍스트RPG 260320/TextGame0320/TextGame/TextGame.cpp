#include <iostream>
#include "MainGame.h"
#include "Player.h"
#include <Windows.h>
//main함수
int main()
{


    MainGame maingame; 
    {
        maingame.Start();
        maingame.Update();
    }
}

//3.20처음 스스로 생각하면서 코드를 작성 하고 있는 클래스를 활용한 텍스트 RPG
//근데 너무 클래스만 생각하다 보니 역할 이런 것들이 뭔가 꼬이는 듯한 느낌이 들었다 여기서 막혔는데 일단 오늘은 기본적인 틀 플레이어 클래스, 사냥터 클래스, 몬스터 클래스 까지 했고 전투 구현 하면 댐
//전투 구현 할려다 뭔가 꼬인게 느껴짐ㅋㅋ 집에서 다시 한번 생각 해보며 해봐야겠다 일단 오늘은 이렇게 깃에 올릴 예정

//3.21 지금 전투 구현 하는거 까지 했는데 한글깨짐만 일단 해결하면 될 것 같음 오늘은 일단 이렇게 깃에 올린다