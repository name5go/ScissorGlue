#pragma once
/*****************************************************************//**
 * \file   Player.h
 * \brief  �v���C���[�̏�������
 * 
 * \author �߂���
 * \date   July 2022
 *********************************************************************/

class Player {
public:
	//�R���X�g���N�^
	Player();
	//�f�X�g���N�^
	~Player();

	//�����o�֐��̐錾
	void Input();
	void Update();
	void Render();

	//�����o�ϐ��̐錾
	int xPlayer;
	int yPlayer;
	int playerSpeed;

};
