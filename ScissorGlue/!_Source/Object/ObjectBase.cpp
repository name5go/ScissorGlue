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

//コンストラクタ
ObjectBase::ObjectBase()
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
	verticalInertia = 0;
	cnt = 0;
	cgNum = 1;
}
//計算
void ObjectBase::Process(Game& g)
{
	//重力処理と当たり判定
	if (g.mapChips.IsHit(*this, 0, verticalInertia) != 0)
	{
		if (verticalInertia > 0)
		{
			standFlag = 1;
		}
		verticalInertia = 0;
	}
	//接触していないなら重力処理を行う
	else
	{
		Gravity();
	}
	//カウントプラス
	cnt++;
}

//描画
void ObjectBase::Draw(Game& g)
{
	//ワールドの座標からカメラで見た座標に変更
	//画面上に描画する座標
	int x, y;
	x = xWorld + xCamera - g.mapChips.xScr;
	y = yWorld + yCamera - g.mapChips.yScr;
	//変更した座標に描画
	DrawGraph(x, y, cgPic[(cnt / 8) % cgNum], TRUE);
}

void ObjectBase::Gravity()
{
	verticalInertia += 1;
	yWorld += verticalInertia;
	standFlag = 0;
}
