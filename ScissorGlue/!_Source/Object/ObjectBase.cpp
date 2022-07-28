/*****************************************************************//**
 * \file   ObjectBase.cpp
 * \brief  �I�u�W�F�N�g�x�[�X
 * 
 * \author �߂���
 * \date   July 2022
 *********************************************************************/

#include"ObjectBase.h"

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
	//�ڐG���Ă��Ȃ��Ȃ�d�͏������s��
	Gravity();
	//�d�͏����Ɠ����蔻��
	if (g._mapChips.IsHit(*this, 0, verticalInertia) != 0)
	{
		if (verticalInertia > 0)
		{
			standFlag = 1;
		}
		verticalInertia = 0;
	}
	//�J�E���g�v���X
	cnt++;
}
void ObjectBase::Gravity()
{
	verticalInertia += 1;
	yWorld += verticalInertia;
	standFlag = 0;
}



//�`��
void ObjectBase::Draw(Game& g)
{
	
	//���[���h�̍��W����J�����Ō������W�ɕύX
	//��ʏ�ɕ`�悷����W
	int x, y;
	x = xWorld + xCamera - g._mapChips.xScr;
	y = yWorld + yCamera - g._mapChips.yScr;
	//�ύX�������W�ɕ`��
	DrawGraph(x, y, cgPic[(cnt / 8) % cgNum], TRUE);

	// �J���p�B�����蔻���\������
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		// �������`��w��
	DrawBox(x + xHit, y + yHit, x + xHit + wHit, y + yHit + hHit, GetColor(255, 0, 0), TRUE);	// �������̐Ԃœ����蔻��`��
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// �s�����`��w��

}

