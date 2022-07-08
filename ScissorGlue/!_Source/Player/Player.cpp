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
#include"../Object/ImageServer.h"

//コンストラクタ
Player::Player(Game& pGame) :
	game(pGame),
	//Playerメンバ変数の初期化
	xPlayer(0), yPlayer(0),//プレイヤー座標を0,0で初期化
	inertiaPlayer(0),//プレイヤーの慣性
	gravityPlayer(0),
	inertiaMax(20),//最大速度
	sizePlayer(1.0),//プレイヤーの描画倍率
	anglePlayer(0.0),//プレイヤーの角度
	turnPlayerFlag(FALSE),//プレイヤーの反転フラグ
	standFlag(0)

{
	//画像の読み込み___後でイメージサーバーのハンドル取得に書き換える
	gh = ImageServer::LoadGraph("!_Resources\\!_Pic\\player\\ball.png");
}

//デストラクタ
Player::~Player()
{
}

//入力
void Player::Input()
{
//WASDの入力を登録
	constexpr auto A_KEY = PAD_INPUT_4;
	constexpr auto D_KEY = PAD_INPUT_6;
	constexpr auto W_KEY = PAD_INPUT_8;
	constexpr auto S_KEY = PAD_INPUT_5;
	constexpr auto X_KEY = PAD_INPUT_2;

	//左押されてたら左方向
	if(game.gKey&PAD_INPUT_LEFT||game.gKey&A_KEY)
	{
		//ボタンを押された時の処理
		turnPlayerFlag = FALSE;
			inertiaPlayer -= 3;
	}

	//右押されてたら右方向
	if (game.gKey & PAD_INPUT_RIGHT||game.gKey&D_KEY )
	{
		//ボタンを押された時の処理
		//描画の反転をオン
		turnPlayerFlag = TRUE;
		inertiaPlayer += 3;
	}

	//g.gKey & PAD_INPUT_A ||
	//ジャンプ
	if (game.gTrg & W_KEY)
	{
		if(standFlag==1)
		{
			gravityPlayer = -25;
		}
	}
}

//描画
void Player::Render()
{
	DrawRotaGraph(xPlayer, yPlayer, sizePlayer, anglePlayer, gh, TRUE, turnPlayerFlag);
}


//更新
void Player::Update()
{
	//座標の反映
	xPlayer += inertiaPlayer;
	yPlayer += gravityPlayer;

//	重力処理過去のやつ
if (yPlayer > 1000)
	{
		gravityPlayer = 0;
		standFlag = 1;
	}
	else
	{
		standFlag = 0;
		gravityPlayer += 1;
	
	}


//減速処理時間に余裕あるならベクトルとか絶対値基準で書き直したい
if (inertiaPlayer < 0)
{
	inertiaPlayer += 1;
}
if (inertiaPlayer > 0)
{
	inertiaPlayer -= 1;
}

//最大速度の処理これも時間があればベクトルで書き換えたい
if (inertiaPlayer > inertiaMax)
{
	inertiaPlayer = inertiaMax;
}
if (inertiaPlayer < -1 * inertiaMax)
{
	inertiaPlayer = -1 * inertiaMax;
}


}
