/*****************************************************************//**
 * \file   BackGround.cpp
 * \brief  
 * 
 * \author �߂���
 * \date   July 2022
 *********************************************************************/

#include"../PCH/stdafx.h"
#include<winsock.h>

//�R���X�g���N�^
BackGround::BackGround()
{
	//�w�i�摜�����[�h
	cgPic = ImageServer::LoadGraph("!_Resources\\!_Pic\\background\\background.png");
}

//�f�X�g���N�^
BackGround::~BackGround()
{
}

void BackGround::Draw()
{
	DrawGraph(0, 0, cgPic, FALSE);
}
