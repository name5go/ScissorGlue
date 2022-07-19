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
#include"../Object/ImageServer.h"

//�R���X�g���N�^
Player::Player(Game& g)
	:base(g)
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
	base::Init();
	cgNum = 1;
	size.x = 32;size.y= 48;//�摜�̑傫��xy
	pos.x = 32;pos.y = 0;//xy���W
	xCamera = wPic / 2;yCamera = hPic + 1;//��ʒu����`�掞�̍���
	besideInertia = 0;verticalInertia = 0;//���Əc�̊���
	colPos.x = 0; colPos.y = 0;//�����蔻��̍��W
	colSize.x = 32; colSize.y = 48;//�����蔻��̑傫��
	/**
	 * 	�����蔻��X�V�̌v�Z(�ꏊ��objectBase)
	 * 
	 * collision.min = pos + colPos;
	 * collision.max = pos + colPos + colSize;.
	 * 
	 */
}

//����
void Player::Process(Game& g)
{
	CheckInput(g);
	ObjectBase::Process(g);
	ObjectBase::UpdateCollision();

	// ��l���ʒu����̃J�������W����
	g.mapChips.xScr = pos.x - (SCREEN_W / 2);		// ��ʂ̉������ɃL������u��
	g.mapChips.yScr = pos.y - (SCREEN_H * 7 / 10);	// ��ʂ̏c70%�ɃL������u��
}

void Player::CheckInput(Game& g)
{
	
	//WASD�̓��͂�o�^
	constexpr auto A_KEY = PAD_INPUT_4;
	constexpr auto D_KEY = PAD_INPUT_6;
	constexpr auto W_KEY = PAD_INPUT_8;
	constexpr auto S_KEY = PAD_INPUT_5;
	constexpr auto X_KEY = PAD_INPUT_2;

	//��������Ă��獶����
	if (g.gKey & PAD_INPUT_LEFT || g.gKey & A_KEY)
	{
		//�{�^���������ꂽ���̏���
		pos.x -= 1;
		g.mapChips.IsHit(*this, -1, 0);		// ���ɓ������̂ŁAx�ړ��������}�C�i�X�w��
	}

	//�E������Ă���E����
	if (g.gKey & PAD_INPUT_RIGHT || g.gKey & D_KEY)
	{

		//�{�^���������ꂽ���̏���
		//�`��̔��]���I��
		pos.x += 1;
		g.mapChips.IsHit(*this, 1, 0);			// �E�ɓ������̂ŁAx�ړ��������v���X�w��
	}

	//g.gKey & PAD_INPUT_A ||
	//�W�����v
	if (g.gTrg & W_KEY)
	{
		if (standFlag == 1)
		{
			verticalInertia = -20;
			//�W�����v����
		}
	}
}
