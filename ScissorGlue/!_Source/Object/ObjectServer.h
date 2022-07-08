#pragma once
/*****************************************************************//**
 * \file   ObjectServer.h
 * \brief  オブジェクトサーバー
 * 
 * \author めざし
 * \date   July 2022
 *********************************************************************/

#include<vector>
#include"ObjectBase.h"


class Game;

//オブジェクトサーバー
class ObjectServer
{
public:
	//コンストラクタ
	ObjectServer();
	//コンストラクタ
	~ObjectServer();

	//消す
	void Clear();
	//加える
	void Add(ObjectBase* obj);
	//抹消す
	void Del(ObjectBase* obj);

	//計算
	void Process(Game& g);
	//描画
	void Draw(Game& g);

	std::vector<ObjectBase*>* List() { return&vObject; }

private:
	//Addリストのオブジェクトを追加する
	void AddListObjects();
	// Delリストのオブジェクトを削除する
	void DelListObjects();

protected:
	//ObjectBaseを登録するリスト
	std::vector<ObjectBase*> vObject;
	//追加するオブジェクトリスト
	std::vector<ObjectBase*> vAdd;
	//削除するオブジェクトリスト
	std::vector<ObjectBase*> vDel;
};
