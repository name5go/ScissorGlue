/*****************************************************************//**
 * \file   ObjectServer.cpp
 * \brief  �I�u�W�F�N�g�T�[�o�[
 * 
 * \author �߂���
 * \date   July 2022
 *********************************************************************/

#include<DxLib.h>
#include"ObjectServer.h"
#include"ObjectBase.h"
#include"../Aplication/Game.h"


//�R���X�g���N�^
ObjectServer::ObjectServer(Game& pGame)
	:g(pGame)
{
}
//�f�X�g���N�^
ObjectServer::~ObjectServer()
{
	Clear();
}

//�|�C���^�̒��g�������
void ObjectServer::Clear()
{
	vObj.clear();
}
//�|�C���^�ɃN���X�ǉ�
void ObjectServer::Add(std::unique_ptr<ObjectBase>obj)
{
	vObj.push_back(std::move(obj));
}

//�|�C���^�ɒǉ����ꂽ�N���X�̖˃o�J���X�L����
void ObjectServer::Process(Game& g)
{
	for (auto&& obj : vObj)
	{
		obj->Process(g);
	}
}

void ObjectServer::Draw(Game& g)
{
	for (auto&& obj : vObj)
	{
		obj->Draw(g);
	}
}
