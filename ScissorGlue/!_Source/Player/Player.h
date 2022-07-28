#pragma once
/*****************************************************************//**
 * \file   Player.h
 * \brief  �v���C���[�̏�������
 * 
 * \author �߂���
 * \date   July 2022
 *********************************************************************/
#include"../PCH/pch.h"
#include<winsock.h>

class Game;

class Player:public ObjectBase
{
	typedef ObjectBase base;
public:
	//�R���X�g���N�^
	Player(Game& g);
	//�f�X�g���N�^
	~Player();

	void Init();
	void Process(Game& g) override;
  void CheckInput(Game& g);

private:

};
