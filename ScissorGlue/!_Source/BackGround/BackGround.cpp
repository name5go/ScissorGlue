/*****************************************************************//**
 * \file   BackGround.cpp
 * \brief  
 * 
 * \author �߂���
 * \date   July 2022
 *********************************************************************/

#include"DxLib.h"
#include"BackGround.h"
#include"../Object/ImageServer.h"

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
