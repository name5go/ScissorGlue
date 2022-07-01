/*****************************************************************//**
 * \file   Game.cpp
 * \brief  ゲームクラス
 * 
 * \author めざし
 * \date   June 2022a
 *********************************************************************/

#include"Game.h"
#include<DxLib.h>

//コンストラクタ
Game::Game():
	gKey(0),
	gTrg(0),
	gFrameCount(0)
{
	//jsonからマップデータを読み取る
	mapChips.LoadJson("map01.jason")

		//playerを作ってオブジェクトサーバーに登録
	objectServer.Add(new Player());
}

//デストラクタ
Game::~Game(){}

//入力
void Game::Input() {
	int oldKey = gKey;
	gKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	gTrg = (gKey ^ oldKey) & gKey;//キーのトリガ情報生成。1フレーム前のキーの情報と比較してかつ入力されてるなら
}


//計算
void Game::Process() {
	objectServer.Process(*this);
	mapChips.Process(*this)
}

//描画
void Game::Drae() {
	CleaDrawScreen();
	backGround.Draw();
	mapChips.Draw();
	objectServer.Draw();
	ScreenFlip();
}
