/*
** �I�u�W�F�N�g
*/

#include "DxLib.h"
#include "ObjectBase.h"
#include "../Aplication/Game.h"

ObjectBase::ObjectBase()
{
	Init();
}

ObjectBase::~ObjectBase()
{
}

void ObjectBase::Init()
{
	_g = 0;
	_cnt = 0;
	_cgNum = 1;
}

void ObjectBase::Process(Game& g)
{
	// �d�͏������s��
	_g += 1;			// �L�����́A�d�͂ɂ������l��傫������
	_y += _g;			// �d�͂ɂ������l�̕������ړ�����
	_stand = 0;			// ���ɓ������ĂȂ����Ƃ�O��ɁA���t���O���Z�b�g

	// �㉺�̓����蔻��
	if (g._mapChips.IsHit(*this, 0, _g) != 0)
	{
		// ���������B���������̂͏����H�i�d�͒l�̓v���X���������H�j
		if (_g > 0)
		{
			_stand = 1;	// ���ɓ��������̂Ńt���O�Z�b�g
		}
		_g = 0;		// �d�͂ɂ������l�����Z�b�g
	}

	_cnt++;
}

void ObjectBase::Draw(Game& g)
{
	// �J�������猩�����W�ɕύX�i���[���h���W���r���[���W�j
	int x, y;
	x = _x + _vx - g._mapChips._scrX;
	y = _y + _vy - g._mapChips._scrY;
	DrawGraph(x, y, _cg[(_cnt / 8) % _cgNum], TRUE);

	// �J���p�B�����蔻���\������
//	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		// �������`��w��
//	DrawBox(x + _hit_x, y + _hit_y, x + _hit_x + _hit_w, y + _hit_y + _hit_h, GetColor(255, 0, 0), TRUE);	// �������̐Ԃœ����蔻��`��
//	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// �s�����`��w��

}
