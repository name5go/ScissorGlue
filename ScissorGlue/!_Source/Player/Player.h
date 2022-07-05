#pragma once
/*****************************************************************//**
 * \file   Player.h
 * \brief  プレイヤーの処理部分
 * 
 * \author めざし
 * \date   July 2022
 *********************************************************************/
#include"../Aplication/Game.h"

class Game;

class Player {
public:
	//コンストラクタ
	Player(Game& pGame);
	//デストラクタ
	~Player();

	//メンバ関数の宣言
	void Input();
	void Update();
	void Render();

	Game& g;
	int gh;//グラフィックハンドル、後でイメージサーバーのやつに変更忘れるな

private:
	//メンバ変数の宣言
	int xPlayer;//プレイヤーのX座標
	int yPlayer;//同Y座標
	float anglePlayer;//同角度
	float sizePlayer;//同描画拡大率
	int inertiaPlayer;//プレイヤーの加速度
	int inertiaMax;//最大速度というか内部蓄積慣性の最大値
	


	bool turnPlayerFlag;//プレイヤーの反転描画オンオフ


	
};
