/*****************************************************************//**
 * \file   ObjectServer.cpp
 * \brief  オブジェクトサーバー
 * 
 * \author めざし
 * \date   July 2022
 *********************************************************************/

#include<DxLib.h>
#include"ObjectServer.h"

//コンストラクタ
ObjectServer::ObjectServer()
{
	vObject.clear();
	vAdd.clear();
	vDel.clear();
}
//デストラクタ
ObjectServer::~ObjectServer()
{
	Clear();
}

//リストに登録されてるオブジェクトの全消し
void ObjectServer::Clear()
{
	for (auto ite = vObject.begin(); ite != vObject.end(); ite++)
	{
		delete(*ite);
	}
	vObject.clear();
}

//Addリストにオブジェクトの登録
void ObjectServer::Add(ObjectBase* obj)
{
	vAdd.push_back(obj);
}

//Delリストにオブジェクトを登録する
void ObjectServer::Del(ObjectBase* obj)
{
	vDel.push_back(obj);
}

//Addリストのオブジェクトを追加する
void ObjectServer::AddListObjects()
{
	for (auto iteAdd = vAdd.begin(); iteAdd != vAdd.end(); iteAdd++)
	{
		vObject.push_back((*iteAdd));
	}
	vAdd.clear();
}

//Dekリストのオブジェクト全消し
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


//Processを登録順に回す
void ObjectServer::Process(Game& g)
{
	//Addリストのオブジェクトをリストに登録する
	AddListObjects();

	//Process()の呼び出し
	for (auto ite = vObject.begin(); ite != vObject.end(); ite++)
	{
		(*ite)->Process(g);
	}
	//Delリストにあるオブジェクトをリストから削除
	DelListObjects();
}

//Drawを登録準に回す
void ObjectServer::Draw(Game& g)
{
	for (auto ite = vObject.begin(); ite != vObject.end(); ite++)
	{
		(*ite)->Draw(g);
	}
}











