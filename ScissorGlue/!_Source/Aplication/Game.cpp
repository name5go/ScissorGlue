/*****************************************************************//**
 * \file   Game.cpp
 * \brief  ゲームの中身いろいろを呼び出して回したり
 * 
 * \author めざし
 * \date   June 2022a
 *********************************************************************/

#include"Game.h"

 //プレイヤークラスのポインタ生成


//コンストラクタ
Game::Game():
	gKey(0),
	gTrg(0),
	gFrameCount(0)
{
	//プレイヤークラスのポインタ生成
	 pPlayer = std::make_unique<Player>(*this);
//画像周りの読み込み処理つっこみたい
	// _mapChips.LoadJson("res/", "platformer_simpleA.json");
}

//デストラクタ
Game::~Game(){}

//入力
void Game::Input() {
	//キーのトリガ情報生成
	CreateKeyTrg();
	//それぞれのクラスの命令を回す。
	pPlayer->Input();
}

//計算
void Game::Update() 
{
	//それぞれのクラスの命令を回す。
	pPlayer->Update();
}

//描画
void Game::Render()
{
	//それぞれのクラスの命令を回す。
	pPlayer->Render();
}

//キーのトリガ情報生成。1フレーム前のキーの情報と比較してかつ入力されてるなら
void Game::CreateKeyTrg() {
	int oldKey = gKey;
	gKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	gTrg = (gKey ^ oldKey) & gKey;
}