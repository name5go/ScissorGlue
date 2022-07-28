/*****************************************************************//**
 * \file   Player.cpp
 * \brief  プレイヤークラス
 * 
 * \author めざし
 * \date   July 2022
 *********************************************************************/

#include"Player.h"

//コンストラクタ
Player::Player(Game& g):
	pG(g)
{
	pG._obj.Add(new Scissor(*this, pG._mapChips));
	//画像の読み込み___後でイメージサーバーのハンドル取得に書き換える
	cgPic[0] = ImageServer::LoadGraph("!_Resources\\!_Pic\\player\\ball.png");
	Init();
}

//デストラクタ
Player::~Player()
{
}

//プレイヤー情報の初期化
void Player::Init()
{
	LeftRight = 1;
	cgNum = 1;
	wPic = 32;
	hPic = 48;
	xWorld = 32;
	yWorld = 0;
	xCamera = -wPic / 2;
	yCamera = -hPic + 1;
	besideInertia = 0;
	verticalInertia = 0;
	xHit = -16;
	yHit = -47;
	wHit = 32;
	hHit = 48;
}

//入力
void Player::Process(Game& g)
{
	CheckInput(g);
	ObjectBase::Process(g);

	// 主人公位置からのカメラ座標決定
	g._mapChips.xScr = xWorld - (SCREEN_W / 2);		// 画面の横中央にキャラを置く
	g._mapChips.yScr = yWorld - (SCREEN_H * 7 / 10);	// 画面の縦70%にキャラを置く
	
}

void Player::CheckInput(Game& g)
{
	
	//WASDの入力を登録
	constexpr auto A_KEY = PAD_INPUT_4;
	constexpr auto D_KEY = PAD_INPUT_6;
	constexpr auto W_KEY = PAD_INPUT_8;
	constexpr auto S_KEY = PAD_INPUT_5;
	constexpr auto X_KEY = PAD_INPUT_2;

	//左押されてたら左方向
	if (g.gKey & PAD_INPUT_LEFT || g.gKey & A_KEY)
	{
		LeftRight = -1;
		//ボタンを押された時の処理
		xWorld -= 1;
		g._mapChips.IsHit(*this, -1, 0);		// 左に動いたので、x移動方向をマイナス指定
	}

	//右押されてたら右方向
	if (g.gKey & PAD_INPUT_RIGHT || g.gKey & D_KEY)
	{
		LeftRight = 1;
		//ボタンを押された時の処理
		//描画の反転をオン
		xWorld += 1;
		g._mapChips.IsHit(*this, 1, 0);			// 右に動いたので、x移動方向をプラス指定
	}

	//g.gKey & PAD_INPUT_A ||
	//ジャンプ
	if (g.gTrg & W_KEY)
	{
		if (standFlag == 1)
		{
			verticalInertia = -20;
			//ジャンプ処理
		}
	}
}
