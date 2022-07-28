#pragma once
/*****************************************************************//**
 * \file   Player.h
 * \brief  プレイヤーの処理部分
 * 
 * \author めざし
 * \date   July 2022
 *********************************************************************/
#include"../PCH/stdafx.h"
#include<winsock.h>
#include"../Object/ObjectBase.h"//オブジェクトベース

class Game;

class Player:public ObjectBase
{
public:
	//コンストラクタ
	Player(Game& g);
	//デストラクタ
	~Player();
	virtual OBJECTTYPE GetType() { return ObjectBase::OBJECTTYPE::PLAYER; }

	void Init();//初期化
	void Process(Game& g);//プロセス
  void CheckInput(Game& g);//入力

	Game& pG;


 int xPl() { return xWorld; }
 int yPl() { return yWorld; }
	

public:
	//左右の向きフラグ1右-1左
	int LeftRight;

};
