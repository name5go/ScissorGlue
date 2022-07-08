/*****************************************************************//**
 * \file   Game.h
 * \brief  �Q�[���N���X
 * 
 * \author �߂���
 * \date   June 2022
 *********************************************************************/

#pragma once

#include<DxLib.h>
#include<memory>
#include"../Player/Player.h"
#include	"../Object/ObjectServer.h"
#include	"../BackGround/BackGround.h"
#include	"../Map/MapChips.h"

class Player;

//��ʐݒ�
constexpr auto SCREEN_W = 1920;		//< ��ʂ̉��𑜓x
constexpr auto SCREEN_H = 1080;		//< ��ʂ̏c�𑜓x
constexpr auto SCREEN_DEPTH = 32;   ///< �P�h�b�g������̃r�b�g��

//�Q�[���N���X
class Game 
{
public:
	//�R���X�g���N�^
	Game();
	//�f�X�g���N�^
	~Game();
	
	//�v���C���[�N���X
	std::unique_ptr<Player>pPlayer;

	//����
	void Input();
	//�v�Z
	void Update();
	//�`��
	void Render();
	//�L�[���̐���
	void CreateKeyTrg();

	//�L�[���
	int gKey;
	//��񉟂�����
	int gTrg;
	//�t���[���J�E���g
	int gFrameCount;
};
