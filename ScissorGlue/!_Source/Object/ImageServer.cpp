/*****************************************************************//**
 * \file   Image.cpp
 * \brief  イメージサーバー
 * 
 * \author めざし
 * \date   July 2022
 *********************************************************************/

#include"ImageServer.h"

//静的メンバ実体
std::unordered_map<std::string, int>ImageServer::mapGraph;
std::unordered_map<std::string, ImageServer::DIVGRAPH>ImageServer::mapDivGraph;

//初期化
void ImageServer::Init()
{
	//画像と分割読み込みされた画像全部削除
	mapGraph.clear();
	mapDivGraph.clear();
}

//解放
void ImageServer::Release()
{
	ClearGraph;
}

//消すやつ
void ImageServer::ClearGraph()
{
	//すべてのデータを削除する
	for (auto itr = mapGraph.begin(); itr != mapGraph.end(); itr++)
	{
		DeleteGraph(itr->second);
	}
	mapGraph.clear();

	for (auto itr = mapDivGraph.begin(); itr != mapDivGraph.end(); itr++)
		{
			for (int i = 0; i < itr->second.AllNum; i++)
			{
				DeleteGraph(itr->second.handle[i]);
			}
			delete[]itr->second.handle;
		}
	mapDivGraph.clear();
	}

//画像読み込み
int ImageServer::LoadGraph(const TCHAR* FileName)
{
	//キーの検索
	auto itr = mapGraph.find(FileName);
	if (itr != mapGraph.end())
	{
		//見つけた
		return itr->second;
	}
	//見つけられなかった
	int cg = ::LoadGraph(FileName);
	//キーと画像をmapGraphに登録
	mapGraph[FileName] = cg;

	return cg;
}

int ImageServer::LoadDivGraph(const TCHAR* FileName, int AllNum,
	int xNum, int yNum,
	int xSize, int ySize, int* HandleBuf)
{
	//キーの検索
	auto itr = mapDivGraph.find(FileName);
	if (itr != mapDivGraph.end())
	{
		// キーがあった
		// データをコピー
		for (int i = 0; i < itr->second.AllNum; i++) {
			HandleBuf[i] = itr->second.handle[i];
		}
		return 0;
	}
	// キーが無かった
	// まずはメモリを作成する
	int* hbuf = new int[AllNum];
	int err = ::LoadDivGraph(FileName, AllNum, xNum, yNum, xSize, ySize, hbuf);     // DXLIBのAPIを呼ぶので、::を先頭に付け、このクラスの同じ名前の関数と区別する
	if (err == 0) {
		// 成功
		// キーとデータをmapに登録
		mapDivGraph[FileName].AllNum = AllNum;
		mapDivGraph[FileName].handle = hbuf;
		// データをコピー
		for (int i = 0; i < AllNum; i++) {
			HandleBuf[i] = hbuf[i];
		}
	}

	return err;

}


