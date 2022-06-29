/*****************************************************************//**
 * \file   winmain.cpp
 * \brief  �G���g���[�|�C���g
 * 
 * \author mezashi
 * \date   June 2022
 *********************************************************************/

#include<DxLib.h>


int CALLBACK winmain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
	OutputDebugString("---Winmain�J�n---\n");
	//�E�B���h�E���[�h�ύX
	ChangeWindowMode(TRUE);
	//��ʉ𑜓x��1920x1080�ŃJ���[�r�b�g����32bit�ɐݒ�
	SetGraphMode(1920, 1080, 32);
	//DX���C�u������������
	DxLib_Init();
	//�`����ʂ𗠂ɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	//���낢��N���X��˂����ނƂ���

	//�Q�[���̃��C�����[�vescape�ŏI��
	while (ProcessMessage() != -1) {
		if (CheckHitKey(KEY_INPUT_ESCAPE)) {
			break;
		}

		//�N���X������
	}
}
