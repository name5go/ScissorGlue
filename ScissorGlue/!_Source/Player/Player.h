#pragma once
/*****************************************************************//**
 * \file   Player.h
 * \brief  �v���C���[�̏�������
 * 
 * \author �߂���
 * \date   July 2022
 *********************************************************************/
#include"../Aplication/Game.h"

class Game;

class Player {
public:
	//�R���X�g���N�^
	Player(Game& pGame);
	//�f�X�g���N�^
	~Player();

	//�����o�֐��̐錾
	void Input();
	void Update();
	void Render();

	Game& g;
	int gh;//�O���t�B�b�N�n���h���A��ŃC���[�W�T�[�o�[�̂�ɕύX�Y����

private:
	//�����o�ϐ��̐錾
	int xPlayer;//�v���C���[��X���W
	int yPlayer;//��Y���W
	float anglePlayer;//���p�x
	float sizePlayer;//���`��g�嗦
	int inertiaPlayer;//�v���C���[�̉����x
	int inertiaMax;//�ő呬�x�Ƃ����������~�ϊ����̍ő�l
	


	bool turnPlayerFlag;//�v���C���[�̔��]�`��I���I�t


	
};
