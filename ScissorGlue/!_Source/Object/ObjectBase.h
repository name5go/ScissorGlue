#pragma once

class Game;

// オブジェクトクラス
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
	int		_cg[2];		// 画像(2枚アニメ)
	int		_cgNum;		// 使う画像枚数
	int		_x, _y;		// 座標（基準位置）
	int		_vx, _vy;	// 基準位置から描画時の差分
	int		_w, _h;		// 大きさ
	int		_spd;		// 移動速度
	int		_g;			// 重力による加速値
	int		_stand;		// 床フラグ。着地していたら1

	// 当たり判定用（座標_x,_y位置からの差分）
	int		_hit_x, _hit_y;
	int		_hit_w, _hit_h;

	int		_cnt;		// 動作カウンタ

};
