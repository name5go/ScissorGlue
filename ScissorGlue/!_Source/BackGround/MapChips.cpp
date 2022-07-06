/*
** �}�b�v�`�b�v
*/

#include "DxLib.h"
#include "MapChips.h"
#include "../Object/ResourceServer.h"
#include "../Aplication/Game.h"
#include "../Object/ObjectBase.h"

#include <memory>
#include <fstream>


MapChips::MapChips()
{
	// �X�N���[���l
	_scrX = 0;
	_scrY = 0;

}

MapChips::~MapChips()
{
}

void	MapChips::Process(Game& g)
{
	// �J�������}�b�v�f�[�^�𒴂��Ȃ��悤�ɂ���
	if (_scrX < 0) { _scrX = 0; }
	if (_scrX > _mapW * _chipW - SCREEN_W) { _scrX = _mapW * _chipW - SCREEN_W; }
	if (_scrY < 0) { _scrY = 0; }
	if (_scrY > _mapH * _chipH - SCREEN_H) { _scrY = _mapH * _chipH - SCREEN_H; }

}


void	MapChips::Draw()
{
	int x, y, layer;
	for (layer = 0; layer < _vMap.size(); layer++)
	{
		for (y = 0; y < _mapH; y++)
		{
			for (x = 0; x < _mapW; x++)
			{
				int pos_x = x * _chipW - _scrX;
				int pos_y = y * _chipH - _scrY;
				int chip_no = _vMap[layer][y][x]._id;
				// .tmx��csv�`���́A������0�Ƃ��A�摜�̃`�b�v��[1]����n�܂�B
				// ���̂��߁A�S�̓I�ɐ��l��-1����B������-1�ƂȂ�̂ŁAif�����ǉ�
				chip_no--;
				if (chip_no >= 0)
				{
					DrawGraph(pos_x, pos_y, _vCgChip[chip_no], TRUE);

					// �J���p�F���̃`�b�v�͓����蔻����s�����̂��H
					if (CheckHit(x, y) != 0)
					{
						/*
						SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		// �������`��w��
						DrawBox(pos_x, pos_y, pos_x + _chipW, pos_y + _chipH, GetColor(255, 0, 0), TRUE);	// �������̐Ԃœ����蔻��`��
						SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// �s�����`��w��
						*/
					}
				}
			}
		}
	}
}





// �}�b�v�`�b�v�Ƃ̓����蔻��
// �����F
//   x,y = �}�b�v�`�b�v�̈ʒu(x,y) �`�b�v�P��
// �ߒl�F
//   0 : �����蔻����s��Ȃ�
//   0�ȊO : �����蔻����s���i�`�b�v�ԍ���Ԃ��j
int MapChips::CheckHit(int x, int y)
{
	// �}�b�v�`�b�v�ʒu�̓}�b�v�f�[�^����͂ݏo�Ă��邩�H
	if (0 <= x && x < _mapW && 0 <= y && y < _mapH)
	{	// �݂͂łĂ��Ȃ�

		// �}�b�v�`�b�vID��0�ȊO�͓����蔻����s��
		// ���݁A���C���[�͍l������Ă��Ȃ�
		int layer = 0;
		int chip_no = _vMap[layer][y][x]._id;

		// ������ID���ǂ������`�F�b�N
		int idtable[] =
		{
			2, 3, 4, 7, 8,
			9, 10, 11, 12, 13, 14, 15, 16,
			20, 21, 22,
			-1		// �Ō�
		};
		int i = 0;
		while (idtable[i] != -1)
		{
			if (chip_no == idtable[i])
			{
				// ��������
				return chip_no;
			}
			i++;
		}
	}

	// �������Ă��Ȃ�
	return 0;
}


// �I�u�W�F�N�g�ƃ}�b�v�`�b�v�������������̔���A����ѓ��������ꍇ�̏���
// �����F
//   o = �I�u�W�F�N�g
//   mx = X�̈ړ�����(�}�C�i�X:0:�v���X)
//   my = Y�̈ړ�����(�}�C�i�X:0:�v���X)
// �ߒl�F
//   0 : �������ĂȂ�
//   1 : ��������
int MapChips::IsHit(ObjectBase& o, int mx, int my)
{
	int x, y;

	// �L������`���쐬����
	int l, t, r, b;		// ����(left,top) - �E��(right,bottom)
	l = o._x + o._hit_x;
	t = o._y + o._hit_y;
	r = o._x + o._hit_x + o._hit_w - 1;
	b = o._y + o._hit_y + o._hit_h - 1;

	// �L�����̍�����W�`�E�����W�ɂ�����}�b�v�`�b�v�ƁA�����蔻����s��
	for (y = t / _chipH; y <= b / _chipH; y++)
	{
		for (x = l / _chipW; x <= r / _chipW; x++)
		{
			// (x,y)�́A�}�b�v�`�b�v�̍��W�i�`�b�v�P�ʁj
			// ���̈ʒu�̃`�b�v�͓����邩�H
			int chip_no = CheckHit(x, y);
			if (chip_no != 0)
			{	// ���̃`�b�v�Ɠ��������B
				// X,Y�̈ړ����������āA���̔��Ε����ɕ␳����
				if (mx < 0)
				{	// ���ɓ����Ă����̂ŁA�E�ɕ␳
					o._x = x * _chipW + _chipW - (o._hit_x);
				}
				if (mx > 0)
				{	// �E�ɓ����Ă����̂ŁA���ɕ␳
					o._x = x * _chipW - (o._hit_x + o._hit_w);
				}
				if (my > 0)
				{	// ���ɓ����Ă����̂ŁA��ɕ␳
					o._y = y * _chipH - (o._hit_y + o._hit_h);
				}
				if (my < 0)
				{	// ��ɓ����Ă����̂ŁA���ɕ␳
					o._y = y * _chipH + _chipH - (o._hit_y);
				}
				// ���������̂Ŗ߂�
				return 1;
			}
		}
	}

	// ������Ȃ�����
	return 0;
}


bool MapChips::LoadJson(std::string folderpath, std::string filename) {
	// �t�@�C������json�f�[�^�̓ǂݍ���
	std::ifstream ifs(folderpath + filename);
	picojson::value json;
	ifs >> json;

	// json�f�[�^����p�����[�^���擾
	picojson::object jsRoot = json.get<picojson::object>();
	_mapW = (int)jsRoot["width"].get<double>();
	_mapH = (int)jsRoot["height"].get<double>();

	// �^�C���Z�b�g�擾(1�̂ݑΉ�)
	picojson::array aTileSets = jsRoot["tilesets"].get<picojson::array>();
	picojson::object jsTile = aTileSets[0].get<picojson::object>();
	_chipCount = (int)jsTile["tilecount"].get<double>();
	_chipCountW = (int)jsTile["columns"].get<double>();
	_chipCountH = (_chipCount / _chipCountW);		// �v�Z�ŏo��
	_chipW = (int)jsRoot["tilewidth"].get<double>();
	_chipH = (int)jsRoot["tileheight"].get<double>();
	std::string strChipFile = jsTile["image"].get<std::string>();       // �摜�t�@�C����

	// �`�b�v�摜�ǂݍ���
	_vCgChip.resize(_chipCount);
	ResourceServer::LoadDivGraph((folderpath + strChipFile).c_str()
		, _chipCount, _chipCountW, _chipCountH
		, _chipW, _chipH
		, _vCgChip.data());


	// ���C���[���̎擾
	picojson::array aLayers = jsRoot["layers"].get<picojson::array>();

	// ���C���[���f�[�^�̎擾
	for (int i = 0; i < aLayers.size(); i++) {

		picojson::object jsLayer = aLayers[i].get<picojson::object>();		// ���C���[�I�u�W�F�N�g
		// ���C���[��ނ��utilelayer�v�̂��̂��J�E���g����
		if (jsLayer["type"].get<std::string>() == "tilelayer") {
			picojson::array aData = jsLayer["data"].get<picojson::array>();			// �}�b�v�z��
			int index = 0;
			std::vector<std::vector<MapChip>>	vMapLayer;	// 1���C���[���̃f�[�^
			for (int y = 0; y < _mapH; y++) {
				std::vector<MapChip>	vMapLine;	// 1�s���̃f�[�^
				for (int x = 0; x < _mapW; x++) {
					MapChip chip;
					chip._id = (int)aData[index].get<double>();
					vMapLine.push_back(chip);
					index++;
				}
				vMapLayer.push_back(vMapLine);
			}
			// ���C���[�f�[�^��ǉ�
			_vMap.push_back(vMapLayer);
		}
	}

	return true;
}


