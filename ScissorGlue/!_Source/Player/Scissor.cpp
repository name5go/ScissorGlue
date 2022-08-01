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
	cgPic[0] = ImageServer::LoadGraph("!_Resources\\!_Pic\\player\\ball2.png");
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
	//ハサミの座標をプレイヤーの座標準拠で更新し続ける
	xWorld = _p.xPl()+_p.LeftRight*100;
	yWorld = _p.yPl();

	//xCutPos=xWorld + _p.LeftRight * 50;
	//yCutPos = yWorld;

	Input(g);//入力を検知して切り貼りを行う
	ScissorPos(g);//切り貼り先の座標を計算
}
void Scissor::ScissorPos(Game& g)
{
	xCursor = xWorld / g._mapChips.wChip;
	yCursor = yWorld / g._mapChips.wChip - 1;
}

//入力
void Scissor::Input(Game& g)
{
	//Zキー押されればカット情報の回転
	if (g.gTrg & PAD_INPUT_1)
	{
		g._mapChips.AngleRotation(*this);
		g._mapChips.PlacemnetRotation(*this);
	}

	//Xキーが押されればカット
	if(g.gTrg&PAD_INPUT_2)
	{
		g._mapChips.Cut(*this);
	}
	//Cキーが押されればコピー
	if (g.gTrg&PAD_INPUT_3)
	{
		g._mapChips.Paste(*this);
	}


}

