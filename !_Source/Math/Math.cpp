/*****************************************************************//**
 * \file   Math.cpp
 * \brief  計算に使うやつ。授業素材丸コピしてるので中身ほとんど理解していないです。。。
 * 
 * \author めざし
 * \date   June 2022
 *********************************************************************/

#include "Math.h"

const Matrix3 Matrix3::Identity = {
	1.0, 0.0, 0.0,
	0.0, 1.0, 0.0,
	0.0, 0.0, 1.0
};

// (2)ベクトルの行列変換
Vector2 Vector2::Transform(const Vector2& vec, const Matrix3& mat, double w) {
	return {
		vec.x * mat.m[0][0] + vec.y * mat.m[1][0] + w * mat.m[2][0],
		vec.x * mat.m[0][1] + vec.y * mat.m[1][1] + w * mat.m[2][1],
	};
}
