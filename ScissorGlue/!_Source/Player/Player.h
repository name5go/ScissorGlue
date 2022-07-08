#pragma once
/*****************************************************************//**
 * \file   Player.h
 * \brief  プレイヤーの処理部分
 * 
 * \author めざし
 * \date   July 2022
 *********************************************************************/
#include"../Aplication/Game.h"
#include"../Object/ObjectBase.h"

class Game;

class Player
	
{
public:
	//コンストラクタ
	Player(Game& pGame);
	//デストラクタ
	~Player();

	//メンバ関数の宣言
	void Input();
	void Update();
	void Render();

	//ゲームクラスのポインタ
	Game& game;

	int gh;//グラフィックハンドル、後でイメージサーバーのやつに変更忘れるな

private:
	//プレイヤーのX座標
	int xPlayer;
	//同Y座標
	int yPlayer;
	//同角度
	float anglePlayer;
	//同描画拡大率
	float sizePlayer;
	//プレイヤーの加速度
	int inertiaPlayer;
	//最大速度というか内部蓄積慣性の最大値
	int inertiaMax;
	//地面接触フラグ
	int standFlag;
	//重力
	int gravityPlayer;
	
	
	
	//プレイヤーの反転描画オンオフ
	bool turnPlayerFlag;
	
};
