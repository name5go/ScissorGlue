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
	Player();
	//デストラクタ
	~Player();
	virtual OBJECTTYPE GetType() { return ObjectBase::OBJECTTYPE::PLAYER; }

	void Init();//初期化
	void Process(Game& g);//プロセス
  void CheckInput(Game& g);//入力


	void UpdatePlayerPos() { int xPl = xWorld; int yPl = yWorld; }

public:
	//左右の向きフラグ1右-1左
	int LeftRight;

};
