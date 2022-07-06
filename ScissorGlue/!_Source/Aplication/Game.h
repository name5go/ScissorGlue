/*****************************************************************//**
 * \file   Game.h
 * \brief  ゲームクラス
 * 
 * \author めざし
 * \date   June 2022
 *********************************************************************/

#pragma once

#include<DxLib.h>
#include<memory>
#include"../Player/Player.h"
#include	"../Object/ObjectServer.h"
#include	"../BackGround/BackGround.h"
#include	"../Map/MapChips.h"

class Player;

//画面設定
constexpr auto SCREEN_W = 1920;		//< 画面の横解像度
constexpr auto SCREEN_H = 1080;		//< 画面の縦解像度
constexpr auto SCREEN_DEPTH = 32;   ///< １ドットあたりのビット数

//ゲームクラス
class Game 
{
public:
	Game();//コンストラクタ
	~Game();//デストラクタ
	
	std::unique_ptr<Player>pPlayer;

	// 背景
	BackGround	_bg;

	// マップチップ
	MapChips	_mapChips;

	// オブジェクトサーバ
	ObjectServer	_objServer;		// プレイヤーや敵などを登録する

	//関数
	void Input();//入力
	void Update();//計算
	void Render();//描画
	void CreateKeyTrg();

	//メンバ変数宣言
	int gKey;
	int gTrg;
	int gFrameCount;
};
