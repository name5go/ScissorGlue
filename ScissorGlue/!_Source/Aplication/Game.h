/*****************************************************************//**
 * \file   Game.h
 * \brief  ゲームクラス
 * 
 * \author めざし
 * \date   June 2022
 *********************************************************************/

#pragma once

#include"../Player/Player.h"
#include	"../Object/ObjectServer.h"
#include	"../BackGround/BackGround.h"
#include	"../Map/MapChips.h"

//画面設定
constexpr auto SCREEN_W = 1280;		//< 画面の横解像度
constexpr auto SCREEN_H = 720;		//< 画面の縦解像度
constexpr auto SCREEN_DEPTH = 32;   ///< １ドットあたりのビット数

//ゲームクラス
class Game 
{
public:
	//コンストラクタ
	Game();
	//デストラクタ
	~Game();

	//入力
	void Input();
	//計算
	void Process();
	//描画
	void Render();
	//キー情報の生成
	void CreateKeyTrg();

	//キー情報
	int gKey;
	//一回押し判定
	int gTrg;
	//フレームカウント
	int gFrameCount;

	BackGround bg;
	MapChips mapChips;

protected:
	ObjectServer pObj;
	
};
