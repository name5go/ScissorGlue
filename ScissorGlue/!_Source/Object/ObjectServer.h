#pragma once
/*****************************************************************//**
 * \file   ObjectServer.h
 * \brief  オブジェクトサーバー
 * 
 * \author めざし
 * \date   July 2022
 *********************************************************************/

#include<vector>
#include<memory>
#include<DxLib.h>


class Game;
class ObjectBase;

//オブジェクトサーバー
class ObjectServer
{
public:
	//コンストラクタ
	ObjectServer(Game& pGame);
	//コンストラクタ
	~ObjectServer();

	//消すやつ
	void Clear();
	//加える
	void Add(std::unique_ptr<ObjectBase> obj);

	//分回す命令
	void Draw(Game& g);
	void Process(Game& g);


protected:
	Game& g;
	std::vector<std::unique_ptr<ObjectBase>>vObj;
};