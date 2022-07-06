/*
** マップチップ
*/

#include "DxLib.h"
#include "MapChips.h"
#include "../Object/ResourceServer.h"
#include "../Aplication/Game.h"
#include "../Object/ObjectBase.h"

#include <memory>
#include <fstream>


MapChips::MapChips()
{
	// スクロール値
	_scrX = 0;
	_scrY = 0;

}

MapChips::~MapChips()
{
}

void	MapChips::Process(Game& g)
{
	// カメラがマップデータを超えないようにする
	if (_scrX < 0) { _scrX = 0; }
	if (_scrX > _mapW * _chipW - SCREEN_W) { _scrX = _mapW * _chipW - SCREEN_W; }
	if (_scrY < 0) { _scrY = 0; }
	if (_scrY > _mapH * _chipH - SCREEN_H) { _scrY = _mapH * _chipH - SCREEN_H; }

}


void	MapChips::Draw()
{
	int x, y, layer;
	for (layer = 0; layer < _vMap.size(); layer++)
	{
		for (y = 0; y < _mapH; y++)
		{
			for (x = 0; x < _mapW; x++)
			{
				int pos_x = x * _chipW - _scrX;
				int pos_y = y * _chipH - _scrY;
				int chip_no = _vMap[layer][y][x]._id;
				// .tmxのcsv形式は、透明を0とし、画像のチップは[1]から始まる。
				// そのため、全体的に数値を-1する。透明は-1となるので、if判定を追加
				chip_no--;
				if (chip_no >= 0)
				{
					DrawGraph(pos_x, pos_y, _vCgChip[chip_no], TRUE);

					// 開発用：このチップは当たり判定を行うものか？
					if (CheckHit(x, y) != 0)
					{
						/*
						SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		// 半透明描画指定
						DrawBox(pos_x, pos_y, pos_x + _chipW, pos_y + _chipH, GetColor(255, 0, 0), TRUE);	// 半透明の赤で当たり判定描画
						SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// 不透明描画指定
						*/
					}
				}
			}
		}
	}
}





// マップチップとの当たり判定
// 引数：
//   x,y = マップチップの位置(x,y) チップ単位
// 戻値：
//   0 : 当たり判定を行わない
//   0以外 : 当たり判定を行う（チップ番号を返す）
int MapChips::CheckHit(int x, int y)
{
	// マップチップ位置はマップデータからはみ出ているか？
	if (0 <= x && x < _mapW && 0 <= y && y < _mapH)
	{	// はみでていない

		// マップチップIDが0以外は当たり判定を行う
		// 現在、レイヤーは考慮されていない
		int layer = 0;
		int chip_no = _vMap[layer][y][x]._id;

		// 当たるIDかどうかをチェック
		int idtable[] =
		{
			2, 3, 4, 7, 8,
			9, 10, 11, 12, 13, 14, 15, 16,
			20, 21, 22,
			-1		// 最後
		};
		int i = 0;
		while (idtable[i] != -1)
		{
			if (chip_no == idtable[i])
			{
				// 当たった
				return chip_no;
			}
			i++;
		}
	}

	// 当たっていない
	return 0;
}


// オブジェクトとマップチップが当たったかの判定、および当たった場合の処理
// 引数：
//   o = オブジェクト
//   mx = Xの移動方向(マイナス:0:プラス)
//   my = Yの移動方向(マイナス:0:プラス)
// 戻値：
//   0 : 当たってない
//   1 : 当たった
int MapChips::IsHit(ObjectBase& o, int mx, int my)
{
	int x, y;

	// キャラ矩形を作成する
	int l, t, r, b;		// 左上(left,top) - 右下(right,bottom)
	l = o._x + o._hit_x;
	t = o._y + o._hit_y;
	r = o._x + o._hit_x + o._hit_w - 1;
	b = o._y + o._hit_y + o._hit_h - 1;

	// キャラの左上座標～右下座標にあたるマップチップと、当たり判定を行う
	for (y = t / _chipH; y <= b / _chipH; y++)
	{
		for (x = l / _chipW; x <= r / _chipW; x++)
		{
			// (x,y)は、マップチップの座標（チップ単位）
			// この位置のチップは当たるか？
			int chip_no = CheckHit(x, y);
			if (chip_no != 0)
			{	// このチップと当たった。
				// X,Yの移動方向を見て、その反対方向に補正する
				if (mx < 0)
				{	// 左に動いていたので、右に補正
					o._x = x * _chipW + _chipW - (o._hit_x);
				}
				if (mx > 0)
				{	// 右に動いていたので、左に補正
					o._x = x * _chipW - (o._hit_x + o._hit_w);
				}
				if (my > 0)
				{	// 下に動いていたので、上に補正
					o._y = y * _chipH - (o._hit_y + o._hit_h);
				}
				if (my < 0)
				{	// 上に動いていたので、下に補正
					o._y = y * _chipH + _chipH - (o._hit_y);
				}
				// 当たったので戻る
				return 1;
			}
		}
	}

	// 当たらなかった
	return 0;
}


bool MapChips::LoadJson(std::string folderpath, std::string filename) {
	// ファイルからjsonデータの読み込み
	std::ifstream ifs(folderpath + filename);
	picojson::value json;
	ifs >> json;

	// jsonデータからパラメータを取得
	picojson::object jsRoot = json.get<picojson::object>();
	_mapW = (int)jsRoot["width"].get<double>();
	_mapH = (int)jsRoot["height"].get<double>();

	// タイルセット取得(1つのみ対応)
	picojson::array aTileSets = jsRoot["tilesets"].get<picojson::array>();
	picojson::object jsTile = aTileSets[0].get<picojson::object>();
	_chipCount = (int)jsTile["tilecount"].get<double>();
	_chipCountW = (int)jsTile["columns"].get<double>();
	_chipCountH = (_chipCount / _chipCountW);		// 計算で出す
	_chipW = (int)jsRoot["tilewidth"].get<double>();
	_chipH = (int)jsRoot["tileheight"].get<double>();
	std::string strChipFile = jsTile["image"].get<std::string>();       // 画像ファイル名

	// チップ画像読み込み
	_vCgChip.resize(_chipCount);
	ResourceServer::LoadDivGraph((folderpath + strChipFile).c_str()
		, _chipCount, _chipCountW, _chipCountH
		, _chipW, _chipH
		, _vCgChip.data());


	// レイヤー情報の取得
	picojson::array aLayers = jsRoot["layers"].get<picojson::array>();

	// レイヤー内データの取得
	for (int i = 0; i < aLayers.size(); i++) {

		picojson::object jsLayer = aLayers[i].get<picojson::object>();		// レイヤーオブジェクト
		// レイヤー種類が「tilelayer」のものをカウントする
		if (jsLayer["type"].get<std::string>() == "tilelayer") {
			picojson::array aData = jsLayer["data"].get<picojson::array>();			// マップ配列
			int index = 0;
			std::vector<std::vector<MapChip>>	vMapLayer;	// 1レイヤー分のデータ
			for (int y = 0; y < _mapH; y++) {
				std::vector<MapChip>	vMapLine;	// 1行分のデータ
				for (int x = 0; x < _mapW; x++) {
					MapChip chip;
					chip._id = (int)aData[index].get<double>();
					vMapLine.push_back(chip);
					index++;
				}
				vMapLayer.push_back(vMapLine);
			}
			// レイヤーデータを追加
			_vMap.push_back(vMapLayer);
		}
	}

	return true;
}


