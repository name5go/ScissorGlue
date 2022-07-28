/*****************************************************************//**
 * \file   Player.cpp
 * \brief  �v���C���[�N���X
 * 
 * \author �߂���
 * \date   July 2022
 *********************************************************************/

#include"Player.h"

//�R���X�g���N�^
Player::Player(Game& g):
	pG(g)
{
	pG._obj.Add(new Scissor(*this, pG._mapChips));
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
	LeftRight = 1;
	cgNum = 1;
	wPic = 32;
	hPic = 48;
	xWorld = 32;
	yWorld = 0;
	xCamera = -wPic / 2;
	yCamera = -hPic + 1;
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
	CheckInput(g);
	ObjectBase::Process(g);

	// ��l���ʒu����̃J�������W����
	g._mapChips.xScr = xWorld - (SCREEN_W / 2);		// ��ʂ̉������ɃL������u��
	g._mapChips.yScr = yWorld - (SCREEN_H * 7 / 10);	// ��ʂ̏c70%�ɃL������u��
	
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
		LeftRight = -1;
		//�{�^���������ꂽ���̏���
		xWorld -= 1;
		g._mapChips.IsHit(*this, -1, 0);		// ���ɓ������̂ŁAx�ړ��������}�C�i�X�w��
	}

	//�E������Ă���E����
	if (g.gKey & PAD_INPUT_RIGHT || g.gKey & D_KEY)
	{
		LeftRight = 1;
		//�{�^���������ꂽ���̏���
		//�`��̔��]���I��
		xWorld += 1;
		g._mapChips.IsHit(*this, 1, 0);			// �E�ɓ������̂ŁAx�ړ��������v���X�w��
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
