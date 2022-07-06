#pragma once

class Game;

// �I�u�W�F�N�g�N���X
class ObjectBase {
public:
	ObjectBase();
	~ObjectBase();

	enum class OBJECTTYPE {
		PLAYER,
	};
	virtual OBJECTTYPE	GetType() = 0;

	virtual	void	Init();
	virtual	void	Process(Game& g);
	virtual	void	Draw(Game& g);

public:
	int		_cg[2];		// �摜(2���A�j��)
	int		_cgNum;		// �g���摜����
	int		_x, _y;		// ���W�i��ʒu�j
	int		_vx, _vy;	// ��ʒu����`�掞�̍���
	int		_w, _h;		// �傫��
	int		_spd;		// �ړ����x
	int		_g;			// �d�͂ɂ������l
	int		_stand;		// ���t���O�B���n���Ă�����1

	// �����蔻��p�i���W_x,_y�ʒu����̍����j
	int		_hit_x, _hit_y;
	int		_hit_w, _hit_h;

	int		_cnt;		// ����J�E���^

};
