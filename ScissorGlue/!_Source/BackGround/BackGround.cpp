/*
** �w�i
*/

#include "DxLib.h"
#include "BackGround.h"
#include "../Object/ResourceServer.h"

BackGround::BackGround()
{
	_cg = ResourceServer::LoadGraph("res/platformer_BG.png");		// �w�i�摜�����[�h����
}

BackGround::~BackGround()
{
}

void	BackGround::Draw()
{
	DrawGraph(0, 0, _cg, FALSE);
}

