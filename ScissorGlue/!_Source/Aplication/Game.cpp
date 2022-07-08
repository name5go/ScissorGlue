/*****************************************************************//**
 * \file   Game.cpp
 * \brief  �Q�[���̒��g���낢����Ăяo���ĉ񂵂���
 * 
 * \author �߂���
 * \date   June 2022a
 *********************************************************************/

#include"DxLib.h"
#include"Game.h"

 //�v���C���[�N���X�̃|�C���^����


//�R���X�g���N�^
Game::Game()
{
	gKey = 0;
	gFrameCount = 0;
	gTrg = 0;

	// json����}�b�v�f�[�^���\�z����
	mapChips.LoadJson("res/", "platformer_simpleA.json");

	// �v���C���[�𐶐����A�I�u�W�F�N�g�T�[�o�ɓo�^����
	objectServer.Add(new Player());
}

//�f�X�g���N�^
Game::~Game()
{
}

//����
void Game::Input()
{
	//�L�[�̃g���K��񐶐�
	CreateKeyTrg();
}

//�v�Z
void Game::Update() 
{
	objectServer.Process(*this);
	mapChips.Process(*this);
	gFrameCount++;
}

//�`��
void Game::Render()
{
	//��ʏ�����
	ClearDrawScreen();
	bg.Draw();
	mapChips.Draw();
	objectServer.Draw(*this);
	ScreenFlip();
}

//�L�[�̃g���K��񐶐��B1�t���[���O�̃L�[�̏��Ɣ�r���Ă����͂���Ă�Ȃ�
void Game::CreateKeyTrg() {
	int oldKey = gKey;
	gKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	gTrg = (gKey ^ oldKey) & gKey;
}