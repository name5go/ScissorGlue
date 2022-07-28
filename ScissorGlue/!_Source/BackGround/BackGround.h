#pragma once
/*****************************************************************//**
 * \file   BackGround.h
 * \brief  背景処理
 * 
 * \author めざし
 * \date   July 2022
 *********************************************************************/
#include"../PCH/pch.h"
#include<winsock.h>

class BackGround
{
public:
	//コンストラクタ
	BackGround();
	//デストラクタ
	~BackGround();

	void Draw();

private:
	//画像
	int cgPic;
};
