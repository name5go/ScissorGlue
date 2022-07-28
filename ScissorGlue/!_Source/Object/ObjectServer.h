#pragma once
/*****************************************************************//**
 * \file   ObjectServer.h
 * \brief  オブジェクトサーバー
 * 
 * \author めざし
 * \date   July 2022
 *********************************************************************/

#include"../PCH/stdafx.h"
#include<winsock.h>


class Game;
class ObjectBase;

//オブジェクトサーバー
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
	std::vector<ObjectBase*>	_vObject;		// ObjectBaseを登録するリスト

	std::vector<ObjectBase*>	_vAdd;	// 追加するオブジェクトリスト
	std::vector<ObjectBase*>	_vDel;	// 削除するオブジェクトリスト


};