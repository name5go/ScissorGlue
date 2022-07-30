#pragma once
/*****************************************************************//**
 * \file   MapChips.h
 * \brief  �}�b�v�`�b�v
 * 
 * \author �߂���
 * \date   July 2022
 *********************************************************************/

#include"../PCH/stdafx.h"
#include<winsock.h>


class Game;
class ObjectBase;
class Scissor;

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

	//�v�Z
	void Process(Game& g);
	//�`��
	void Draw(Game& g);

	//�Փ˒���
	int CheckHit(int x, int y);
	//�Փ˒���
	int IsHit(ObjectBase& o, int mx, int my);

	//���[�h�W�F�C�\��
	bool LoadJson(std::string folderpath, std::string filename);

	//�}�b�v�`�b�v��̐؂�\�菈���p�̊֐�
	virtual void Cut(Scissor&s);//�؂���
	virtual void Paste(Scissor&s);//�\��t��
	virtual void Rotate(Scissor& s);//��]

	//����R���W�����p


	//�}�b�v�`�b�v���I�u�W�F�N�g�ɕϊ�
	void	CreateMapChipToObjects(Game& g);

	


public:
	//�}�b�v�̃T�C�Y�i�`�b�v��
	int wMap, hMap;
	//�`�b�v�摜�f�[�^
	int chipCount;
	int wChipCount, hChipCount;
	int wChip, hChip;//�`�b�v�̑傫��


	float angleChip;//�`�b�v��]�p�Q�p�x

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
