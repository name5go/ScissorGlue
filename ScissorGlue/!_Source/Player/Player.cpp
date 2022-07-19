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
#include"../Aplication/Game.h"
#include"../Object/ImageServer.h"
#include"../Object/ImageServer.h"

//コンストラクタ
Player::Player(Game& g)
	:base(g)
{
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
	base::Init();
	cgNum = 1;
	size.x = 32;size.y= 48;//画像の大きさxy
	pos.x = 32;pos.y = 0;//xy座標
	xCamera = wPic / 2;yCamera = hPic + 1;//基準位置から描画時の差分
	besideInertia = 0;verticalInertia = 0;//横と縦の慣性
	colPos.x = 0; colPos.y = 0;//当たり判定の座標
	colSize.x = 32; colSize.y = 48;//当たり判定の大きさ
	/**
	 * 	当たり判定更新の計算(場所はobjectBase)
	 * 
	 * collision.min = pos + colPos;
	 * collision.max = pos + colPos + colSize;.
	 * 
	 */
}

//入力
void Player::Process(Game& g)
{
	CheckInput(g);
	ObjectBase::Process(g);
	ObjectBase::UpdateCollision();

	// 主人公位置からのカメラ座標決定
	g.mapChips.xScr = pos.x - (SCREEN_W / 2);		// 画面の横中央にキャラを置く
	g.mapChips.yScr = pos.y - (SCREEN_H * 7 / 10);	// 画面の縦70%にキャラを置く
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
		//ボタンを押された時の処理
		pos.x -= 1;
		g.mapChips.IsHit(*this, -1, 0);		// 左に動いたので、x移動方向をマイナス指定
	}

	//右押されてたら右方向
	if (g.gKey & PAD_INPUT_RIGHT || g.gKey & D_KEY)
	{

		//ボタンを押された時の処理
		//描画の反転をオン
		pos.x += 1;
		g.mapChips.IsHit(*this, 1, 0);			// 右に動いたので、x移動方向をプラス指定
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
