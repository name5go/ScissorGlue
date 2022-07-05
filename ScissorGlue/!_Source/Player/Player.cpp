/*****************************************************************//**
 * \file   Player.cpp
 * \brief  プレイヤークラスの処理内容
 * 
 * \author めざし
 * \date   July 2022
 *********************************************************************/

#include<DxLib.h>
#include"Player.h"
#include"Math.h"

//コンストラクタ
Player::Player(Game& pGame) :
	g(pGame),
	//Playerメンバ変数の初期化
	xPlayer(0), yPlayer(0),//プレイヤー座標を0,0で初期化
	inertiaPlayer(0),//プレイヤーの慣性
	inertiaMax(30),//最大速度
	sizePlayer(1.0),//プレイヤーの描画倍率
	anglePlayer(0.0),//プレイヤーの角度
	turnPlayerFlag(FALSE)//プレイヤーの反転フラグ
{
	//画像の読み込み___後でイメージサーバーのハンドル取得に書き換えるの忘れない
	gh = LoadGraph("ScissorGlue / !_Resources / !_Pic / player / ball.png");
}

//デストラクタ
Player::~Player()
{
}

//入力
void Player::Input()
{
	constexpr auto A_KEY = PAD_INPUT_4;
	constexpr auto D_KEY = PAD_INPUT_6;
	constexpr auto W_KEY = PAD_INPUT_8;
	constexpr auto S_KEY = PAD_INPUT_5;
	constexpr auto X_KEY = PAD_INPUT_2;

	//左押されてたら左方向
	if(g.gKey&PAD_INPUT_LEFT||g.gKey&A_KEY)
	{
		//ボタンを押された時の処理
		//加速が最大速度以下なら増やし続ける
		if(inertiaPlayer<inertiaMax)
		{
			inertiaPlayer += 2;
		}

	}

	//右押されてたら右方向
	if (g.gKey & PAD_INPUT_RIGHT || g.gKey & D_KEY)
	{
		//ボタンを押された時の処理
		//描画の反転をオン
		//加速が最大速度以下なら増やし続ける
		turnPlayerFlag = TRUE;
		if (inertiaPlayer < inertiaMax)
		{
			inertiaPlayer += 2;
		}
	}

}

//更新
void Player::Update()
{


	//慣性とその減速
	if (inertiaPlayer > 0)
	{
		inertiaPlayer -= 1;
	}

}

//描画
void Player::Render()
{
	DrawRotaGraph(xPlayer, yPlayer, sizePlayer, anglePlayer, gh, TRUE, turnPlayerFlag);
}
