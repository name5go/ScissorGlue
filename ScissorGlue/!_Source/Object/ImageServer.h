#pragma once
/*****************************************************************//**
 * \file   ImageServer.h
 * \brief  画像読み込むやつ
 * 
 * \author めざし
 * \date   July 2022
 *********************************************************************/

#include	<unordered_map>

class ImageServer
{
public:
	//初期化
	static void Init();
	//解放
	static void Release();
	//ClearGraph
	static void ClearGraph();
	//画像読み込むやつ
	//ファイルのパスつっこむ
	static int LoadGraph(const TCHAR* FileName);

	//画像分割読み込み用
	//左からファイル名、画像の分割数
	//横の分割数、縦の分割数
	//分割された画像の縦の大きさ、同横の大きさ、分割読み込みしたやつのグラフィックハンドルを保存するint型のやつ
	static int LoadDivGraph(const TCHAR* FileName, int allNum,
		int xNum, int yNum,
		int xSize, int ySize, int* HandleBuf);

private:
	static std::unordered_map<std::string, int>mapGraph;
	typedef struct
	{
		int AllNum;
		int* handle;
	}DIVGRAPH;
	static std::unordered_map<std::string, DIVGRAPH>mapDivGraph;
};
