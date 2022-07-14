#pragma once
/*****************************************************************//**
 * \file   MapChips.h
 * \brief  �}�b�v�`�b�v
 * 
 * \author �߂���
 * \date   July 2022
 *********************************************************************/

#include"../picojson/picojson.h"
#include<string>

class Game;
class ObjectBase;

//�}�b�v�`�b�v�V���O��
class MapChip
{
public:
	//�`�b�vID
	int idMapChip;
};

//�}�b�v�`�b�vs�N���X
class MapChips
{
public:
	//�R���X�g���N�^
	MapChips();
	//�f�X�g���N�^
	~MapChips();

	void Init();
	//�v�Z
	void Process(Game& g);
	//�`��
	void Draw();

	//�Փ˒���
	int CheckHit(int x, int y);
	//�Փ˒���
	int IsHit(ObjectBase& o, int mx, int my);

	//���[�h�W�F�C�\��
	bool LoadJson(std::string folderpath, std::string filename);

public:
	//�}�b�v�̃T�C�Y�i�`�b�v��
	int wMap, hMap;
	//�`�b�v�摜�f�[�^
	int chipCount;
	int wChipCount, hChipCount;
	int wChip, hChip;

	//�X�N���[��
	int xScr, yScr;

private:
	//�}�b�v�`�b�v�摜
	std::vector<int> vCgChip;

	//�}�b�v�`�b�v�摜�𑽎����z��Ő錾
	//���C���[�Ή��}�b�v�f�[�^
	//[layer][y][x]
	std::vector<std::vector<std::vector<MapChip>>>vMap;
};
