#pragma once
/*
 * @file  Math.h
 * @brief ���w�֘A
 *
 * @date 2017-07-04
 * @version 4.0
 *
 * Copyright(C) Amusement Media Academy All rights Resved.
 */
#include"../PCH/stdafx.h"
#include<winsock.h>

namespace Math {
  // (1-2)�~����
  constexpr float Pi = 3.1415926535f;
  constexpr float TwoPi = Pi * 2.0f;
  constexpr float PiOver2 = Pi / 2.0f;
  
  // (3.)�x������Ǔx(���W�A��)�ɕϊ�
	inline float ToRadians(float degrees) {
		return degrees * Pi / 180.0f;
	}
  // �Ǔx����x��(�f�B�O���[)�ɕϊ�
  inline float ToDegrees(float radians) {
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
  float x, y;
  // �R���X�g���N�^
  Vector2(float inX = 0, float inY = 0)
    :x{inX}
    ,y{inY} {
  }
  // �x�N�g���̉��Z a + b ���O���֐�
  friend Vector2 operator+(const Vector2& a, const Vector2& b) {
    return {a.x + b.x, a.y + b.y};
  }
  // �x�N�g���̌��Z a - b ���O���֐�
  friend Vector2 operator-(const Vector2& a, const Vector2& b) {
    return {a.x - b.x, a.y - b.y};
  }
  // �x�N�g���̃X�J���[�{ v * scalar ���O���֐�
  friend Vector2 operator*(const Vector2& v, float scalar) {
    return {v.x * scalar, v.y * scalar};
  }
  // �x�N�g���̃X�J���[�{ scalar * v ���O���֐�
  friend Vector2 operator*(float scalar, const Vector2& v) {
    return {v.x * scalar, v.y * scalar};
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
  Vector2& operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
  }
  // �x�N�g���̑傫��
  float Length() const {
    return std::sqrt(x * x + y * y);
  }
  // �x�N�g���̐��K��
  void Normalize() {
    auto length = Length();
    x /= length;
    y /= length;
  }
};
