/*****************************************************************//**
 * \file   ObjectBase.cpp
 * \brief  �I�u�W�F�N�g�x�[�X
 * 
 * \author �߂���
 * \date   July 2022
 *********************************************************************/

#include<DxLib.h>
#include"ObjectBase.h"
#include"../Aplication/Game.h"

//�R���X�g���N�^
ObjectBase::ObjectBase()
{
	Init();
}
//�f�X�g���N�^
ObjectBase::~ObjectBase()
{
}
//������
void ObjectBase::Init()
{
	verticalInertia = 0;
	cnt = 0;
	cgNum = 1;
}
//�v�Z
void ObjectBase::Process(Game& g)
{
	//�d�͏����Ɠ����蔻��
	if (g.mapChips.IsHit(*this, 0, verticalInertia) != 0)
	{

	}
}
