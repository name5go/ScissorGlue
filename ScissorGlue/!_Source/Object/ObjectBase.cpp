/*****************************************************************//**
 * \file   ObjectBase.cpp
 * \brief  オブジェクトベース
 * 
 * \author めざし
 * \date   July 2022
 *********************************************************************/

#include<DxLib.h>
#include"ObjectBase.h"
#include"../Aplication/Game.h"
#include"../Player/Player.h"


//コンストラクタ
ObjectBase::ObjectBase(Game& g)
	:pGame(g)
{
	Init();
}
//デストラクタ
ObjectBase::~ObjectBase()
{
}
//初期化
void ObjectBase::Init()
{
	pos.x = 0; pos.y = 0;
	colPos.x = 0; colPos.y = 0;
	colSize.x = 0; colSize.y = 0;
	cnt = 0;
}
//計算
void ObjectBase::Process(Game& g)
{
	//重力処理
	Gravity(g);
	//カウント
	cnt++;
}
//重力処理//地面に接触していれば落下しない
void ObjectBase::Gravity(Game& g)
{
	if (g.mapChips.IsHit(*this, 0, verticalInertia) != 0)
	{
		if (verticalInertia > 0)
		{
			standFlag = 1;
		}
		verticalInertia = 0;
	}
	verticalInertia += 1;
	yWorld += verticalInertia;
	standFlag = 0;
}

//描画
void ObjectBase::Draw(Game& g)
{
	//ワールドの座標からカメラで見た座標に変更
	int x, y;	//画面上に描画する座標
	x = xWorld + xCamera - g.mapChips.xScr;
	y = yWorld + yCamera - g.mapChips.yScr;
	//変更した座標に描画
	DrawGraph(x, y, cgPic[(cnt / 8) % cgNum], TRUE);
}

//当たり判定の更新
void ObjectBase::UpDateCollision()
{
	collision.min = pos + colPos;
	collision.max = pos + colPos + colSize;
}

void ObjectBase::DrawCollision()
{
	collision.Draw(rand() % 256, rand() % 256, rand() % 256);
}
