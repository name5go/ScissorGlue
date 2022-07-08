/*****************************************************************//**
 * \file   Image.cpp
 * \brief  �C���[�W�T�[�o�[
 * 
 * \author �߂���
 * \date   July 2022
 *********************************************************************/

#include"DxLib.h"
#include"ImageServer.h"

//�ÓI�����o����
std::unordered_map<std::string, int>ImageServer::mapGraph;
std::unordered_map<std::string, ImageServer::DIVGRAPH>ImageServer::mapDivGraph;

//������
void ImageServer::Init()
{
	//�摜�ƕ����ǂݍ��݂��ꂽ�摜�S���폜
	mapGraph.clear();
	mapDivGraph.clear();
}

//���
void ImageServer::Release()
{
	ClearGraph;
}

//�������
void ImageServer::ClearGraph()
{
	//���ׂẴf�[�^���폜����
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

//�摜�ǂݍ���
int ImageServer::LoadGraph(const TCHAR* FileName)
{
	//�L�[�̌���
	auto itr = mapGraph.find(FileName);
	if (itr != mapGraph.end())
	{
		//������
		return itr->second;
	}
	//�������Ȃ�����
	int cg = ::LoadGraph(FileName);
	//�L�[�Ɖ摜��mapGraph�ɓo�^
	mapGraph[FileName] = cg;

	return cg;
}
