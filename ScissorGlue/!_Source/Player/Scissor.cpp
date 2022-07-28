/*****************************************************************//**
 * \file   Scissor.cpp
 * \brief  
 * 
 * \author めざし
 * \date   July 2022
 *********************************************************************/
#include"../Player/Scissor.h"

//コンストラクタ
Scissor::Scissor(Player& p,MapChips& mp)
	:_p(p),_mp(mp)
{
	cgPic[0] = ImageServer::LoadGraph("!_Resources\\!_Pic\\player\\ball.png");
	Init();
}
//初期化
void Scissor::Init()
{
	cgNum = 1;
	wPic = 32;
	hPic = 48;
	xWorld = 32;
	yWorld = 0;
	xCamera = -wPic / 2;
	yCamera = -hPic + 1;
	besideInertia = 0;
	verticalInertia = 0;
	xHit = -16;
	yHit = -47;
	wHit = 32;
	hHit = 48;
}

//デストラクタ
Scissor::~Scissor()
{
}

//計算
void Scissor::Process(Game& g)
{
	xWorld = _p.xPl()+_p.LeftRight*50;
	yWorld = _p.yPl();

	xCutPos=xWorld + _p.LeftRight * 50;
	yCutPos = yWorld;

	Input(g);
	ScissorPos();
}
void Scissor::ScissorPos()
{
	xCursor = xWorld / 40;
	yCursor = yWorld / 40 - 1;
}

//入力
void Scissor::Input(Game& g)
{
	if(g.gTrg&PAD_INPUT_1)
	{
		g._mapChips.Cut(*this);
	}
	if (g.gTrg&PAD_INPUT_2)
	{
		g._mapChips.Paste(*this);
	}

}

