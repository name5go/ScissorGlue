/*****************************************************************//**
 * \file   MapChips.cpp
 * \brief  マップチップ
 * 
 * \author めざし
 * \date   July 2022
 *********************************************************************/

#include"DxLib.h"
#include"MapChips.h"
#include"../Object/ImageServer.h"
#include"../Aplication/Game.h"
#include"../Object/ObjectBase.h"
#include"../Collision/Collision.h"
#include"../Math/Math.h"
#include"../Player/Player.h"

#include<memory>
#include<fstream>

//マップチップｓクラスのコンストラクタ
MapChips::MapChips()
{
	Init();
}
//初期化
void MapChips::Init()
{
	//スクロールの値
	xScr = 0;	yScr = 0;
}

//マップチップｓのデストラクタ
MapChips::~MapChips()
{
}

//当たり判定更新
void MapChips:: UpdateMapCol()
{
	mapCol.min = mapPos;
	mapCol.max = mapPos + mapSize;
}
//当たり判定描画
void MapChips:: DrawMapCol()
{
	mapCol.DrawBoxCol(rand() % 256, rand() % 256, rand() % 256);
}


//計算
void MapChips::Process(Game& g)
{
	UpdateMapCol();
	//カメラがマップデータを超えないようにする
	if (xScr < 0) { xScr = 0; }
	if (xScr > wMap * wChip - SCREEN_W) { xScr = wMap * wChip - SCREEN_W; }
	if (yScr < 0) { yScr = 0; }
	if (yScr > hMap * hChip - SCREEN_H) { yScr = hMap * hChip - SCREEN_H; }
}

//描画
void MapChips::Draw()
{
	int x, y, layer;
	for (layer = 0; layer < vMap.size(); layer++)
	{
		for (y = 0; y < hMap; y++)
		{
			for (x = 0; x < wMap; x++)
			{
				mapPos.x = x * wChip - xScr;
				mapPos.y = y * hChip - yScr;
				int noChip = vMap[layer][y][x].idMapChip;

				noChip--;
				if (noChip >= 0)
				{
					DrawGraph(mapPos.x, mapPos.y, vCgChip[noChip], TRUE);

					/// 開発用：このチップは当たり判定を行うものか？
					if (CheckHit(x, y) != 0)
					{
						DrawMapCol();
					}
				}
			}
		}
	}
}


//マップチップの当たり判定
//　引数
//x,y=マップチップの位置(x,y)チップ単位
//　戻値
//0 当たり判定を行わない
//0以外　当たり判定を行う(チップ番号を返す

int MapChips::CheckHit(int x, int y)
{
	//マップチップ位置はマップデータからはみ出してるか
	if (0 <= x && x < wMap && 0 <= y && y < hMap)
	{
		//はみでていない

		//マップチップIDが0以外は当たり判定を行う
		//現在、レイヤーは考慮されていない。
		int layer = 0;
		int noChip = vMap[layer][y][x].idMapChip;

		//衝突判定のあるIDかどうかをチェック
		int idTable[] =
		{
			2,3,4,7,8,
			9,10,11,12,13,14,15,16,
			20,21,21,
			-1//最後
		};
		int i = 0;
		while (idTable[i] != -1)
		{
			if (noChip == idTable[i])
			{
				//当たった
				return noChip;
			}
			i++;
		}
	}
	return 0;
}


//オブジェクトとマップチップが当たったかの判定、および当たった場合の処理


int MapChips::IsHit(ObjectBase& o, int mx, int my)
{
	for(auto&&)
}

//ロードジェイソン
bool MapChips::LoadJson(std::string folderpath, std::string filename) {
	// ファイルからjsonデータの読み込み
	std::ifstream ifs(folderpath + filename);
	picojson::value json;
	ifs >> json;

	// jsonデータからパラメータを取得
	picojson::object jsRoot = json.get<picojson::object>();
	wMap = (int)jsRoot["width"].get<double>();
	hMap = (int)jsRoot["height"].get<double>();

	// タイルセット取得(1つのみ対応)
	picojson::array aTileSets = jsRoot["tilesets"].get<picojson::array>();
	picojson::object jsTile = aTileSets[0].get<picojson::object>();
	chipCount = (int)jsTile["tilecount"].get<double>();
	wChipCount = (int)jsTile["columns"].get<double>();
	hChipCount = (chipCount / wChipCount);		// 計算で出す
	wChip = (int)jsRoot["tilewidth"].get<double>();
	hChip = (int)jsRoot["tileheight"].get<double>();
	std::string strChipFile = jsTile["image"].get<std::string>();       // 画像ファイル名

	// チップ画像読み込み
	vCgChip.resize(chipCount);
	ImageServer::LoadDivGraph((folderpath + strChipFile).c_str()
		, chipCount, wChipCount, hChipCount
		, wChip, hChip
		, vCgChip.data());


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
			for (int y = 0; y < hMap; y++) {
				std::vector<MapChip>	vMapLine;	// 1行分のデータ
				for (int x = 0; x < wMap; x++) {
					MapChip chip;
					chip.idMapChip = (int)aData[index].get<double>();
					vMapLine.push_back(chip);
					index++;
				}
				vMapLayer.push_back(vMapLine);
			}
			// レイヤーデータを追加
			vMap.push_back(vMapLayer);
		}
	}

	return true;
}
