/***********************************************************************/
/*! @file  Loop.cpp
 *  @brief ゲームループ
 *  
 *  @author 川原　佑介
 *  @date 
 */
/***********************************************************************/
#include"Game.h"

#include"CInputCommon.h"
#include"CTextureFactory.h"
#include"CSpriteFactory.h"
#include"CSceneBase.h"
#include"CSceneTestSpace.h"
#include"CScreen.h"
#include"CFadeInOut.h"
#include"const.h"
#include"CDevice.h"			//デバイスクラスヘッダ

/***********************************************************************/
//	グローバル変数宣言
/***********************************************************************/
CSceneBase* pScene		= NULL;
CSceneBase* pLastScene	= NULL;	//	最後に扱ったシーン
uint		Phase		= 0;


/***********************************************************************/
//	先行宣言
/***********************************************************************/
BOOL drawBegin();	//	描画開始
void drawEnd();		//	描画終了


/***********************************************************************/
//	フェーズ
/***********************************************************************/
enum{
	P_INIT,
	P_FADEIN,
	P_UPDATE,
	P_FADEOUT,
	P_SCENE_SWITCH,
};

/***********************************************************************/
/*! @brief 初期化処理
 * 
 *  @retval void
 */
/***********************************************************************/
void gameInit()
{
	CDEVICE->init();				//デバイスの初期化
	INPUTCOMMON->createKeyboard();
	INPUTCOMMON->createMouse();
	CSceneTestSpace* ps;
	ps = new CSceneTestSpace;
	pScene = ps;

	TEXTUREFACTORY->reserve(TEXKEY::SUM());
	SPRITEFACTORY->registTexture(TEXKEY::FADEMASK(),TEXPATH::FADEMASK());
}


/***********************************************************************/
/*! @brief ループ
 * 
 *  @retval void
 */
/***********************************************************************/
void gameLoop()
{

	//...入力情報の更新
	INPUTCOMMON->update();
	pLastScene = pScene;

	switch(Phase)
	{
	case P_INIT:
		if(pLastScene != NULL)
		{
			pLastScene->release();
		}
		pScene->release();
		pScene->init();
		FADEINOUT->fadeInStart(60);
		Phase = P_FADEIN;
		break;
	case P_FADEIN:
		FADEINOUT->update();
		if(FADEINOUT->getState() == FADE_NONE)
		{
			Phase = P_UPDATE;
		}
		break;

	case P_UPDATE:
		pScene->update();
		if(pScene->getEndFlg() == TRUE)
		{
			FADEINOUT->fadeOutStart(60);
			Phase = P_FADEOUT;
		}
		break;

	case P_FADEOUT:
		FADEINOUT->update();
		if(FADEINOUT->getState() == FADE_NONE)
		{
			Phase = P_SCENE_SWITCH;
		}
		break;

	case P_SCENE_SWITCH:
		pScene = pScene->nextScene();
		Phase = P_INIT;
		break;
	}
	if(drawBegin())
	{
		pScene->draw();
		FADEINOUT->draw();
		drawEnd();
		D3DDEVICE->Present(0,0,0,0);
	}
}

/***********************************************************************/
/*! @brief 描画開始
 * 
 *  @retval BOOL 失敗
 */
/***********************************************************************/
BOOL drawBegin()
{
	//---描画処理---//
	D3DDEVICE->Clear(
		0,
		NULL,
		(D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER ),
		D3DCOLOR_RGBA(100, 100, 100, 255),
		1.0f,
		0
		);

	if(FAILED(D3DDEVICE->BeginScene()))
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

/***********************************************************************/
/*! @brief 描画終了
 * 
 *  @retval void
 */
/***********************************************************************/
void drawEnd()
{
	D3DDEVICE->EndScene();
}

/***********************************************************************/
/*! @brief 解放処理
 * 
 *  @retval void
 */
/***********************************************************************/
void gameRelease()
{
	delete pScene;
}
