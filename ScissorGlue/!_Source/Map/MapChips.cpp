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