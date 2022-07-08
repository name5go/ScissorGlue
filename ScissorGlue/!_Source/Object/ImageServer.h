#pragma once
/*****************************************************************//**
 * \file   ImageServer.h
 * \brief  �摜�ǂݍ��ނ��
 * 
 * \author �߂���
 * \date   July 2022
 *********************************************************************/

#include	<unordered_map>

class ImageServer
{
public:
	//������
	static void Init();
	//���
	static void Release();
	//ClearGraph
	static void ClearGraph();
	//�摜�ǂݍ��ނ��
	//�t�@�C���̃p�X������
	static int LoadGraph(const TCHAR* FileName);

	//�摜�����ǂݍ��ݗp
	//������t�@�C�����A�摜�̕�����
	//���̕������A�c�̕�����
	//�������ꂽ�摜�̏c�̑傫���A�����̑傫���A�����ǂݍ��݂�����̃O���t�B�b�N�n���h����ۑ�����int�^�̂��
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
