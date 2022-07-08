#pragma once
/*****************************************************************//**
 * \file   Player.h
 * \brief  �v���C���[�̏�������
 * 
 * \author �߂���
 * \date   July 2022
 *********************************************************************/
#include"../Aplication/Game.h"
#include"../Object/ObjectBase.h"

class Game;

class Player
	
{
public:
	//�R���X�g���N�^
	Player(Game& pGame);
	//�f�X�g���N�^
	~Player();

	//�����o�֐��̐錾
	void Input();
	void Update();
	void Render();

	//�Q�[���N���X�̃|�C���^
	Game& game;

	int gh;//�O���t�B�b�N�n���h���A��ŃC���[�W�T�[�o�[�̂�ɕύX�Y����

private:
	//�v���C���[��X���W
	int xPlayer;
	//��Y���W
	int yPlayer;
	//���p�x
	float anglePlayer;
	//���`��g�嗦
	float sizePlayer;
	//�v���C���[�̉����x
	int inertiaPlayer;
	//�ő呬�x�Ƃ����������~�ϊ����̍ő�l
	int inertiaMax;
	//�n�ʐڐG�t���O
	int standFlag;
	//�d��
	int gravityPlayer;
	
	
	
	//�v���C���[�̔��]�`��I���I�t
	bool turnPlayerFlag;
	
};
