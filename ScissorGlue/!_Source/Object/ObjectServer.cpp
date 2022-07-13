/*****************************************************************//**
 * \file   ObjectServer.cpp
 * \brief  
 * 
 * \author めざし
 * \date   July 2022
 *********************************************************************/

#include<DxLib.h>
#include"ObjectServer.h"
#include"ObjectBase.h"
#include"../Aplication/Game.h"


//コンストラクタ
ObjectServer::ObjectServer(Game& pGame)
	:g(pGame)
{
}
//デストラクタ
ObjectServer::~ObjectServer()
{
	Clear();
}

//ポインタの中身消すやつ
void ObjectServer::Clear()
{
	vObj.clear();
}
//ポインタにクラス追加
void ObjectServer::Add(std::unique_ptr<ObjectBase>obj)
{
	vObj.push_back(std::move(obj));
}

//ポインタに追加された命令を回す
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
