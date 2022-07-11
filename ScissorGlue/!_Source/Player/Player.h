#pragma once
/*****************************************************************//**
 * \file   Player.h
 * \brief  プレイヤーの処理部分
 * 
 * \author めざし
 * \date   July 2022
 *********************************************************************/
#include"../Object/ObjectBase.h"

class Game;

class Player:public ObjectBase
{
	typedef ObjectBase base;
public:
	//コンストラクタ
	Player();
	//デストラクタ
	~Player();

	void Init();
	void Process(Game& g);

private:

};
