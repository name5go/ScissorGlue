/*****************************************************************//**
 * \file   winmain.cpp
 * \brief  エントリーポイント
 * 
 * \author mezashi
 * \date   June 2022
 *********************************************************************/

#include"../PCH/stdafx.h"
#include<winsock.h>


//エントリーポイント
int WINAPI WinMain(
	_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,_In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	//画面解像度を1920x1080でカラービット数を32bitに設定
	SetGraphMode(SCREEN_W, SCREEN_H, SCREEN_DEPTH);
	//ウィンドウモード変更
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)
	{	// エラーが起きたら直ちに終了
		return -1;
	}
	//描画先画面を裏にする
	SetDrawScreen(DX_SCREEN_BACK);
	
	// 乱数初期化
	srand((unsigned int)time(NULL));
	
	//各種リソースサーバー初期化
	ImageServer::Init();
	
	//ゲームクラスのポインタ生成
	Game *g = new Game();
	
	
	//ゲームのメインループescapeで終了
	while (ProcessMessage() ==0)
	{
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}
		//各種命令ぶっこみ
		g->Input();//入力
		g->Process();//計算
		g->Render();//描画
	}

	//イメージサーバー解放
	ImageServer::Release();
	//ゲームクラスの解放
	delete g;
	// Dxライブラリ終了
	DxLib_End();
	return 0;
}
