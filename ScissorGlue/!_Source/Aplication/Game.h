#pragma once
/*****************************************************************//**
 * \file   Game.h
 * \brief  �Q�[���N���X
 * 
 * \author �߂���
 * \date   June 2022
 *********************************************************************/

#include"../PCH/stdafx.h"
#include<winsock.h>
#include"../BackGround/BackGround.h"//�o�b�N�O���E���h
#include"../Map/MapChips.h"//�}�b�v�`�b�v�w�b�_�[
#include"../Object/ObjectServer.h"//�I�u�W�F�N�g�T�[�o�[

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

	// �w�i
	BackGround	_bg;
	// �}�b�v�`�b�v
	MapChips	_mapChips;
	// �I�u�W�F�N�g�T�[�o
	ObjectServer	_obj;
};
