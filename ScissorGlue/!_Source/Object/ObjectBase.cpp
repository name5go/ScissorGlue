/*
** オブジェクト
*/

#include "DxLib.h"
#include "ObjectBase.h"
#include "../Aplication/Game.h"

ObjectBase::ObjectBase()
{
	Init();
}

ObjectBase::~ObjectBase()
{
}

void ObjectBase::Init()
{
	_g = 0;
	_cnt = 0;
	_cgNum = 1;
}

void ObjectBase::Process(Game& g)
{
	// 重力処理を行う
	_g += 1;			// キャラの、重力による加速値を大きくする
	_y += _g;			// 重力による加速値の分だけ移動する
	_stand = 0;			// 床に当たってないことを前提に、床フラグリセット

	// 上下の当たり判定
	if (g._mapChips.IsHit(*this, 0, _g) != 0)
	{
		// 当たった。当たったのは床か？（重力値はプラスだったか？）
		if (_g > 0)
		{
			_stand = 1;	// 床に当たったのでフラグセット
		}
		_g = 0;		// 重力による加速値をリセット
	}

	_cnt++;
}

void ObjectBase::Draw(Game& g)
{
	// カメラから見た座標に変更（ワールド座標→ビュー座標）
	int x, y;
	x = _x + _vx - g._mapChips._scrX;
	y = _y + _vy - g._mapChips._scrY;
	DrawGraph(x, y, _cg[(_cnt / 8) % _cgNum], TRUE);

	// 開発用。当たり判定を表示する
//	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		// 半透明描画指定
//	DrawBox(x + _hit_x, y + _hit_y, x + _hit_x + _hit_w, y + _hit_y + _hit_h, GetColor(255, 0, 0), TRUE);	// 半透明の赤で当たり判定描画
//	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// 不透明描画指定

}
