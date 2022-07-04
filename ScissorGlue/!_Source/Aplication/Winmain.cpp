/*****************************************************************//**
 * \file   winmain.cpp
 * \brief  エントリーポイント
 * 
 * \author mezashi
 * \date   June 2022
 *********************************************************************/

#include<DxLib.h>
#include <stdio.h>
#include <time.h>
#include<memory>
#include"Game.h"


//エントリーポイント
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	OutputDebugString("---Winmain開始---\n");

	//ウィンドウモード変更
	ChangeWindowMode(TRUE);
	
	//画面解像度を1920x1080でカラービット数を32bitに設定
	SetGraphMode(wScreen, hScreen, depthScreen);
	
	//DXライブラリを初期化
	DxLib_Init();
	
	//描画先画面を裏にする
	SetDrawScreen(DX_SCREEN_BACK);
	
	// 乱数初期化
	srand((unsigned int)time(NULL));
	
	
	//ゲームクラスのポインタ作成
	auto pGame = std::make_unique<Game>();
	
	
	//ゲームのメインループescapeで終了
	while (ProcessMessage() != -1)
	{
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}
//各種命令ぶっこみ
		pGame->Input;//入力
		pGame->Process;//計算
		pGame->Draw;//描画
	}
	// Dxライブラリ終了
	DxLib_End();
	return 0;
}
