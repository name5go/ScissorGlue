#pragma once
/*****************************************************************//**
 * \file   Scissor.h
 * \brief  
 * 
 * \author �߂���
 * \date   July 2022
 *********************************************************************/

#include"../PCH/stdafx.h"
#include<winsock.h>
#include"../Object/ObjectBase.h"//�I�u�W�F�N�g�x�[�X

class Scissor:public ObjectBase
{
public:
	Scissor();//�R���X�g���N�^
	~Scissor();//�f�X�g���N�^
	virtual OBJECTTYPE GetType() { return ObjectBase::OBJECTTYPE::SCISSOR; }

	void Init();//������
	void Process(Game& g);//�v�Z
	void Input(Game& g);//����

public:
	int xCursor; int yCursor;
	int saveMapChips[2*2]={0,0,0,0};

};
