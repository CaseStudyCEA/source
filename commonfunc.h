/***********************************************************************/
/*! @file  commonfunc.h
 *  @brief �R�����i�֐��j
 *  
 *  @author �쌴�@�C��
 *  @date 
 */
/***********************************************************************/
/***********************************************************************/
//	�C���N���[�h�K�[�h
/***********************************************************************/
#pragma once
/***********************************************************************/
//	�C���N���[�h
/***********************************************************************/
#include<d3d9.h>
#include<d3dx9.h>
#include<time.h>


/***********************************************************************/
//	�}�N����`
/***********************************************************************/
#define SAFE_RELEASE(p)				safeRelease(p)
#define SAFE_RELEASE_ARRAY(p,sum)	safeReleaseArray(p,sum)
#define SAFE_DELETE(p)				safeDelete(p)
#define SAFE_DELETE_ARRAY(p)		safeDeleteArray(p)
#define FRIEND_DELETE				template<typename T> friend const bool safeDelete(T*&p);template<typename T>friend const bool safeDeleteArray(T*&p);
#define FRIEND_RELEASE				template<typename T> friend const bool safeRelease(T*&p);template<typename T>friend const bool safeReleaseArray(T*&p,int);


/***********************************************************************/
//	�萔��`
/***********************************************************************/
const float grvityacc = 9.8f;	//!<	�d�͉����x

/***********************************************************************/
//	�ʖ���`
/***********************************************************************/
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned long  ulong;

typedef signed int		sint;
typedef signed short	sshort;
typedef signed long		slong;


template<typename T>
/***********************************************************************/
/*! @brief ���S���
 * 
 *  @param[in] pt 
 *  @retval template<typename T>
inline const bool 
 */
/***********************************************************************/
inline const bool safeRelease(T* &pt)
{
	if(pt != NULL)
	{
		pt->Release();
		pt = NULL;
		return true;
	}
	return false;
}

template<typename T>
/***********************************************************************/
/*! @brief ���S�폜
 * 
 *  @param[in] pt 
 *  @param[in] nSum 
 *  @retval template<typename T>
inline const bool 
 */
/***********************************************************************/
inline const bool safeReleaseArray(T* &pt,int nSum)
{
	bool bReturnFlg = false;
	for(int nCnt = 0; nCnt < nSum; nCnt++)
	{
		if(pt[nCnt] != NULL)
		{
			pt[nCnt]->Release();
			pt[nCnt] = NULL;
			if(bReturnFlg == false)
			{
				bReturnFlg = true;
			}
		}
	}
	if(pt != NULL)
	{
		delete pt;
	}
	return bReturnFlg;
}

template<typename T>
/***********************************************************************/
/*! @brief ���S�폜
 * 
 *  @param[in] pt 
 *  @retval template<typename T>
inline const bool 
 */
/***********************************************************************/
inline const bool safeDelete(T* &pt)
{
	if(pt != NULL)
	{
		delete pt;
		pt = NULL;
		return true;
	}
	return false;
}

//-------------------------------------
//	�T�v	�������̈��S���
//		�z��̕ϐ��폜
//-------------------------------------
template<typename T>
/***********************************************************************/
/*! @brief 
 * 
 *  @param[in] pt 
 *  @retval template<typename T>
inline const bool 
 */
/***********************************************************************/
inline const bool safeDeleteArray(T* &pt)
{
	if(pt != NULL)
	{
		delete[] pt;
		pt = NULL;
		return true;
	}
	return false;
}



void worldMatrixTransform(
	D3DXMATRIXA16* matWorld,
	const D3DXVECTOR3& refvec3Pos,
	const D3DXVECTOR3& refvec3Rot,
	const D3DXVECTOR3& refvec3Scale 
	);


float gravAcc(float fElTime);
uint getRand(uint nBetween);

void MessageAlert( char szText[MAX_PATH], char szCaption[MAX_PATH]);
BOOL bindBall(D3DXVECTOR3& vec3PosA,float fARad,D3DXVECTOR3& vec3PosB,float fBRad);
BOOL bindBall(D3DXMATRIXA16& matPosA,float fARadius,D3DXMATRIXA16& matPosB,float fBRadius);
BOOL bindCircle(D3DXVECTOR2* vec2PosA,float fARad,D3DXVECTOR2* vec2PosB,float fBRad);
BOOL bindRect(D3DXVECTOR2* pvec2PosA, RECT*  pRectSizeA,D3DXVECTOR2* pvec2PosB);
D3DCOLOR colorWave(int TMax,int T);

/***********************************************************************/
/*! @namespace commonfunc
 *  @brief 
 * 
 */
/***********************************************************************/
namespace commonfunc
{
void repulsion(float* pv1Out,float v1, float v2,float m1,float m2, float e1, float e2);
};
//EOF