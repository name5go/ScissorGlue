#pragma once
/*****************************************************************//**
 * \file   ImageServere.h
 * \brief  âÊëúì«Ç›çûÇﬁÇ‚Ç¬
 * 
 * \author ÇﬂÇ¥Çµ
 * \date   July 2022
 *********************************************************************/

#include	<unordered_map>

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

