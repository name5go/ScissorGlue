/*****************************************************************//**
 * \file   Collision.cpp
 * \brief  衝突判定
 * 
 * \author めざし
 * \date   June 2022
 *********************************************************************/
#include "Collision.h"
#include "DxLib.h"
#include <sstream>


// AABBの交差判定
bool Intersect(const AABB& a, const AABB& b) {
	// 式が一つでもtrueなら交差していない
	if (a.max.x < b.min.x) {
		return false;
	}
	if (b.max.x < a.min.x) {
		return false;
	}
	if (a.max.y < b.min.y) {
		return false;
	}
	if (b.max.y < a.min.y) {
		return false;
	}
	return true;

	// 以下のように短縮した記述もある
	//bool no = a.max.x < b.min.x ||
	//					b.max.x < a.min.x ||
	//					a.max.y < b.min.y ||
	//					b.max.y < a.min.y;
	//return !no;
}

// AABBの描画
void AABB::Draw(int red, int green, int blue) const {
	DrawBoxAA(static_cast<float>(min.x), static_cast<float>(min.y),
		static_cast<float>(max.x), static_cast<float>(max.y), GetColor(red, green, blue), FALSE);
}

// 線分の描画
void LineSegment::Draw(int red, int green, int blue) const {
	DrawLineAA(static_cast<float>(start.x), static_cast<float>(start.y),
		static_cast<float>(end.x), static_cast<float>(end.y), GetColor(red, green, blue), 2);
}