#pragma once
/*****************************************************************//**
 * \file   ObjectServer.h
 * \brief  �I�u�W�F�N�g�T�[�o�[
 * 
 * \author �߂���
 * \date   July 2022
 *********************************************************************/

#include<vector>
#include"ObjectBase.h"


class Game;

//�I�u�W�F�N�g�T�[�o�[
class ObjectServer
{
public:
	//�R���X�g���N�^
	ObjectServer();
	//�R���X�g���N�^
	~ObjectServer();

	//����
	void Clear();
	//������
	void Add(ObjectBase* obj);
	//������
	void Del(ObjectBase* obj);

	//�v�Z
	void Process(Game& g);
	//�`��
	void Draw(Game& g);

	std::vector<ObjectBase*>* List() { return&vObject; }

private:
	//Add���X�g�̃I�u�W�F�N�g��ǉ�����
	void AddListObjects();
	// Del���X�g�̃I�u�W�F�N�g���폜����
	void DelListObjects();

protected:
	//ObjectBase��o�^���郊�X�g
	std::vector<ObjectBase*> vObject;
	//�ǉ�����I�u�W�F�N�g���X�g
	std::vector<ObjectBase*> vAdd;
	//�폜����I�u�W�F�N�g���X�g
	std::vector<ObjectBase*> vDel;
};
