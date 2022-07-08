/*****************************************************************//**
 * \file   MapChips.cpp
 * \brief  �}�b�v�`�b�v
 * 
 * \author �߂���
 * \date   July 2022
 *********************************************************************/

#include"DxLib.h"
#include"MapChips.h"
#include"../Object/ImageServer.h"
#include"../Aplication/Game.h"
#include"../Object/ObjectBase.h"
#include"../Collision/Collision.h"
#include"../Math/Math.h"

#include<memory>
#include<fstream>

//�}�b�v�`�b�v���N���X�̃R���X�g���N�^
MapChips::MapChips()
{
	//�X�N���[���̒l
	xScr = 0;
	yScr = 0;
}

//�}�b�v�`�b�v���̃f�X�g���N�^
MapChips::~MapChips()
{
}

//�v�Z
void MapChips::Process(Game& g)
{
	//�J�������}�b�v�f�[�^�𒴂��Ȃ��悤�ɂ���
	if (xScr < 0) { xScr = 0; }
	if (xScr > wMap * wChip - SCREEN_W) { xScr = wMap * wChip - SCREEN_W; }
	if (yScr < 0) { yScr = 0; }
	if (yScr > hMap * hChip - SCREEN_H) { yScr = hMap * hChip - SCREEN_H; }
}

//�`��
void MapChips::Draw()
{
	int x, y, layer;
	for (layer = 0; layer < vMap.size(); layer++)
	{
		for (y = 0; y < hMap; y++)
		{
			for (x = 0; x < wMap; x++)
			{
				int xPos = x * wChip - xScr;
				int yPos = y * hChip - yScr;
				int noChip = vMap[layer][y][x].idMapChip;

				noChip--;
				if (noChip >= 0)
				{
					DrawGraph(xPos, yPos, vCgChip[noChip], TRUE);

					/// �J���p�F���̃`�b�v�͓����蔻����s�����̂��H
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


//�}�b�v�`�b�v�̓����蔻��
//�@����
//x,y=�}�b�v�`�b�v�̈ʒu(x,y)�`�b�v�P��
//�@�ߒl
//0 �����蔻����s��Ȃ�
//0�ȊO�@�����蔻����s��(�`�b�v�ԍ���Ԃ�

int MapChips::CheckHit(int x, int y)
{
	//�}�b�v�`�b�v�ʒu�̓}�b�v�f�[�^����͂ݏo���Ă邩
	if (0 <= x && x < wMap && 0 <= y && y < hMap)
	{
		//�݂͂łĂ��Ȃ�

		//�}�b�v�`�b�vID��0�ȊO�͓����蔻����s��
		//���݁A���C���[�͍l������Ă��Ȃ��B
		int layer = 0;
		int noChip = vMap[layer][y][x].idMapChip;

		//�Փ˔���̂���ID���ǂ������`�F�b�N
		int idTable[] =
		{
			2,3,4,7,8,
			9,10,11,12,13,14,15,16,
			20,21,21,
			-1//�Ō�
		};
		int i = 0;
		while (idTable[i] != -1)
		{
			if (noChip == idTable[i])
			{
				//��������
				return noChip;
			}
			i++;
		}
	}
	return 0;
}


//�I�u�W�F�N�g�ƃ}�b�v�`�b�v�������������̔���A����ѓ��������ꍇ�̏���


int MapChips::IsHit(ObjectBase& o, int mx, int my)
{
	int x, y;

	// �L������`���쐬����
	int l, t, r, b;		// ����(left,top) - �E��(right,bottom)
	l = o.xWorld + o.xHit;
	t = o.yWorld + o.yHit;
	r = o.xWorld + o.xHit + o.wHit - 1;
	b = o.yWorld + o.yHit + o.hHit - 1;

	// �L�����̍�����W�`�E�����W�ɂ�����}�b�v�`�b�v�ƁA�����蔻����s��
	for (y = t / hChip; y <= b / hChip; y++)
	{
		for (x = l / wChip; x <= r / wChip; x++)
		{
			// (x,y)�́A�}�b�v�`�b�v�̍��W�i�`�b�v�P�ʁj
			// ���̈ʒu�̃`�b�v�͓����邩�H
			int noChip = CheckHit(x, y);
			if (noChip != 0)
			{	// ���̃`�b�v�Ɠ��������B
				// X,Y�̈ړ����������āA���̔��Ε����ɕ␳����
				if (mx < 0)
				{	// ���ɓ����Ă����̂ŁA�E�ɕ␳
					o.xWorld = x * wChip + wChip - (o.xHit);
				}
				if (mx > 0)
				{	// �E�ɓ����Ă����̂ŁA���ɕ␳
					o.xWorld = x * wChip - (o.xHit + o.wHit);
				}
				if (my > 0)
				{	// ���ɓ����Ă����̂ŁA��ɕ␳
					o.yWorld = y * hChip - (o.yHit + o.hHit);
				}
				if (my < 0)
				{	// ��ɓ����Ă����̂ŁA���ɕ␳
					o.yWorld = y * hChip + hChip - (o.yWorld);
				}
				// ���������̂Ŗ߂�
				return 1;
			}
		}
	}

	// ������Ȃ�����
	return 0;
}

//���[�h�W�F�C�\��
bool MapChips::LoadJson(std::string folderpath, std::string filename) {
	// �t�@�C������json�f�[�^�̓ǂݍ���
	std::ifstream ifs(folderpath + filename);
	picojson::value json;
	ifs >> json;

	// json�f�[�^����p�����[�^���擾
	picojson::object jsRoot = json.get<picojson::object>();
	wMap = (int)jsRoot["width"].get<double>();
	hMap = (int)jsRoot["height"].get<double>();

	// �^�C���Z�b�g�擾(1�̂ݑΉ�)
	picojson::array aTileSets = jsRoot["tilesets"].get<picojson::array>();
	picojson::object jsTile = aTileSets[0].get<picojson::object>();
	chipCount = (int)jsTile["tilecount"].get<double>();
	wChipCount = (int)jsTile["columns"].get<double>();
	hChipCount = (chipCount / wChipCount);		// �v�Z�ŏo��
	wChip = (int)jsRoot["tilewidth"].get<double>();
	hChip = (int)jsRoot["tileheight"].get<double>();
	std::string strChipFile = jsTile["image"].get<std::string>();       // �摜�t�@�C����

	// �`�b�v�摜�ǂݍ���
	vCgChip.resize(chipCount);
	ImageServer::LoadDivGraph((folderpath + strChipFile).c_str()
		, chipCount, wChipCount, hChipCount
		, wChip, hChip
		, vCgChip.data());


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
			for (int y = 0; y < hMap; y++) {
				std::vector<MapChip>	vMapLine;	// 1�s���̃f�[�^
				for (int x = 0; x < wMap; x++) {
					MapChip chip;
					chip.idMapChip = (int)aData[index].get<double>();
					vMapLine.push_back(chip);
					index++;
				}
				vMapLayer.push_back(vMapLine);
			}
			// ���C���[�f�[�^��ǉ�
			vMap.push_back(vMapLayer);
		}
	}

	return true;
}
