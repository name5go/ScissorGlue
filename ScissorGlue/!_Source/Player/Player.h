#pragma once
/*****************************************************************//**
 * \file   Player.h
 * \brief  �v���C���[�̏�������
 * 
 * \author �߂���
 * \date   July 2022
 *********************************************************************/
#include"../Object/ObjectBase.h"

class Game;

class Player:public ObjectBase
{
	typedef ObjectBase base;
public:
	//�R���X�g���N�^
	Player();
	//�f�X�g���N�^
	~Player();

	void Init();
	void Process(Game& g);

private:

};
