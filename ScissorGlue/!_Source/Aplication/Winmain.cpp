/*****************************************************************//**
 * \file   winmain.cpp
 * \brief  �G���g���[�|�C���g
 * 
 * \author mezashi
 * \date   June 2022
 *********************************************************************/

#include<DxLib.h>
#include <stdio.h>
#include <time.h>
#include<memory>
#include"../Aplication/Game.h"
#include"../Object/ImageServer.h"


//�G���g���[�|�C���g
int WINAPI WinMain(
	_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,_In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	OutputDebugString("---Winmain�J�n---\n");

	//�E�B���h�E���[�h�ύX
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)
	{	// �G���[���N�����璼���ɏI��
		return -1;
	}
	
	//��ʉ𑜓x��1920x1080�ŃJ���[�r�b�g����32bit�ɐݒ�
	SetGraphMode(SCREEN_W, SCREEN_H, SCREEN_DEPTH);
	
	//DX���C�u������������
	DxLib_Init();
	
	//�`����ʂ𗠂ɂ���
	SetDrawScreen(DX_SCREEN_BACK);
	
	// ����������
	srand((unsigned int)time(NULL));
	
	
	//�Q�[���N���X�̃|�C���^����
	Game* g = new Game();
	
	
	//�Q�[���̃��C�����[�vescape�ŏI��
	while (ProcessMessage() != -1)
	{
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}
//�e�햽�߂Ԃ�����
		g->Input();//����
		g->Process();//�v�Z
		g->Render();//�`��
	}

	//�C���[�W�T�[�o�[���
	ImageServer::Release();
	//�Q�[���N���X�̉��
	delete g;
	// Dx���C�u�����I��
	DxLib_End();
	return 0;
}
