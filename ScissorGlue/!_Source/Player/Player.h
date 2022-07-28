#pragma once
/*****************************************************************//**
 * \file   Player.h
 * \brief  プレイヤーの処理部分
 * 
 * \author めざし
 * \date   July 2022
 *********************************************************************/
#include"../PCH/pch.h"
#include<winsock.h>

class Game;

class Player:public ObjectBase
{
	typedef ObjectBase base;
public:
	//コンストラクタ
	Player(Game& g);
	//デストラクタ
	~Player();

	void Init();
	void Process(Game& g) override;
  void CheckInput(Game& g);

private:

};
