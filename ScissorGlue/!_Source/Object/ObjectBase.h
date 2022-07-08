#pragma once
/*****************************************************************//**
 * \file   ObjectBase.h
 * \brief  オブジェクトベース
 * 
 * \author めざし
 * \date   July 2022
 *********************************************************************/

class Game;

//オブジェクトクラス
class ObjectBase
{
public:
	//コンストラクタ
	ObjectBase();
	//デストラクタ
	~ObjectBase();

	//オブジェクトタイプ
	enum class OBJECTTYPE
	{
		PLAYER,
	};

	void Process();
	void Draw();

public:
	int _cg[2];
	





};
