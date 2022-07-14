/*****************************************************************//**
 * \file   ObjectServer.cpp
 * \brief  
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
	:g(pGame),
	updating(false)
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
	if (updating)
	{
		vPendingObj.push_back(std::move(obj));
	}
	else
	{
		vObj.push_back(std::move(obj));
	}
}

void ObjectServer::AddPendingObjects()
{
	vObj.insert(
		vObj.end(),
		make_move_iterator(vPendingObj.begin()),
		make_move_iterator(vPendingObj.end())
	);
	vPendingObj.clear();
}

//�|�C���^�ɒǉ����ꂽ����(Process��Draw����
void ObjectServer::Process(Game& g)
{
	for (auto&& object : vObj)
	{
		object->Process(g);
	}
}
void ObjectServer::Draw(Game& g)
{
	for (auto&& object : vObj)
	{
		object->Draw(g);
	}
}
