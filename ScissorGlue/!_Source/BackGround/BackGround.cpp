/*****************************************************************//**
 * \file   BackGround.cpp
 * \brief  
 * 
 * \author めざし
 * \date   July 2022
 *********************************************************************/

#include"../PCH/stdafx.h"
#include<winsock.h>

//コンストラクタ
BackGround::BackGround()
{
	//背景画像をロード
	cgPic = ImageServer::LoadGraph("!_Resources\\!_Pic\\background\\background.png");
}

//デストラクタ
BackGround::~BackGround()
{
}

void BackGround::Draw()
{
	DrawGraph(0, 0, cgPic, FALSE);
}
