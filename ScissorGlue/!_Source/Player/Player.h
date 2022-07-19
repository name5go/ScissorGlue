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
	Player(Game& g);
	//�f�X�g���N�^
	~Player();
	virtual Type	GetType() { return Type::kPlayer; }

	void Init();
	void Process(Game& g) override;
  void CheckInput(Game& g);

private:

};
