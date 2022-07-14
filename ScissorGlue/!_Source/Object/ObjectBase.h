#pragma once
/*****************************************************************//**
 * \file   ObjectBase.h
 * \brief  オブジェクトベース
 * 
 * \author めざし
 * \date   July 2022
 *********************************************************************/

#include"../Collision/Collision.h"
#include"../Math/Math.h"

class Game;

//オブジェクトクラス
class ObjectBase
{
public:
	//コンストラクタ
	ObjectBase(Game& g);
	//デストラクタ
	virtual ~ObjectBase();

	//種別の列挙
	enum class Type {
		kBase,//0ベース
		kPlayer,//1プレイヤー
		kBackGround,//2背景
		kEnemy,//3エネミー
	};
	virtual Type GetType() = 0;

	//初期化
	virtual void Init();
	//計算
	virtual void Process(Game& g);
	//描画
	void Draw(Game& g);

	//AABBを利用したコリジョン周りとその更新
	virtual void UpDateCollision();
	virtual void DrawCollision();
	virtual AABB& GetCollision() { return collision; }
	virtual Vector2& GetPosition() { return pos; }
	virtual void SetPosition(Vector2 pPos) { pos = pPos; }
	virtual Vector2& GetSize() { return size; }
	virtual void SetSize(Vector2 pSize) { size = pSize; }

	//ダメージ周りの処理に必要なものの追加


	//プロセスに含まれる移動周りの計算
	
	//移動周りの命令//左右移動とジャンプ処理もここに入れるつもりなこと忘れんな！
	void Gravity(Game& g);


public:
	Game& pGame;

	int cgPic[2];//画像
	int cgNum;	//画像枚数
	int xWorld, yWorld;	//ワールド座標のXとY
	int xCamera, yCamera;	//描画時の座標
	int wPic, hPic;	//画像の縦の大きさと横の大きさ

	int besideInertia,verticalInertia;	//内部蓄積慣性、左から横慣性と縦慣性
	int besideSpeed,verticalSpeed;	//スピード（横の加速度	//重力の強さ(縦の加速度
	
	int standFlag;	//接地フラグ0空中1地上
	
	int xHit, yHit;	//当たり判定用
	int wHit, hHit;

protected:
	AABB collision;//当たり判定
	Vector2 pos;//座標
	Vector2 size;//サイズ
	Vector2 colPos, colSize;//当たり判定の位置とサイズ
	
	int cnt;	//カウント
};
