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
	Game();//�R���X�g���N�^
	~Game();//�f�X�g���N�^
	
	std::unique_ptr<Player>pPlayer;

	// �w�i
	BackGround	_bg;

	// �}�b�v�`�b�v
	MapChips	_mapChips;

	// �I�u�W�F�N�g�T�[�o
	ObjectServer	_objServer;		// �v���C���[��G�Ȃǂ�o�^����

	//�֐�
	void Input();//����
	void Update();//�v�Z
	void Render();//�`��
	void CreateKeyTrg();

	//�����o�ϐ��錾
	int gKey;
	int gTrg;
	int gFrameCount;
};
