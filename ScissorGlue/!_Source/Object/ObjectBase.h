#pragma once
/*****************************************************************//**
 * \file   ObjectBase.h
 * \brief  �I�u�W�F�N�g�x�[�X
 * 
 * \author �߂���
 * \date   July 2022
 *********************************************************************/

class Game;

//�I�u�W�F�N�g�N���X
class ObjectBase
{
public:
	//�R���X�g���N�^
	ObjectBase();
	//�f�X�g���N�^
	~ObjectBase();

	//�I�u�W�F�N�g�^�C�v
	enum class OBJECTTYPE
	{
		PLAYER,
	};

	void Process();
	void Draw();

public:
	int _cg[2];
	





};
