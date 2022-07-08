/*****************************************************************//**
 * \file   Collision.cpp
 * \brief  衝突判定
 * 
 * \author めざし
 * \date   July 2022
 *********************************************************************/

#include "Collision.h"
#include "DxLib.h"
#include <sstream>


// AABBの交差判定
bool Intersect(const AABB& a, const AABB& b) 
{
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

}


// AABBの描画
void AABB::Draw(int red, int green, int blue) const {
	DrawBoxAA(min.x, min.y, max.x, max.y, GetColor(red, green, blue), FALSE);
}

// 線分の描画
void LineSegment::Draw(int red, int green, int blue) const {
	DrawLineAA(start.x, start.y, end.x, end.y, GetColor(red, green, blue), 5);
}