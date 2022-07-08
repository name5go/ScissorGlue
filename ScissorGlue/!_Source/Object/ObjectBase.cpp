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

	}
}
