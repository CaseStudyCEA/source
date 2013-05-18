/***********************************************************************/
/*! @file  CCamera.h
 *  @brief
 *  
 *  @author 
 *  @date 
 */
/***********************************************************************/
#pragma once

/***********************************************************************/
//	インクルード部
/***********************************************************************/
#include<d3dx9.h>
#include<d3d9.h>
#include"common.h"
#include"CCamera.h"


/***********************************************************************/
//	クラス定義
/***********************************************************************/
class CCamera
{

public:
	explicit CCamera();			//	コンストラクタ
	CCamera(const CCamera&);	//	コピーコンストラクタ
	virtual ~CCamera();			//	デストラクタ

public:
	const D3DXMATRIXA16* getMatView();	///<	ビューマトリクスの取得
	virtual void init();				///<	初期化
	virtual void update();				///<	更新
	void setEyeX(const float fX);		///<	視点座標Ｘ設定
	void setEyeY(const float fY);		///<	視点座標Ｙ設定
	void setEyeZ(const float fZ);		///<	視点座標Ｚ設定
	void setEye(D3DXVECTOR3& vec3Eye);	///<	視点座標設定
	void setAt(D3DXVECTOR3& vec3At);	///<	注視点座標設定
	void setUp(D3DXVECTOR3& vec3Up);	///<	アップベクトル設定
	D3DXVECTOR3& getEye();				///<	視点座標取得	
	D3DXVECTOR3& getAt();				///<	注視点座標取得
	D3DXVECTOR3& getUp();				///<	アップベクトル取得
	D3DXMATRIXA16& position();			///<	座標マトリクス取得

protected:
	D3DXVECTOR3 _vec3Eye;	//!<	カメラ座標
	D3DXVECTOR3 _vec3At;	//!<	注視点
	D3DXVECTOR3 _vec3Up;	//!<	アップベクトル
	D3DXMATRIXA16 _matView;	//!<	ビューマトリクス
	D3DXMATRIXA16 _matPose;	//!<	姿勢マトリクス
	bool  _bUpdateFlg;		//!<	更新フラグ
	float _fZOffset;		//!<	カメラの奥行きのオフセット
	float _fZRotDef;		//!<	カメラＺ軸での回転差分
	float _fAngle;			//!<	移動時回転単位
};
//EOF