#pragma once
#pragma once

class Game;
class ObjectBase;

// jsonファイルを使うために必要
#include "../picojson/picojson.h"
#include <string>


// ひとつのマップチップ
class MapChip {
public:
	int		_id;	// チップID
};


// マップチップクラス
class MapChips {
public:
	MapChips();
	~MapChips();

	void	Process(Game& g);
	void	Draw();

	int		CheckHit(int x, int y);
	int		IsHit(ObjectBase& o, int mx, int my);

	bool	LoadJson(std::string folderpath, std::string filename);


public:
	// マップのサイズ（チップ数）
	int		_mapW, _mapH;		// マップサイズ

	// チップ画像データ
	int		_chipCount;
	int		_chipCountW, _chipCountH;
	int		_chipW, _chipH;


	// スクロール
	int		_scrX, _scrY;


private:
	std::vector<int>	_vCgChip;		// マップチップ画像

	// マップデータ
	std::vector<std::vector<std::vector<MapChip>>>	_vMap;		// レイヤー対応マップデータ[layer][y][x]
};
