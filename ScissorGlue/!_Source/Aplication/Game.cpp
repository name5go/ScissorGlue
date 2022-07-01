/*****************************************************************//**
 * \file   Game.cpp
 * \brief  �Q�[���N���X
 * 
 * \author �߂���
 * \date   June 2022a
 *********************************************************************/

#include"Game.h"
#include<DxLib.h>

//�R���X�g���N�^
Game::Game():
	gKey(0),
	gTrg(0),
	gFrameCount(0)
{
	//json����}�b�v�f�[�^��ǂݎ��
	mapChips.LoadJson("map01.jason")

		//player������ăI�u�W�F�N�g�T�[�o�[�ɓo�^
	objectServer.Add(new Player());
}

//�f�X�g���N�^
Game::~Game(){}

//����
void Game::Input() {
	int oldKey = gKey;
	gKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	gTrg = (gKey ^ oldKey) & gKey;//�L�[�̃g���K��񐶐��B1�t���[���O�̃L�[�̏��Ɣ�r���Ă����͂���Ă�Ȃ�
}


//�v�Z
void Game::Process() {
	objectServer.Process(*this);
	mapChips.Process(*this)
}

//�`��
void Game::Drae() {
	CleaDrawScreen();
	backGround.Draw();
	mapChips.Draw();
	objectServer.Draw();
	ScreenFlip();
}
