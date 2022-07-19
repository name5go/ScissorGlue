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
	Player(Game& g);
	//デストラクタ
	~Player();
	virtual Type	GetType() { return Type::kPlayer; }

	void Init();
	void Process(Game& g) override;
  void CheckInput(Game& g);

private:

};
