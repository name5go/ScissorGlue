#pragma once
/*****************************************************************//**
 * \file   ObjectBase.h
 * \brief  �I�u�W�F�N�g�x�[�X
 * 
 * \author �߂���
 * \date   July 2022
 *********************************************************************/

#include"../Collision/Collision.h"
#include"../Math/Math.h"

class Game;

//�I�u�W�F�N�g�N���X
class ObjectBase
{
public:
	//�R���X�g���N�^
	ObjectBase(Game& g);
	//�f�X�g���N�^
	virtual ~ObjectBase();

	//��ʂ̗�
	enum class Type {
		kBase,//0�x�[�X
		kPlayer,//1�v���C���[
		kBackGround,//2�w�i
		kEnemy,//3�G�l�~�[
	};
	virtual Type GetType() = 0;

	//������
	virtual void Init();
	//�v�Z
	virtual void Process(Game& g);
	//�`��
	void Draw(Game& g);

	//AABB�𗘗p�����R���W��������Ƃ��̍X�V
	virtual void UpDateCollision();
	virtual void DrawCollision();
	virtual AABB& GetCollision() { return collision; }
	virtual Vector2& GetPosition() { return pos; }
	virtual void SetPosition(Vector2 pPos) { pos = pPos; }
	virtual Vector2& GetSize() { return size; }
	virtual void SetSize(Vector2 pSize) { size = pSize; }

	//�_���[�W����̏����ɕK�v�Ȃ��̂̒ǉ�


	//�v���Z�X�Ɋ܂܂��ړ�����̌v�Z
	
	//�ړ�����̖���//���E�ړ��ƃW�����v�����������ɓ�������Ȃ��ƖY���ȁI
	void Gravity(Game& g);


public:
	Game& pGame;

	int cgPic[2];//�摜
	int cgNum;	//�摜����
	int xWorld, yWorld;	//���[���h���W��X��Y
	int xCamera, yCamera;	//�`�掞�̍��W
	int wPic, hPic;	//�摜�̏c�̑傫���Ɖ��̑傫��

	int besideInertia,verticalInertia;	//�����~�ϊ����A�����牡�����Əc����
	int besideSpeed,verticalSpeed;	//�X�s�[�h�i���̉����x	//�d�͂̋���(�c�̉����x
	
	int standFlag;	//�ڒn�t���O0��1�n��
	
	int xHit, yHit;	//�����蔻��p
	int wHit, hHit;

protected:
	AABB collision;//�����蔻��
	Vector2 pos;//���W
	Vector2 size;//�T�C�Y
	Vector2 colPos, colSize;//�����蔻��̈ʒu�ƃT�C�Y
	
	int cnt;	//�J�E���g
};
