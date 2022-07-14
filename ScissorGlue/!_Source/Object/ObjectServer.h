#pragma once
/*****************************************************************//**
 * \file   ObjectServer.h
 * \brief  �I�u�W�F�N�g�T�[�o�[
 * 
 * \author �߂���
 * \date   July 2022
 *********************************************************************/

#include<vector>
#include<memory>
#include<DxLib.h>


class Game;
class ObjectBase;

//�I�u�W�F�N�g�T�[�o�[
class ObjectServer
{
public:
	//�R���X�g���N�^�ƃf�X�g���N�^
	ObjectServer(Game& pGame);
	~ObjectServer();
	//�I�u�W�F�N�g���X�g���`
	typedef std::vector<std::unique_ptr<ObjectBase>> TypeObjects;

	//�������
	void Clear();
	//������
	void Add(std::unique_ptr<ObjectBase> obj);
	void Del(ObjectBase& obj);

	//���񂷖���
	void Draw(Game& g);
	void Process(Game& g);


protected:
	Game& g;
	TypeObjects vObj;
	TypeObjects vPendingObj;
	bool updating;

	void DeleteObjects();
	void AddPendingObjects();
};