/*****************************************************************//**
 * \file   winmain.cpp
 * \brief  エントリーポイント
 * 
 * \author mezashi
 * \date   June 2022
 *********************************************************************/

#include<DxLib.h>


int CALLBACK winmain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
	OutputDebugString("---Winmain開始---\n");
	//ウィンドウモード変更
	ChangeWindowMode(TRUE);
	//画面解像度を1920x1080でカラービット数を32bitに設定
	SetGraphMode(1920, 1080, 32);
	//DXライブラリを初期化
	DxLib_Init();
	//描画先画面を裏にする
	SetDrawScreen(DX_SCREEN_BACK);

	//いろいろクラスを突っ込むところ

	//ゲームのメインループescapeで終了
	while (ProcessMessage() != -1) {
		if (CheckHitKey(KEY_INPUT_ESCAPE)) {
			break;
		}

		//クラスつっこむ
	}
}
