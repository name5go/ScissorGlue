/*****************************************************************//**
 * \file   ObjectServer.cpp
 * \brief  �I�u�W�F�N�g�T�[�o�[
 * 
 * \author �߂���
 * \date   July 2022
 *********************************************************************/

#include<DxLib.h>
#include"ObjectServer.h"

//�R���X�g���N�^
ObjectServer::ObjectServer()
{
	vObject.clear();
	vAdd.clear();
	vDel.clear();
}
//�f�X�g���N�^
ObjectServer::~ObjectServer()
{
	Clear();
}

//���X�g�ɓo�^����Ă�I�u�W�F�N�g�̑S����
void ObjectServer::Clear()
{
	for (auto ite = vObject.begin(); ite != vObject.end(); ite++)
	{
		delete(*ite);
	}
	vObject.clear();
}

//Add���X�g�ɃI�u�W�F�N�g�̓o�^
void ObjectServer::Add(ObjectBase* obj)
{
	vAdd.push_back(obj);
}

//Del���X�g�ɃI�u�W�F�N�g��o�^����
void ObjectServer::Del(ObjectBase* obj)
{
	vDel.push_back(obj);
}

//Add���X�g�̃I�u�W�F�N�g��ǉ�����
void ObjectServer::AddListObjects()
{
	for (auto iteAdd = vAdd.begin(); iteAdd != vAdd.end(); iteAdd++)
	{
		vObject.push_back((*iteAdd));
	}
	vAdd.clear();
}

//Dek���X�g�̃I�u�W�F�N�g�S����
void ObjectServer::DelListObjects()
{
	for (auto iteDel = vDel.begin(); iteDel != vDel.end(); iteDel++)
	{
		for (auto ite = vObject.begin(); ite != vObject.end();)
		{
			if((*ite) == (*iteDel))
			{
				delete(*ite);
				ite = vObject.erase(ite);
			}
			else
			{
				ite++;
			}
		}
	}
	vDel.clear();
}


//Process��o�^���ɉ�
void ObjectServer::Process(Game& g)
{
	//Add���X�g�̃I�u�W�F�N�g�����X�g�ɓo�^����
	AddListObjects();

	//Process()�̌Ăяo��
	for (auto ite = vObject.begin(); ite != vObject.end(); ite++)
	{
		(*ite)->Process(g);
	}
	//Del���X�g�ɂ���I�u�W�F�N�g�����X�g����폜
	DelListObjects();
}

//Draw��o�^���ɉ�
void ObjectServer::Draw(Game& g)
{
	for (auto ite = vObject.begin(); ite != vObject.end(); ite++)
	{
		(*ite)->Draw(g);
	}
}











