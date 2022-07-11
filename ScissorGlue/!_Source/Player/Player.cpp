/*****************************************************************//**
 * \file   Player.cpp
 * \brief  �v���C���[�N���X�̏������e
 * 
 * \author �߂���
 * \date   July 2022
 *********************************************************************/

#include<DxLib.h>
#include"Player.h"
#include"Math.h"
#include"../Aplication/Game.h"
#include"../Object/ImageServer.h"

//�R���X�g���N�^
Player::Player() 
{
	//�摜�̓ǂݍ���___��ŃC���[�W�T�[�o�[�̃n���h���擾�ɏ���������
	cgPic[0] = ImageServer::LoadGraph("!_Resources\\!_Pic\\player\\ball.png");
	Init();
}

//�f�X�g���N�^
Player::~Player()
{
}

//�v���C���[���̏�����
void Player::Init()
{
	cgNum = 1;
	wPic = 32;
	hPic = 48;
	xWorld = 32;
	yWorld = 0;
	xCamera = wPic / 2;
	yCamera = hPic + 1;
	besideInertia = 0;
	verticalInertia = 0;
	xHit = -16;
	yHit = -47;
	wHit = 32;
	hHit = 48;
}

//����
void Player::Process(Game& g)
{
	ObjectBase::Process(g);
//WASD�̓��͂�o�^
	constexpr auto A_KEY = PAD_INPUT_4;
	constexpr auto D_KEY = PAD_INPUT_6;
	constexpr auto W_KEY = PAD_INPUT_8;
	constexpr auto S_KEY = PAD_INPUT_5;
	constexpr auto X_KEY = PAD_INPUT_2;

	//��������Ă��獶����
	if(g.gKey&PAD_INPUT_LEFT||g.gKey&A_KEY)
	{
		//�{�^���������ꂽ���̏���
		xWorld -= 1;
		g.mapChips.IsHit(*this, -1, 0);		// ���ɓ������̂ŁAx�ړ��������}�C�i�X�w��
	}

	//�E������Ă���E����
	if (g.gKey & PAD_INPUT_RIGHT||g.gKey&D_KEY )
	{

		//�{�^���������ꂽ���̏���
		//�`��̔��]���I��
		xWorld += 1;
		g.mapChips.IsHit(*this, 1, 0);			// �E�ɓ������̂ŁAx�ړ��������v���X�w��
	}

	//g.gKey & PAD_INPUT_A ||
	//�W�����v
	if (g.gTrg & W_KEY)
	{
		if(standFlag==1)
		{
			verticalInertia = -20;
			//�W�����v����
		}
	}
	// ��l���ʒu����̃J�������W����
	g.mapChips.xScr = xWorld - (SCREEN_W / 2);		// ��ʂ̉������ɃL������u��
	g.mapChips.yScr = yWorld - (SCREEN_H * 7 / 10);	// ��ʂ̏c70%�ɃL������u��



}

