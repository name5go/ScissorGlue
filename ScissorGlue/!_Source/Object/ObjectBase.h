#pragma once
/*****************************************************************//**
 * \file   ObjectBase.h
 * \brief  �I�u�W�F�N�g�x�[�X
 * 
 * \author �߂���
 * \date   July 2022
 *********************************************************************/

class Game;

//�I�u�W�F�N�g�N���X
class ObjectBase
{
public:
	//�R���X�g���N�^
	ObjectBase();
	//�f�X�g���N�^
	~ObjectBase();

	//�I�u�W�F�N�g�^�C�v
	enum class OBJECTTYPE
	{
		PLAYER,
	};
	virtual OBJECTTYPE GetType() = 0;

	//������
	void Init();
	//�v�Z
	void Process(Game&g);
	//�`��
	void Draw(Game&g);

	//�v���Z�X�Ɋ܂܂��ړ�����̌v�Z
	
	//�ړ�����̖���
	void GoFoward();
	void GoBack();
	void Gravity();
	void Jump();

public:
	//�摜
	int cgPic[2];
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
	int stand;
	
	//�����蔻��p
	int xHit, yHit;
	int wHit, hHit;
	
	//����J�E���^
	int cnt;
};
