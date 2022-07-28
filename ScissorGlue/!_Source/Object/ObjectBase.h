#pragma once
/*****************************************************************//**
 * \file   ObjectBase.h
 * \brief  �I�u�W�F�N�g�x�[�X
 * 
 * \author �߂���
 * \date   July 2022
 *********************************************************************/
#include"../PCH/stdafx.h"
#include<winsock.h>

//�I�u�W�F�N�g�N���X
class ObjectBase
{
public:
	//�R���X�g���N�^
	ObjectBase();
	//�f�X�g���N�^
	~ObjectBase();

	enum class OBJECTTYPE
	{
		PLAYER,
		SCISSOR,
	};
	virtual OBJECTTYPE GetType() = 0;

	//������
	virtual void Init();
	//�v�Z
	virtual void Process(Game&g);
	//�`��
	virtual void Draw(Game&g);

	

	//�v���Z�X�Ɋ܂܂��ړ�����̌v�Z
	
	//�ړ�����̖���
	//void GoFoward();
	//void GoBack();
	void Gravity();
	//void Jump();

public:

	//�摜
	int cgPic[32];
	//�摜����
	int cgNum;
	//���[���h���W��X��Y
	int xWorld, yWorld;
	//�`�掞�̍��W
	int xCamera, yCamera;
	//�摜�̏c�̑傫���Ɖ��̑傫��
	int wPic, hPic;

	//�����~�ϊ����A�����牡�����Əc����
	int besideInertia,verticalInertia;
	//�X�s�[�h�i���̉����x	//�d�͂̋���(�c�̉����x
	int besideSpeed,verticalSpeed;
	
	//�ڒn�t���O0��1�n��
	int standFlag;
	//���E�̌����t���O1�E-1��
	int LeftRight;
	
	//�����蔻��p
	int xHit, yHit;
	int wHit, hHit;
	
	//����J�E���^
	int cnt;
};
