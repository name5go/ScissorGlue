/*****************************************************************//**
 * \file   ObjectServer.cpp
 * \brief  
 * 
 * \author �߂���
 * \date   July 2022
 *********************************************************************/

#include"../PCH/pch.h"
#include<winsock.h>


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

//�|�C���^�ɒǉ����ꂽ���߂���
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
