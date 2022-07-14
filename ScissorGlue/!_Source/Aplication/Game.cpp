/*****************************************************************//**
 * \file   Game.cpp
 * \brief  ゲームの中身いろいろを呼び出して回したり
 * 
 * \author めざし
 * \date   June 2022aaa
 *********************************************************************/

#include"DxLib.h"
#include"Game.h"
#include<memory>

 //プレイヤークラスのポインタ生成


//コンストラクタ
Game::Game():pObj(*this)
{
	gKey = 0;
	gFrameCount = 0;
	gTrg = 0;

	// jsonからマップデータを構築する
	mapChips.LoadJson("!_Resources\\!_Pic\\mapchips\\", "map01.json");
	//各種クラスをポインタに追加
	auto player = std::make_unique<Player>(*this);
	pObj.Add(std::move(player));
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
//キーのトリガ情報生成。1フレーム前のキーの情報と比較してかつ入力されてるなら
void Game::CreateKeyTrg() {
	int oldKey = gKey;
	gKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	gTrg = (gKey ^ oldKey) & gKey;
}

//計算
void Game::Process() 
{
	pObj.Process(*this);
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
	pObj.Draw(*this);

	ScreenFlip();
}

