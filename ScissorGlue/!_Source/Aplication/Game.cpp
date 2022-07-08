/*****************************************************************//**
 * \file   Game.cpp
 * \brief  ゲームの中身いろいろを呼び出して回したり
 * 
 * \author めざし
 * \date   June 2022a
 *********************************************************************/

#include"DxLib.h"
#include"Game.h"

 //プレイヤークラスのポインタ生成


//コンストラクタ
Game::Game()
{
	gKey = 0;
	gFrameCount = 0;
	gTrg = 0;

	// jsonからマップデータを構築する
	mapChips.LoadJson("res/", "platformer_simpleA.json");

	// プレイヤーを生成し、オブジェクトサーバに登録する
	objectServer.Add(new Player());
}

//デストラクタ
Game::~Game()
{
}

//入力
void Game::Input()
{
	//キーのトリガ情報生成
	CreateKeyTrg();
}

//計算
void Game::Update() 
{
	objectServer.Process(*this);
	mapChips.Process(*this);
	gFrameCount++;
}

//描画
void Game::Render()
{
	//画面初期化
	ClearDrawScreen();
	bg.Draw();
	mapChips.Draw();
	objectServer.Draw(*this);
	ScreenFlip();
}

//キーのトリガ情報生成。1フレーム前のキーの情報と比較してかつ入力されてるなら
void Game::CreateKeyTrg() {
	int oldKey = gKey;
	gKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	gTrg = (gKey ^ oldKey) & gKey;
}