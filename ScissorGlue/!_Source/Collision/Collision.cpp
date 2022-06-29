/*****************************************************************//**
 * \file   Collision.cpp
 * \brief  Õ“Ë”»’è
 * 
 * \author ‚ß‚´‚µ
 * \date   June 2022
 *********************************************************************/
#include "Collision.h"
#include "DxLib.h"
#include <sstream>


// AABB‚ÌŒğ·”»’è
bool Intersect(const AABB& a, const AABB& b) {
	// ®‚ªˆê‚Â‚Å‚àtrue‚È‚çŒğ·‚µ‚Ä‚¢‚È‚¢
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

	// ˆÈ‰º‚Ì‚æ‚¤‚É’Zk‚µ‚½‹Lq‚à‚ ‚é
	//bool no = a.max.x < b.min.x ||
	//					b.max.x < a.min.x ||
	//					a.max.y < b.min.y ||
	//					b.max.y < a.min.y;
	//return !no;
}

// AABB‚Ì•`‰æ
void AABB::Draw(int red, int green, int blue) const {
	DrawBoxAA(static_cast<float>(min.x), static_cast<float>(min.y),
		static_cast<float>(max.x), static_cast<float>(max.y), GetColor(red, green, blue), FALSE);
}

// ü•ª‚Ì•`‰æ
void LineSegment::Draw(int red, int green, int blue) const {
	DrawLineAA(static_cast<float>(start.x), static_cast<float>(start.y),
		static_cast<float>(end.x), static_cast<float>(end.y), GetColor(red, green, blue), 2);
}