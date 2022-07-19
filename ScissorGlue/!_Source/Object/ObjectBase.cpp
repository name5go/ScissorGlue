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
	pos.x = 0; pos.y = 0;//�`����W�̃��Z�b�g
	colPos.x = 0; colPos.y = 0;//�R���W�����̍��W���Z�b�g
	colSize.x = 0; colSize.y = 0;//�����蔻��̑傫�����Z�b�g
	cnt = 0;//�J�E���g
}
//�v�Z
void ObjectBase::Process(Game& g)
{
	//�d�͏���
	Gravity(g);
	//�J�E���g
	cnt++;
}
//�d�͏���//�n�ʂɐڐG���Ă���Η������Ȃ�
void ObjectBase::Gravity(Game& g)
{
	if (g.mapChips.IsHit(*this, 0, verticalInertia) != 0)
	{
		if (verticalInertia > 0)
		{
			standFlag = 1;
		}
		verticalInertia = 0;
	}
	verticalInertia += 1;
	pos.y += verticalInertia;
	standFlag = 0;
}

//�`��
void ObjectBase::Draw(Game& g)
{
	//���[���h�̍��W����J�����Ō������W�ɕύX
	int x, y;	//��ʏ�ɕ`�悷����W
	x = pos.x + xCamera - g.mapChips.xScr;
	y = pos.y + yCamera - g.mapChips.yScr;
	//�ύX�������W�ɕ`��
	DrawGraph(x, y, cgPic[(cnt / 8) % cgNum], TRUE);
}

//�����蔻��̍X�V
void ObjectBase::UpdateCollision()
{
	collision.min = pos + colPos;
	collision.max = pos + colPos + colSize;
}
//�����蔻��̕`��
void ObjectBase::DrawCollision()
{
	collision.Draw(rand() % 256, rand() % 256, rand() % 256);
}
//�_���[�W����
void ObjectBase::Damage()
{
	//�_���[�W�󂯂����̏����������ɏ����񂾂��I�Y���ȁI
}
