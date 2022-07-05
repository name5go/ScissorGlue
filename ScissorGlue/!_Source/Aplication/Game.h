/*****************************************************************//**
 * \file   Game.h
 * \brief  �Q�[���N���X
 * 
 * \author �߂���
 * \date   June 2022
 *********************************************************************/

#pragma once

#include<DxLib.h>

//��ʐݒ�
constexpr auto wScreen = 1920;		//< ��ʂ̉��𑜓x
constexpr auto hScreen = 1080;		//< ��ʂ̏c�𑜓x
constexpr auto depthScreen = 32;   ///< �P�h�b�g������̃r�b�g��

//�Q�[���N���X
class Game {
public:
	Game();//�R���X�g���N�^
	~Game();//�f�X�g���N�^



	//�֐�
	void Input();//����
	void Update();//�v�Z
	void Render();//�`��
	void CreateKeyTrg();

	//�����o�ϐ��錾
	int gKey;
	int gTrg;
	int gFrameCount;
	int gh;
};