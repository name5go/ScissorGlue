#pragma once
/*****************************************************************//**
 * \file   ObjectServer.h
 * \brief  �I�u�W�F�N�g�T�[�o�[
 * 
 * \author �߂���
 * \date   July 2022
 *********************************************************************/

#include"../PCH/stdafx.h"
#include<winsock.h>


class Game;
class ObjectBase;

//�I�u�W�F�N�g�T�[�o�[
class ObjectServer
{
public:
	ObjectServer();
	~ObjectServer();

	void	Clear();
	void	Add(ObjectBase* obj);
	void	Del(ObjectBase* obj);

	void	Process(Game& g);
	void	Draw(Game& g);

	std::vector<ObjectBase*>* List() { return &_vObject; }

private:
	void	AddListObjects();
	void	DelListObjects();

protected:
	std::vector<ObjectBase*>	_vObject;		// ObjectBase��o�^���郊�X�g

	std::vector<ObjectBase*>	_vAdd;	// �ǉ�����I�u�W�F�N�g���X�g
	std::vector<ObjectBase*>	_vDel;	// �폜����I�u�W�F�N�g���X�g


};