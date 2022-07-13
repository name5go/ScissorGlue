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
#include"../Player/Player.h"

//�R���X�g���N�^
ObjectBase::ObjectBase(Game& g)
	:pGame(g)
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
		if (verticalInertia > 0)
		{
			standFlag = 1;
		}
		verticalInertia = 0;
	}
	//�ڐG���Ă��Ȃ��Ȃ�d�͏������s��
	else
	{
		Gravity();
	}
	//�J�E���g�v���X
	cnt++;
}

//�`��
void ObjectBase::Draw(Game& g)
{
	
	//���[���h�̍��W����J�����Ō������W�ɕύX
	//��ʏ�ɕ`�悷����W
	int x, y;
	x = xWorld + xCamera - g.mapChips.xScr;
	y = yWorld + yCamera - g.mapChips.yScr;
	//�ύX�������W�ɕ`��
	DrawGraph(x, y, cgPic[(cnt / 8) % cgNum], TRUE);



	// �J���p�B�����蔻���\������
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		// �������`��w��
	DrawBox(x + xHit, y + yHit, x + xHit + wHit, y + yHit + hHit, GetColor(255, 0, 0), TRUE);	// �������̐Ԃœ����蔻��`��
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// �s�����`��w��

}

void ObjectBase::Gravity()
{
	verticalInertia += 1;
	yWorld += verticalInertia;
	standFlag = 0;
}
