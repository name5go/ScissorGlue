#pragma once

/*****************************************************************//**
 * \file   stdafx.h
 * \brief  �v���R���p�C���ς݃w�b�_
 *
 * \author �߂���
 * \date   July 2022
 *********************************************************************/

 /**
	�R�s�y�p
#include"../PCH/stdafx.h"
#include<winsock.h>

	*/


	//���C�u�����̃C���N���[�h
#include"DxLib.h"
#include<stdio.h>
#include<time.h>
#include<memory>
#include<vector>
#include<cmath>
#include<limits>
#include<unordered_map>
#include<string>
#include<fstream>
#include<sstream>

//�w�b�_�[�̃C���N���[�h
#include"../Aplication/Game.h"//�Q�[���w�b�_�[
#include"../BackGround/BackGround.h"//�o�b�N�O���E���h
#include"../Collision/Collision.h"//�Փ˔���w�b�_�[
#include"../Map/MapChips.h"//�}�b�v�`�b�v�w�b�_�[
#include"../Math/Math.h"//MATH�w�b�_�[
#include"../Player/Player.h"//�v���C���[

//object�֘A�̃w�b�_�[
#include"../Object/ImageServer.h"//�C���[�W�T�[�o�[�̃w�b�_�[
#include"../Object/ObjectBase.h"//�I�u�W�F�N�g�x�[�X
#include"../Object/ObjectServer.h"//�I�u�W�F�N�g�T�[�o�[
#include"../Object/SoundServer.h"//�T�E���h�T�[�o�[
