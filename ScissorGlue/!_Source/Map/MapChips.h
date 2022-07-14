#pragma once
/*****************************************************************//**
 * \file   MapChips.h
 * \brief  マップチップ
 * 
 * \author めざし
 * \date   July 2022
 *********************************************************************/

#include"../picojson/picojson.h"
#include<string>

class Game;
class ObjectBase;

//マップチップシングル
class MapChip
{
public:
	//チップID
	int idMapChip;
};

//マップチップsクラス
class MapChips
{
public:
	//コンストラクタ
	MapChips();
	//デストラクタ
	~MapChips();

	void Init();
	//計算
	void Process(Game& g);
	//描画
	void Draw();

	//衝突調査
	int CheckHit(int x, int y);
	//衝突調査
	int IsHit(ObjectBase& o, int mx, int my);

	//ロードジェイソン
	bool LoadJson(std::string folderpath, std::string filename);

public:
	//マップのサイズ（チップ数
	int wMap, hMap;
	//チップ画像データ
	int chipCount;
	int wChipCount, hChipCount;
	int wChip, hChip;

	//スクロール
	int xScr, yScr;

private:
	//マップチップ画像
	std::vector<int> vCgChip;

	//マップチップ画像を多次元配列で宣言
	//レイヤー対応マップデータ
	//[layer][y][x]
	std::vector<std::vector<std::vector<MapChip>>>vMap;
};
