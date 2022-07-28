/*****************************************************************//**
 * \file   Scissor.cpp
 * \brief  
 * 
 * \author �߂���
 * \date   July 2022
 *********************************************************************/
#include"../Player/Scissor.h"

//�R���X�g���N�^
Scissor::Scissor()
{
	cgPic[0] = ImageServer::LoadGraph("!_Resources\\!_Pic\\player\\ball.png");
	Init();
}
//������
void Scissor::Init()
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

//�f�X�g���N�^
Scissor::~Scissor()
{
}

//�v�Z
void Scissor::Process(Game& g)
{
  
	Input(g);
}
//����
void Scissor::Input(Game& g)
{

}
