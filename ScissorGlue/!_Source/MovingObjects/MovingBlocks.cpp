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
	flagLR = 0;
	cgPic[0] = ImageServer::LoadGraph("!_Resources\\!_Pic\\moving_objects\\movingblock.png");
	Init();
}
void MovingBlocks::Init()
{
	cgNum = 3;
	wPic = 80;
	hPic = 20;
	xWorld = 64;
	yWorld = 64;
	xCamera = -wPic / 2;
	yCamera = -hPic + 1;
	besideInertia = -1;
	verticalInertia = 0;
	xHit = -40;
	yHit = -20;
	wHit = 80;
	hHit = 20;

	pos.x = 0; pos.y = 0;
	size.x = 0; size.y = 0;
}
//デストラクタ
MovingBlocks::~MovingBlocks()
{

}

//計算
void MovingBlocks::Process(Game& g)
{
	//左右移動
	xWorld+=besideInertia;
	flagLR += 1;
	if (flagLR > 150)
	{
		besideInertia *= -1;
		flagLR = 0;
	}
	/*
	for (auto ite = g._obj.List()->begin(); ite != g._obj.List()->end(); ite++)
	{
		if ((*ite)->GetType() == ObjectBase::OBJECTTYPE::PLAYER) {
			// プレイヤーとの当たり判定を行う
			if (IsHit(*(*ite))) {
				// 当たった。自分を消す
				g._objServer.Del(this);
	}
	*/

	UpdateCollision();
}

void MovingBlocks::UpdateCollision()
{
	pos.x = xWorld; pos.y = yWorld;
	size.x = wHit+10; size.y = hHit+10;
	collision.min = pos;
	collision.max = pos + size;

	//開発用当たり判定描画
	collision.Draw(rand() % 256, rand() % 256, rand() % 256);
}
