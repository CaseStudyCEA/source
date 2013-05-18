/***********************************************************************/
/*! @file  Loop.cpp
 *  @brief �Q�[�����[�v
 *  
 *  @author �쌴�@�C��
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
#include"CDevice.h"			//�f�o�C�X�N���X�w�b�_

/***********************************************************************/
//	�O���[�o���ϐ��錾
/***********************************************************************/
CSceneBase* pScene		= NULL;
CSceneBase* pLastScene	= NULL;	//	�Ō�Ɉ������V�[��
uint		Phase		= 0;


/***********************************************************************/
//	��s�錾
/***********************************************************************/
BOOL drawBegin();	//	�`��J�n
void drawEnd();		//	�`��I��


/***********************************************************************/
//	�t�F�[�Y
/***********************************************************************/
enum{
	P_INIT,
	P_FADEIN,
	P_UPDATE,
	P_FADEOUT,
	P_SCENE_SWITCH,
};

/***********************************************************************/
/*! @brief ����������
 * 
 *  @retval void
 */
/***********************************************************************/
void gameInit()
{
	CDEVICE->init();				//�f�o�C�X�̏�����
	INPUTCOMMON->createKeyboard();
	INPUTCOMMON->createMouse();
	CSceneTestSpace* ps;
	ps = new CSceneTestSpace;
	pScene = ps;

	TEXTUREFACTORY->reserve(TEXKEY::SUM());
	SPRITEFACTORY->registTexture(TEXKEY::FADEMASK(),TEXPATH::FADEMASK());
}


/***********************************************************************/
/*! @brief ���[�v
 * 
 *  @retval void
 */
/***********************************************************************/
void gameLoop()
{

	//...���͏��̍X�V
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
/*! @brief �`��J�n
 * 
 *  @retval BOOL ���s
 */
/***********************************************************************/
BOOL drawBegin()
{
	//---�`�揈��---//
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
/*! @brief �`��I��
 * 
 *  @retval void
 */
/***********************************************************************/
void drawEnd()
{
	D3DDEVICE->EndScene();
}

/***********************************************************************/
/*! @brief �������
 * 
 *  @retval void
 */
/***********************************************************************/
void gameRelease()
{
	delete pScene;
}
