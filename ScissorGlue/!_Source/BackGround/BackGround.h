#pragma once
/*****************************************************************//**
 * \file   BackGround.h
 * \brief  �w�i����
 * 
 * \author �߂���
 * \date   July 2022
 *********************************************************************/
#include"../PCH/pch.h"
#include<winsock.h>

class BackGround
{
public:
	//�R���X�g���N�^
	BackGround();
	//�f�X�g���N�^
	~BackGround();

	void Draw();

private:
	//�摜
	int cgPic;
};
