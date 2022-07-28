/*****************************************************************//**
 * \file   Game.cpp
 * \brief  �Q�[���̒��g���낢����Ăяo���ĉ񂵂���
 * 
 * \author �߂���
 * \date   June 2022a
 *********************************************************************/
#include"Game.h"

//�R���X�g���N�^
Game::Game()
{
	gKey = 0;
	gFrameCount = 0;
	gTrg = 0;

	// json����}�b�v�f�[�^���\�z����
	_mapChips.LoadJson("!_Resources\\!_Pic\\mapchips\\", "map01.json");
	//�e��N���X��ǉ�
		// �v���C���[�𐶐����A�I�u�W�F�N�g�T�[�o�ɓo�^����
	_obj.Add(new Player());
	_obj.Add(new Scissor());
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
void Game::Process() 
{
	_obj.Process(*this);//�I�u�W�F�N�g�T�[�o�[
	_mapChips.Process(*this);//�}�b�v�`�b�v
	gFrameCount++;
}

//�`��
void Game::Render()
{
	//��ʏ�����
	ClearDrawScreen();
	_bg.Draw();//�w�i�`��
	_mapChips.Draw(*this);//�}�b�v�`�b�v
	_obj.Draw(*this);//�I�u�W�F�N�g�T�[�o�[
	ScreenFlip();
}

//�L�[�̃g���K��񐶐��B1�t���[���O�̃L�[�̏��Ɣ�r���Ă����͂���Ă�Ȃ�
void Game::CreateKeyTrg() {
	int oldKey = gKey;
	gKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	gTrg = (gKey ^ oldKey) & gKey;
}