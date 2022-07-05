#pragma once
/*****************************************************************//**
 * \file   Player.h
 * \brief  プレイヤーの処理部分
 * 
 * \author めざし
 * \date   July 2022
 *********************************************************************/

class Player {
public:
	//コンストラクタ
	Player();
	//デストラクタ
	~Player();

	//メンバ関数の宣言
	void Input();
	void Update();
	void Render();

	//メンバ変数の宣言
	int xPlayer;
	int yPlayer;
	int playerSpeed;

};
