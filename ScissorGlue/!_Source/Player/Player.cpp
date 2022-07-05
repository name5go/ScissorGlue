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

//�R���X�g���N�^
Player::Player(Game& pGame) :
	g(pGame),
	//Player�����o�ϐ��̏�����
	xPlayer(0), yPlayer(0),//�v���C���[���W��0,0�ŏ�����
	inertiaPlayer(0),//�v���C���[�̊���
	inertiaMax(30),//�ő呬�x
	sizePlayer(1.0),//�v���C���[�̕`��{��
	anglePlayer(0.0),//�v���C���[�̊p�x
	turnPlayerFlag(FALSE)//�v���C���[�̔��]�t���O
{
	//�摜�̓ǂݍ���___��ŃC���[�W�T�[�o�[�̃n���h���擾�ɏ���������̖Y��Ȃ�
	gh = LoadGraph("ScissorGlue / !_Resources / !_Pic / player / ball.png");
}

//�f�X�g���N�^
Player::~Player()
{
}

//����
void Player::Input()
{
	constexpr auto A_KEY = PAD_INPUT_4;
	constexpr auto D_KEY = PAD_INPUT_6;
	constexpr auto W_KEY = PAD_INPUT_8;
	constexpr auto S_KEY = PAD_INPUT_5;
	constexpr auto X_KEY = PAD_INPUT_2;

	//��������Ă��獶����
	if(g.gKey&PAD_INPUT_LEFT||g.gKey&A_KEY)
	{
		//�{�^���������ꂽ���̏���
		//�������ő呬�x�ȉ��Ȃ瑝�₵������
		if(inertiaPlayer<inertiaMax)
		{
			inertiaPlayer += 2;
		}

	}

	//�E������Ă���E����
	if (g.gKey & PAD_INPUT_RIGHT || g.gKey & D_KEY)
	{
		//�{�^���������ꂽ���̏���
		//�`��̔��]���I��
		//�������ő呬�x�ȉ��Ȃ瑝�₵������
		turnPlayerFlag = TRUE;
		if (inertiaPlayer < inertiaMax)
		{
			inertiaPlayer += 2;
		}
	}

}

//�X�V
void Player::Update()
{


	//�����Ƃ��̌���
	if (inertiaPlayer > 0)
	{
		inertiaPlayer -= 1;
	}

}

//�`��
void Player::Render()
{
	DrawRotaGraph(xPlayer, yPlayer, sizePlayer, anglePlayer, gh, TRUE, turnPlayerFlag);
}
