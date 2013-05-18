/***********************************************************************/
/*! @file  CSceneTestSpace.cpp
 *  @brief テスト空間
 *  
 *  @author 川原　佑介
 *  @date 
 */
/***********************************************************************/
#include"CSceneTestSpace.h"
#include"const.h"
#include"CSpriteFactory.h"
#include"CMeshFactory.h"

#include"CCamera.h"
#include"CLight.h"
#include"CScreen.h"
#include"CEffect.h"
#include"CEffectToon.h"
#include"CFactory.h"

CMesh *TestMesh[2] = {NULL,};
CLight* pLight;
CCamera* pCamera;
CSprite* pSprite;
CEffectBase* pEffect;
CEffectBase* pEffect2;

/***********************************************************************/
/*! @brief 
 * 
 *  @retval  
 */
/***********************************************************************/
CSceneTestSpace::CSceneTestSpace()
{
	release();
}

/***********************************************************************/
/*! @brief 
 * 
 *  @retval  
 */
/***********************************************************************/
CSceneTestSpace::~CSceneTestSpace()
{
	release();
}

#include"CEffect.h"
/***********************************************************************/
/*! @brief 
 * 
 *  @retval void
 */
/***********************************************************************/
D3DXVECTOR4 v4lD(1.0f,1.0f,1.0f,1.0f);
void CSceneTestSpace::init()
{
	release();
	MESHFACTORY->reserve(50);
	MESHFACTORY->registMesh(MESHKEY::YUKA(),MESHPATH::YUKA());
	TestMesh[0] = MESHFACTORY->create(MESHKEY::YUKA());
	TestMesh[1] = MESHFACTORY->create(MESHKEY::YUKA());
	pCamera = new CCamera;

	pCamera->setEyeZ(-30);
	pCamera->update();

	pLight  = new CLight;
	pLight->setDirectionalLight(
		COLORVALUE(1.0f,1.0f,1.0f,1.0f),
		D3DXVECTOR3(0,-1.0f,0)
		);

	CEffectToon* pEffectToon = new CEffectToon;
	
	//pEffectToon->setlightDir(&v4lD);

	TestMesh[0]->setEffect(pEffectToon);

	pEffect2 = new CEffect(
		"data/fx/Hlsl.fx",
		"Hsls",
		"DecalTex",
		"WVP");

	TestMesh[1]->setEffect(pEffect2);

	pLight->lightON();


}

/***********************************************************************/
/*! @brief 
 * 
 *  @retval void
 */
/***********************************************************************/
void CSceneTestSpace::update()
{
	CHECK_UPDATE;

	D3DXVECTOR3 Eye = pCamera->getEye();
	if(GetAsyncKeyState('S'))
	{
		pCamera->setEyeZ(Eye.z - 0.5f);
	}
	else if(GetAsyncKeyState('W'))
	{
		pCamera->setEyeZ(Eye.z + 0.5f);
	}
	if(GetAsyncKeyState('E'))
	{
		pCamera->setEyeY(Eye.y - 0.5f);
	}
	else if(GetAsyncKeyState('R'))
	{
		pCamera->setEyeY(Eye.y + 0.5f);
	}



	pCamera->update();
}

/***********************************************************************/
/*! @brief 
 * 
 *  @retval void
 */
/***********************************************************************/
void CSceneTestSpace::draw()
{
	CHECK_DRAW;
	static D3DXMATRIXA16 mat[2];
	static float rot = 0;
	D3DXMatrixIdentity(&mat[0]);
	D3DXMatrixIdentity(&mat[1]);

	D3DXMatrixRotationY(&mat[0],rot);
	D3DXMatrixRotationY(&mat[1],rot);

	mat[0]._41 -= 2;
	mat[1]._41 += 2;

	rot += 0.01f;

	rot = rot >= 360.0f ? 0.0f : rot;

	CSCREEN->update();

	TestMesh[0]->draw(
		pCamera->getMatView(),
		&mat[0]
		);
	TestMesh[1]->draw(
		pCamera->getMatView(),
		&mat[1]
		);

}

/***********************************************************************/
/*! @brief 
 * 
 *  @retval void
 */
/***********************************************************************/
void CSceneTestSpace::release()
{
	SAFE_DELETE(TestMesh[0]);
	SAFE_DELETE(TestMesh[1]);
	SAFE_DELETE(pCamera);
	SAFE_DELETE(pLight);
	SAFE_DELETE(pSprite);
	SAFE_DELETE(pEffect);
	SAFE_DELETE(pEffect2);
}

/***********************************************************************/
/*! @brief 
 * 
 *  @retval CSceneBase * 
 */
/***********************************************************************/
CSceneBase * CSceneTestSpace::nextScene()
{
	return this;
}