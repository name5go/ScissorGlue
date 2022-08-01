#pragma once

/*****************************************************************//**
 * \file   stdafx.h
 * \brief  プリコンパイル済みヘッダ
 *
 * \author めざし
 * \date   July 2022
 *********************************************************************/

 /**
	インクルードのコピペ用
#include"../PCH/stdafx.h"
#include<winsock.h>

	*/


	//ライブラリのインクルード
#include"DxLib.h"
#include<stdio.h>
#include<time.h>
#include<memory>
#include<vector>
#include<cmath>
#include <array>
#include<limits>
#include<unordered_map>
#include<string>
#include<fstream>
#include<sstream>
#include"../picojson/picojson.h"//picojson.h

//ヘッダーのインクルード
#include"../Aplication/Game.h"//ゲームヘッダー
#include"../BackGround/BackGround.h"//バックグラウンド
#include"../Collision/Collision.h"//衝突判定ヘッダー
#include"../Map/MapChips.h"//マップチップヘッダー
#include"../Math/Math.h"//MATHヘッダー
#include"../Player/Player.h"//プレイヤー
#include"../Player/Scissor.h"//ハサミ
#include"../MovingObjects/MovingBlocks.h"//動く床

//object関連のヘッダー
#include"../Object/ImageServer.h"//イメージサーバーのヘッダー
#include"../Object/ObjectBase.h"//オブジェクトベース
#include"../Object/ObjectServer.h"//オブジェクトサーバー
#include"../Object/SoundServer.h"//サウンドサーバー
