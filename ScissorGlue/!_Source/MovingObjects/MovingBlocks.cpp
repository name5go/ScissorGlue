/*****************************************************************//**
 * \file   MovingBlocks.cpp
 * \brief  動くブロック
 * 
 * \author めざし
 * \date   July 2022
 *********************************************************************/

#include"MovingBlocks.h"

//コンストラクタ
MovingBlocks::MovingBlocks()
{
	cgPic[0] = ImageServer::LoadGraph("!_Resources\\!_Pic\\moving_objects\\movingblock.png");
	Init();
}
void MovingBlocks::Init()
{
	cgNum = 1;
	wPic = 32;
	hPic = 48;
	xWorld = 32;
	yWorld = 100;
	xCamera = -wPic / 2;
	yCamera = -hPic + 1;
	besideInertia = 0;
	verticalInertia = 0;
	xHit = -16;
	yHit = -47;
	wHit = 32;
	hHit = 48;
}
//デストラクタ
MovingBlocks::~MovingBlocks()
{

}

//計算
void MovingBlocks::Process(Game& g)
{

}

