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

#include<memory>
#include<fstream>

//マップチップｓクラスのコンストラクタ
MapChips::MapChips()
{
	//スクロールの値
	xScr = 0;
	yScr = 0;
}

//マップチップｓのデストラクタ
MapChips::~MapChips()
{
}

//計算
void MapChips::Process(Game& g)
{
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
				int xPos = x * wChip - xScr;
				int yPos = y * hChip - yScr;
				int noChip = vMap[layer][y][x].idMapChip;

				noChip--;
				if (noChip >= 0)
				{
					DrawGraph(xPos, yPos, vCgChip[noChip], TRUE);

					/// 開発用：このチップは当たり判定を行うものか？
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