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
	pos.x = 0; pos.y = 0;//描画座標のリセット
	colPos.x = 0; colPos.y = 0;//コリジョンの座標リセット
	colSize.x = 0; colSize.y = 0;//当たり判定の大きさリセット
	cnt = 0;//カウント
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
	pos.y += verticalInertia;
	standFlag = 0;
}

//描画
void ObjectBase::Draw(Game& g)
{
	//ワールドの座標からカメラで見た座標に変更
	int x, y;	//画面上に描画する座標
	x = pos.x + xCamera - g.mapChips.xScr;
	y = pos.y + yCamera - g.mapChips.yScr;
	//変更した座標に描画
	DrawGraph(x, y, cgPic[(cnt / 8) % cgNum], TRUE);
}

//当たり判定の更新
void ObjectBase::UpdateCollision()
{
	collision.min = pos + colPos;
	collision.max = pos + colPos + colSize;
}
//当たり判定の描画
void ObjectBase::DrawCollision()
{
	collision.Draw(rand() % 256, rand() % 256, rand() % 256);
}
//ダメージ処理
void ObjectBase::Damage()
{
	//ダメージ受けた時の処理をここに書くんだぞ！忘れるな！
}
