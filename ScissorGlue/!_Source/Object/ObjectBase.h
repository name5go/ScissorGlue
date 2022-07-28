#pragma once
/*****************************************************************//**
 * \file   ObjectBase.h
 * \brief  オブジェクトベース
 * 
 * \author めざし
 * \date   July 2022
 *********************************************************************/
#include"../PCH/stdafx.h"
#include<winsock.h>

//オブジェクトクラス
class ObjectBase
{
public:
	//コンストラクタ
	ObjectBase();
	//デストラクタ
	~ObjectBase();

	enum class OBJECTTYPE
	{
		PLAYER,
		SCISSOR,
	};
	virtual OBJECTTYPE GetType() = 0;

	//初期化
	virtual void Init();
	//計算
	virtual void Process(Game&g);
	//描画
	virtual void Draw(Game&g);

	

	//プロセスに含まれる移動周りの計算
	
	//移動周りの命令
	//void GoFoward();
	//void GoBack();
	void Gravity();
	//void Jump();

public:

	//画像
	int cgPic[32];
	//画像枚数
	int cgNum;
	//ワールド座標のXとY
	int xWorld, yWorld;
	//描画時の座標
	int xCamera, yCamera;
	//画像の縦の大きさと横の大きさ
	int wPic, hPic;

	//内部蓄積慣性、左から横慣性と縦慣性
	int besideInertia,verticalInertia;
	//スピード（横の加速度	//重力の強さ(縦の加速度
	int besideSpeed,verticalSpeed;
	
	//接地フラグ0空中1地上
	int standFlag;
	//左右の向きフラグ1右-1左
	int LeftRight;
	
	//当たり判定用
	int xHit, yHit;
	int wHit, hHit;
	
	//動作カウンタ
	int cnt;
};
