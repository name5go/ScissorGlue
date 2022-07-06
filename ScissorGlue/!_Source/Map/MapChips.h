#pragma once
#pragma once

class Game;
class ObjectBase;

// json�t�@�C�����g�����߂ɕK�v
#include "../picojson/picojson.h"
#include <string>


// �ЂƂ̃}�b�v�`�b�v
class MapChip {
public:
	int		_id;	// �`�b�vID
};


// �}�b�v�`�b�v�N���X
class MapChips {
public:
	MapChips();
	~MapChips();

	void	Process(Game& g);
	void	Draw();

	int		CheckHit(int x, int y);
	int		IsHit(ObjectBase& o, int mx, int my);

	bool	LoadJson(std::string folderpath, std::string filename);


public:
	// �}�b�v�̃T�C�Y�i�`�b�v���j
	int		_mapW, _mapH;		// �}�b�v�T�C�Y

	// �`�b�v�摜�f�[�^
	int		_chipCount;
	int		_chipCountW, _chipCountH;
	int		_chipW, _chipH;


	// �X�N���[��
	int		_scrX, _scrY;


private:
	std::vector<int>	_vCgChip;		// �}�b�v�`�b�v�摜

	// �}�b�v�f�[�^
	std::vector<std::vector<std::vector<MapChip>>>	_vMap;		// ���C���[�Ή��}�b�v�f�[�^[layer][y][x]
};
