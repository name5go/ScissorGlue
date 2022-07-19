/*****************************************************************//**
 * \file   Game.h
 * \brief  �Q�[���N���X
 *  * ��邱��
 * Input�ŃL�[�̃g���K���̐���
 * Process�ŃI�u�W�F�N�g�T�[�o�[�ɓo�^���ꂽ�N���X�A
 * �@�@�@�@�}�b�v�`�b�v�A�w�i��Process�����̌Ăяo��
 * Render�ŃI�u�W�F�N�g�T�[�o�[�o�^Draw
 * �}�b�v�`�b�v�A�w�i��Draw���Ăяo���B
 * 
 * \author �߂���
 * \date   June 2022
 *********************************************************************/

#pragma once

#include"../Player/Player.h"
#include	"../Object/ObjectServer.h"
#include	"../BackGround/BackGround.h"
#include	"../Map/MapChips.h"

//��ʐݒ�
constexpr auto SCREEN_W = 1280;		//< ��ʂ̉��𑜓x
constexpr auto SCREEN_H = 720;		//< ��ʂ̏c�𑜓x
constexpr auto SCREEN_DEPTH = 32;   ///< �P�h�b�g������̃r�b�g��

//�Q�[���N���X
class Game 
{
public:
	//�R���X�g���N�^
	Game();
	//�f�X�g���N�^
	~Game();

	//����
	void Input();
	//�v�Z
	void Process();
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

	BackGround bg;
	MapChips mapChips;

protected:
	ObjectServer pObj;
	
};
