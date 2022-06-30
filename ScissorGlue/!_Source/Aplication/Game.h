/*****************************************************************//**
 * \file   Game.h
 * \brief  ゲームクラス
 * 
 * \author めざし
 * \date   June 2022
 *********************************************************************/

#pragma once

#include<DxLib.h>

//画面設定
constexpr auto wScreen = 1920;		//< 画面の横解像度
constexpr auto hScreen = 1080;		//< 画面の縦解像度
constexpr auto depthScreen = 32;   ///< １ドットあたりのビット数

//ゲームクラス
class Game {
public:
	Game();//コンストラクタ
	~Game();//デストラクタ

	//関数
	void Input();//入力
	void Process();//計算
	void Draw();//描画

	//メンバ変数宣言
	int gKey;
	int gTrg;
	int gFrameCount;

};
