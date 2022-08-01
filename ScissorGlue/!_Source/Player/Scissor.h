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



class Scissor:public ObjectBase
{
public:
	Scissor(Player& p, MapChips& mp);//�R���X�g���N�^
	~Scissor();//�f�X�g���N�^
	virtual OBJECTTYPE GetType() { return ObjectBase::OBJECTTYPE::SCISSOR; }

	void Init();//������
	void Process(Game& g);//�v�Z
	void Input(Game& g);//����

	void ScissorPos(Game& g);


	Player& _p;
	MapChips& _mp;
	

public:
	int xCursor; int yCursor;//�؂����̏ꏊ
	MapChip saveMapChips[2 * 2]; //�؂�����̈ꎞ�ۑ��p
	MapChip saveRotateChips[2 * 2];//��]�p�ꎞ�ۑ�

	int xCutPos;
	int yCutPos;
	int CutDekiru;
};
