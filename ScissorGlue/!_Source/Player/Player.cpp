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
#include"../Object/ImageServer.h"

//�R���X�g���N�^
Player::Player(Game& pGame) :
	game(pGame),
	//Player�����o�ϐ��̏�����
	xPlayer(0), yPlayer(0),//�v���C���[���W��0,0�ŏ�����
	inertiaPlayer(0),//�v���C���[�̊���
	gravityPlayer(0),
	inertiaMax(20),//�ő呬�x
	sizePlayer(1.0),//�v���C���[�̕`��{��
	anglePlayer(0.0),//�v���C���[�̊p�x
	turnPlayerFlag(FALSE),//�v���C���[�̔��]�t���O
	standFlag(0)

{
	//�摜�̓ǂݍ���___��ŃC���[�W�T�[�o�[�̃n���h���擾�ɏ���������
	gh = ImageServer::LoadGraph("!_Resources\\!_Pic\\player\\ball.png");
}

//�f�X�g���N�^
Player::~Player()
{
}

//����
void Player::Input()
{
//WASD�̓��͂�o�^
	constexpr auto A_KEY = PAD_INPUT_4;
	constexpr auto D_KEY = PAD_INPUT_6;
	constexpr auto W_KEY = PAD_INPUT_8;
	constexpr auto S_KEY = PAD_INPUT_5;
	constexpr auto X_KEY = PAD_INPUT_2;

	//��������Ă��獶����
	if(game.gKey&PAD_INPUT_LEFT||game.gKey&A_KEY)
	{
		//�{�^���������ꂽ���̏���
		turnPlayerFlag = FALSE;
			inertiaPlayer -= 3;
	}

	//�E������Ă���E����
	if (game.gKey & PAD_INPUT_RIGHT||game.gKey&D_KEY )
	{
		//�{�^���������ꂽ���̏���
		//�`��̔��]���I��
		turnPlayerFlag = TRUE;
		inertiaPlayer += 3;
	}

	//g.gKey & PAD_INPUT_A ||
	//�W�����v
	if (game.gTrg & W_KEY)
	{
		if(standFlag==1)
		{
			gravityPlayer = -25;
		}
	}
}

//�`��
void Player::Render()
{
	DrawRotaGraph(xPlayer, yPlayer, sizePlayer, anglePlayer, gh, TRUE, turnPlayerFlag);
}


//�X�V
void Player::Update()
{
	//���W�̔��f
	xPlayer += inertiaPlayer;
	yPlayer += gravityPlayer;

//	�d�͏����ߋ��̂��
if (yPlayer > 1000)
	{
		gravityPlayer = 0;
		standFlag = 1;
	}
	else
	{
		standFlag = 0;
		gravityPlayer += 1;
	
	}


//�����������Ԃɗ]�T����Ȃ�x�N�g���Ƃ���Βl��ŏ�����������
if (inertiaPlayer < 0)
{
	inertiaPlayer += 1;
}
if (inertiaPlayer > 0)
{
	inertiaPlayer -= 1;
}

//�ő呬�x�̏�����������Ԃ�����΃x�N�g���ŏ�����������
if (inertiaPlayer > inertiaMax)
{
	inertiaPlayer = inertiaMax;
}
if (inertiaPlayer < -1 * inertiaMax)
{
	inertiaPlayer = -1 * inertiaMax;
}


}
