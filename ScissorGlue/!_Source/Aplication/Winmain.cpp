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
#include"../Aplication/Game.h"


//エントリーポイント
int WINAPI WinMain(
	_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,_In_ LPSTR lpCmdLine, _In_ int nCmdShow)
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
	
	
	//ゲームクラスのポインタ生成
	auto pGame = std::make_unique<Game>();
	
	
	//ゲームのメインループescapeで終了
	while (ProcessMessage() != -1)
	{
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}
//各種命令ぶっこみ
		pGame->Input();//入力
		pGame->Update();//計算
		ClearDrawScreen();
		pGame->Render();//描画
		ScreenFlip();
	}
	// Dxライブラリ終了
	DxLib_End();
	return 0;
}
