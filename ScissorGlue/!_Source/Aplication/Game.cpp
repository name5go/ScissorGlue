/*****************************************************************//**
 * \file   Game.cpp
 * \brief  �Q�[���̒��g���낢����Ăяo���ĉ񂵂���
 * 
 * \author �߂���
 * \date   June 2022aaa
 *********************************************************************/

#include"DxLib.h"
#include"Game.h"
#include<memory>

 //�v���C���[�N���X�̃|�C���^����


//�R���X�g���N�^
Game::Game():pObj(*this)
{
	gKey = 0;
	gFrameCount = 0;
	gTrg = 0;

	// json����}�b�v�f�[�^���\�z����
	mapChips.LoadJson("!_Resources\\!_Pic\\mapchips\\", "map01.json");
	//�e��N���X���|�C���^�ɒǉ�
	auto player = std::make_unique<Player>(*this);
	pObj.Add(std::move(player));
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
//�L�[�̃g���K��񐶐��B1�t���[���O�̃L�[�̏��Ɣ�r���Ă����͂���Ă�Ȃ�
void Game::CreateKeyTrg() {
	int oldKey = gKey;
	gKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	gTrg = (gKey ^ oldKey) & gKey;
}

//�v�Z
void Game::Process() 
{
	pObj.Process(*this);
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
	pObj.Draw(*this);

	ScreenFlip();
}

