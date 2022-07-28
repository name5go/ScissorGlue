/*****************************************************************//**
 * \file   Scissor.cpp
 * \brief  
 * 
 * \author めざし
 * \date   July 2022
 *********************************************************************/
#include"../Player/Scissor.h"

//コンストラクタ
Scissor::Scissor()
{
	cgPic[0] = ImageServer::LoadGraph("!_Resources\\!_Pic\\player\\ball.png");
	Init();
}
//初期化
void Scissor::Init()
{
	cgNum = 1;
	wPic = 32;
	hPic = 48;
	xWorld = 32;
	yWorld = 0;
	xCamera = wPic / 2;
	yCamera = hPic + 1;
	besideInertia = 0;
	verticalInertia = 0;
	xHit = -16;
	yHit = -47;
	wHit = 32;
	hHit = 48;
}

//デストラクタ
Scissor::~Scissor()
{
}

//計算
void Scissor::Process(Game& g)
{
  
	Input(g);
}
//入力
void Scissor::Input(Game& g)
{

}
