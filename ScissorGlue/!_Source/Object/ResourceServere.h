#pragma once
/*****************************************************************//**
 * \file   ImageServere.h
 * \brief  画像読み込むやつ
 * 
 * \author めざし
 * \date   July 2022
 *********************************************************************/

class ResourceServer {
public:
	static	void	Init();
	static	void	Release();

	static	void	ClearGraph();
	static	int		LoadGraph(const TCHAR* FileName);
	static int		LoadDivGraph(const TCHAR* FileName, int AllNum,
		int XNum, int YNum,
		int XSize, int YSize, int* HandleBuf);

private:
	static std::unordered_map<std::string, int>	_mapGraph;
	typedef struct {
		int		AllNum;
		int* handle;
	} DIVGRAPH;
	static std::unordered_map<std::string, DIVGRAPH>	_mapDivGraph;
};

