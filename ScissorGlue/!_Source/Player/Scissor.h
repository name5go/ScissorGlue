#pragma once
/*****************************************************************//**
 * \file   Scissor.h
 * \brief  
 * 
 * \author めざし
 * \date   July 2022
 *********************************************************************/

#include"../PCH/stdafx.h"
#include<winsock.h>



class Scissor:public ObjectBase
{
public:
	Scissor(Player& p, MapChips& mp);//コンストラクタ
	~Scissor();//デストラクタ
	virtual OBJECTTYPE GetType() { return ObjectBase::OBJECTTYPE::SCISSOR; }

	void Init();//初期化
	void Process(Game& g);//計算
	void Input(Game& g);//入力

	void ScissorPos(Game& g);


	Player& _p;
	MapChips& _mp;
	

public:
	int xCursor; int yCursor;
	int saveMapChips[2*2]={0,0,0,0};
	int xCutPos;
	int yCutPos;
	int CutDekiru;
};
