/*****************************************************************//**
 * \file   Game.cpp
 * \brief  �Q�[���̒��g���낢����Ăяo���ĉ񂵂���
 * 
 * \author �߂���
 * \date   June 2022a
 *********************************************************************/

#include"Game.h"

 //�v���C���[�N���X�̃|�C���^����


//�R���X�g���N�^
Game::Game():
	gKey(0),
	gTrg(0),
	gFrameCount(0)
{
	 pPlayer = std::make_unique<Player>(*this);
//�摜����̓ǂݍ��ݏ��������݂���
}

//�f�X�g���N�^
Game::~Game(){}

//����
void Game::Input() {
	//�L�[�̃g���K��񐶐�
	CreateKeyTrg();

	pPlayer->Update();
}

//�v�Z
void Game::Update() {
	pPlayer->Update();

}

//�`��
void Game::Render() {
	pPlayer->Render();
}

//�L�[�̃g���K��񐶐��B1�t���[���O�̃L�[�̏��Ɣ�r���Ă����͂���Ă�Ȃ�
void Game::CreateKeyTrg() {
	int oldKey = gKey;
	gKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	gTrg = (gKey ^ oldKey) & gKey;
}