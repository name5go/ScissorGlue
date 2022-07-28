/*****************************************************************//**
 * \file   ObjectBase.cpp
 * \brief  オブジェクトベース
 * 
 * \author めざし
 * \date   July 2022
 *********************************************************************/

#include"ObjectBase.h"

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
	//接触していないなら重力処理を行う
	Gravity();
	//重力処理と当たり判定
	if (g._mapChips.IsHit(*this, 0, verticalInertia) != 0)
	{
		if (verticalInertia > 0)
		{
			standFlag = 1;
		}
		verticalInertia = 0;
	}
	//カウントプラス
	cnt++;
}
void ObjectBase::Gravity()
{
	verticalInertia += 1;
	yWorld += verticalInertia;
	standFlag = 0;
}



//描画
void ObjectBase::Draw(Game& g)
{
	
	//ワールドの座標からカメラで見た座標に変更
	//画面上に描画する座標
	int x, y;
	x = xWorld + xCamera - g._mapChips.xScr;
	y = yWorld + yCamera - g._mapChips.yScr;
	//変更した座標に描画
	DrawGraph(x, y, cgPic[(cnt / 8) % cgNum], TRUE);

	// 開発用。当たり判定を表示する
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		// 半透明描画指定
	DrawBox(x + xHit, y + yHit, x + xHit + wHit, y + yHit + hHit, GetColor(255, 0, 0), TRUE);	// 半透明の赤で当たり判定描画
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// 不透明描画指定

}

