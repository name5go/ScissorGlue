#pragma once
/*****************************************************************//**
 * \file   Player.h
 * \brief  �v���C���[�̏�������
 * 
 * \author �߂���
 * \date   July 2022
 *********************************************************************/
#include"../PCH/stdafx.h"
#include<winsock.h>
#include"../Object/ObjectBase.h"//�I�u�W�F�N�g�x�[�X

class Game;

class Player:public ObjectBase
{
public:
	//�R���X�g���N�^
	Player(Game& g);
	//�f�X�g���N�^
	~Player();
	virtual OBJECTTYPE GetType() { return ObjectBase::OBJECTTYPE::PLAYER; }

	void Init();//������
	void Process(Game& g);//�v���Z�X
  void CheckInput(Game& g);//����

	Game& pG;


 int xPl() { return xWorld; }
 int yPl() { return yWorld; }
	

public:
	//���E�̌����t���O1�E-1��
	int LeftRight;

};
