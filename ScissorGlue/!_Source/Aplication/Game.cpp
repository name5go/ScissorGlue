/*****************************************************************//**
 * \file   Game.cpp
 * \brief  ゲームの中身いろいろを呼び出して回したり
 * 
 * \author めざし
 * \date   June 2022a
 *********************************************************************/
#include"Game.h"

//コンストラクタ
Game::Game()
{
	gKey = 0;
	gFrameCount = 0;
	gTrg = 0;

	// jsonからマップデータを構築する
	_mapChips.LoadJson("!_Resources\\!_Pic\\mapchips\\", "map01.json");
	//各種クラスを追加
		// プレイヤーを生成し、オブジェクトサーバに登録する
	_obj.Add(new Player());
	_obj.Add(new Scissor());
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
void Game::Process() 
{
	_obj.Process(*this);//オブジェクトサーバー
	_mapChips.Process(*this);//マップチップ
	gFrameCount++;
}

//描画
void Game::Render()
{
	//画面初期化
	ClearDrawScreen();
	_bg.Draw();//背景描画
	_mapChips.Draw(*this);//マップチップ
	_obj.Draw(*this);//オブジェクトサーバー
	ScreenFlip();
}

//キーのトリガ情報生成。1フレーム前のキーの情報と比較してかつ入力されてるなら
void Game::CreateKeyTrg() {
	int oldKey = gKey;
	gKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	gTrg = (gKey ^ oldKey) & gKey;
}