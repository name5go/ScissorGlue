/*****************************************************************//**
 * \file   Math.cpp
 * \brief  �v�Z����
 * 
 * \author �߂���
 * \date   July 2022
 *********************************************************************/

#include "Math.h"

const Matrix3 Matrix3::Identity = {
	1.0, 0.0, 0.0,
	0.0, 1.0, 0.0,
	0.0, 0.0, 1.0
};

// �x�N�g���̍s��ϊ�
Vector2 Vector2::Transform(const Vector2& vec, const Matrix3& mat, double w) {
	return {
		vec.x * mat.m[0][0] + vec.y * mat.m[1][0] + w * mat.m[2][0],
		vec.x * mat.m[0][1] + vec.y * mat.m[1][1] + w * mat.m[2][1],
	};
}