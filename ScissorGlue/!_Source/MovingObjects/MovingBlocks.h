#pragma once
/*****************************************************************//**
 * \file   MovingObjects.h
 * \brief  �����u���b�N
 * 
 * \author �߂���
 * \date   July 2022
 *********************************************************************/

#include"../PCH/stdafx.h"

class MovingBlocks :public ObjectBase
{
public:
	MovingBlocks();
	~MovingBlocks();
	virtual OBJECTTYPE GetType() { return ObjectBase::OBJECTTYPE::MOVINGBLOCKS; }

public:
	void Init();
	void Process(Game& g);

};
