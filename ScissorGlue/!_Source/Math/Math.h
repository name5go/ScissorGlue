/*****************************************************************//**
 * \file   Math.h
 * \brief  �v�Z�Ɏg������Ƒf�ފۃR�s
 * 
 * \author �߂���
 * \date   June 2022
 *********************************************************************/

#pragma once

#include <cmath>
#include <limits>
#include <array>
#include <DxLib.h>

namespace Math {
	// �~����
	constexpr double Pi = 3.1415926535f;
	constexpr double TwoPi = Pi * 2.0f;
	constexpr double PiOver2 = Pi / 2.0f;

	// �x������Ǔx(���W�A��)�ɕϊ�
	inline double ToRadians(double degrees) {
		return degrees * Pi / 180.0f;
	}
	// �Ǔx����x��(�f�B�O���[)�ɕϊ�
	inline double ToDegrees(double radians) {
		return radians * 180.0f / Pi;
	}
	// ��̒l�̑傫���l���擾
	template <typename T>
	T Max(const T& a, const T& b) {
		return (a < b ? b : a);
	}
	// ��̒l�̏������l���擾
	template <typename T>
	T Min(const T& a, const T& b) {
		return (a < b ? a : b);
	}
	// ��̒l�̊ԂŃN�����v����
	template <typename T>
	T Clamp(const T& value, const T& lower, const T& upper) {
		return Min(upper, Max(lower, value));
	}
}

// 2D�x�N�g���N���X
class Vector2 {
public:
	// x����,y����
	double x, y;
	// �R���X�g���N�^
	Vector2() noexcept = default;
	constexpr Vector2(double inX, double inY) noexcept
    : x{inX}
    , y{inY} {
  }
	// �x�N�g���̉��Z a + b ���O���֐�
	friend Vector2 operator+(const Vector2& a, const Vector2& b) {
		return { a.x + b.x, a.y + b.y };
	}
	// �x�N�g���̌��Z a - b ���O���֐�
	friend Vector2 operator-(const Vector2& a, const Vector2& b) {
		return { a.x - b.x, a.y - b.y };
	}
	// �x�N�g���̃X�J���[�{ v * scalar ���O���֐�
	friend Vector2 operator*(const Vector2& v, double scalar) {
		return { v.x * scalar, v.y * scalar };
	}
	// �x�N�g���̃X�J���[�{ scalar * v ���O���֐�
	friend Vector2 operator*(double scalar, const Vector2& v) {
		return { v.x * scalar, v.y * scalar };
	}
	// �x�N�g�����Z���
	Vector2& operator+=(const Vector2& right) {
		x += right.x;
		y += right.y;
		return *this;
	}
	// �x�N�g�����Z���
	Vector2& operator-=(const Vector2& right) {
		x -= right.x;
		y -= right.y;
		return *this;
	}
	// �x�N�g���̃X�J����Z���
	Vector2& operator*=(double scalar) {
		x *= scalar;
		y *= scalar;
		return *this;
	}
	// �x�N�g���̑傫��
	double Length() const {
		return std::sqrt(x * x + y * y);
	}
	// �x�N�g���̐��K��
	void Normalize() {
		auto length = Length();
		x /= length;
		y /= length;
	}
	static Vector2 Normalize(const Vector2& vec) {
		auto temp = vec;
		temp.Normalize();
		return temp;
	}

	// �x�N�g���̓���(Dot product) a�Eb
	static double Dot(const Vector2& a, const Vector2& b) {
		return (a.x * b.x + a.y * b.y);
	}
	// �x�N�g���̊O��(Cross product) a�~b
	static double Cross(const Vector2& a, const Vector2& b) {
		return (a.x * b.y - a.y * b.x);
	}
	// �x�N�g���̍s��ϊ�
	static Vector2 Transform(const Vector2& vec, const class Matrix3& mat, double w = 1.0f);
};

// (1-1)�s��N���X
class Matrix3 {
public:
	// 3��~3�s
	std::array<std::array<double, 3>, 3> m;
	constexpr Matrix3() {
		*this = Matrix3::Identity;
	}
	constexpr Matrix3(
		double m00, double m01, double m02,
		double m10, double m11, double m12,
		double m20, double m21, double m22
	) noexcept
    : m{ m00, m01, m02,
         m10, m11, m12,
         m20, m21, m22 }
	{}

	// (3)�s��̏�Z
	friend Matrix3 operator*(const Matrix3& l, const Matrix3& r) {
		return {
			// row 0
			l.m[0][0] * r.m[0][0] + l.m[0][1] * r.m[1][0] + l.m[0][2] * r.m[2][0],
			l.m[0][0] * r.m[0][1] + l.m[0][1] * r.m[1][1] + l.m[0][2] * r.m[2][1],
			l.m[0][0] * r.m[0][2] + l.m[0][1] * r.m[1][2] + l.m[0][2] * r.m[2][2],
			// row 1
			l.m[1][0] * r.m[0][0] + l.m[1][1] * r.m[1][0] + l.m[1][2] * r.m[2][0],
			l.m[1][0] * r.m[0][1] + l.m[1][1] * r.m[1][1] + l.m[1][2] * r.m[2][1],
			l.m[1][0] * r.m[0][2] + l.m[1][1] * r.m[1][2] + l.m[1][2] * r.m[2][2],
			// row 2
			l.m[2][0] * r.m[0][0] + l.m[2][1] * r.m[1][0] + l.m[2][2] * r.m[2][0],
			l.m[2][0] * r.m[0][1] + l.m[2][1] * r.m[1][1] + l.m[2][2] * r.m[2][1],
			l.m[2][0] * r.m[0][2] + l.m[2][1] * r.m[1][2] + l.m[2][2] * r.m[2][2],
		};
	}
	Matrix3& operator*=(const Matrix3& right) {
		*this = *this * right;
		return *this;
	}
	// (1-2)��]�s��̍쐬
	static Matrix3 CreateRotation(double theta) {
		using std::sin;	using std::cos;
		return {
			cos(theta), sin(theta), 0.0f,
			-sin(theta), cos(theta), 0.0f,
			0.0f, 0.0f, 1.0f,
		};
	}
	// (1-3)�g�k�s��̍쐬
	static Matrix3 CreateScale(double xScale, double yScale) {
		return {
			xScale, 0.0f, 0.0f,
			0.0f, yScale, 0.0f,
			0.0f, 0.0f, 1.0f,
		};
	}
	static Matrix3 CreateScale(const Vector2& scaleVector) {
		return CreateScale(scaleVector.x, scaleVector.y);
	}
	static Matrix3 CreateScale(double scale) {
		return CreateScale(scale, scale);
	}
	// (1-4.)���s�ړ��s��̍쐬
	static Matrix3 CreateTranslation(const Vector2& trans) {
		return {
			1.0, 0.0, 0.0,
			0.0, 1.0, 0.0,
			trans.x, trans.y, 1.0,
		};
	}
	// �P�ʍs��
	static const Matrix3 Identity;
};

namespace MyLib {
	inline void DrawModiGraph(
		double x1, double y1,
		double x2, double y2,
		double x3, double y3,
		double x4, double y4,
		int grHandle, bool transFlag) {
		DxLib::DrawModiGraph(
			static_cast<int>(x1), static_cast<int>(y1),
			static_cast<int>(x2), static_cast<int>(y2),
			static_cast<int>(x3), static_cast<int>(y3),
			static_cast<int>(x4), static_cast<int>(y4), grHandle, transFlag);
	}
	inline void DrawModiGraph(
		Vector2& lt, Vector2& rt,
		Vector2& rb, Vector2& lb,
		int grHandle, bool transFlag) {
		DxLib::DrawModiGraph(
			static_cast<int>(lt.x), static_cast<int>(lt.y),
			static_cast<int>(rt.x), static_cast<int>(rt.y),
			static_cast<int>(rb.x), static_cast<int>(rb.y),
			static_cast<int>(lb.x), static_cast<int>(lb.y), grHandle, transFlag);
	}
	// (4-1)��]�g�k���s�ړ��s����g���ĕ`�悷��
	inline void DrawModiGraph(const Vector2& position, double zoom, double angle, int width, int height, int rgHandle) {
		// ��]�~�g�k�~���s�ړ�
		Matrix3 m = Matrix3::CreateRotation(angle);
		m *= Matrix3::CreateScale(zoom);
		m *= Matrix3::CreateTranslation(position);
		// �`�悷��摜��4�̒��_���W
		std::array<Vector2, 4> pos = {
			Vector2{-width / 2.0, -height / 2.0 },	// ���ォ��E���
			Vector2{ width / 2.0, -height / 2.0 },	// �E��
			Vector2{ width / 2.0,  height / 2.0 },	// �E��
			Vector2{-width / 2.0,  height / 2.0 }		// ����
			// ���]�p
			//Vector2{ width / 2.0, -height / 2.0 },	// �E�ォ�獶���
			//Vector2{-width / 2.0, -height / 2.0 },	// ����
			//Vector2{-width / 2.0,  height / 2.0 },	// ����
			//Vector2{ width / 2.0,  height / 2.0 }		// �E��
		};
		// 4�̒��_���W�S�Ăɍs����|���ĕϊ�����
		for (auto&& v : pos) {
			v = Vector2::Transform(v, m);
		}
		// �ϊ��������W�ŕ`�悷��
		MyLib::DrawModiGraph(pos[0], pos[1], pos[2], pos[3], rgHandle, true);
	}
};
