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
//	�C���N���[�h��
/***********************************************************************/
#include<d3dx9.h>
#include<d3d9.h>
#include"common.h"
#include"CCamera.h"


/***********************************************************************/
//	�N���X��`
/***********************************************************************/
class CCamera
{

public:
	explicit CCamera();			//	�R���X�g���N�^
	CCamera(const CCamera&);	//	�R�s�[�R���X�g���N�^
	virtual ~CCamera();			//	�f�X�g���N�^

public:
	const D3DXMATRIXA16* getMatView();	///<	�r���[�}�g���N�X�̎擾
	virtual void init();				///<	������
	virtual void update();				///<	�X�V
	void setEyeX(const float fX);		///<	���_���W�w�ݒ�
	void setEyeY(const float fY);		///<	���_���W�x�ݒ�
	void setEyeZ(const float fZ);		///<	���_���W�y�ݒ�
	void setEye(D3DXVECTOR3& vec3Eye);	///<	���_���W�ݒ�
	void setAt(D3DXVECTOR3& vec3At);	///<	�����_���W�ݒ�
	void setUp(D3DXVECTOR3& vec3Up);	///<	�A�b�v�x�N�g���ݒ�
	D3DXVECTOR3& getEye();				///<	���_���W�擾	
	D3DXVECTOR3& getAt();				///<	�����_���W�擾
	D3DXVECTOR3& getUp();				///<	�A�b�v�x�N�g���擾
	D3DXMATRIXA16& position();			///<	���W�}�g���N�X�擾

protected:
	D3DXVECTOR3 _vec3Eye;	//!<	�J�������W
	D3DXVECTOR3 _vec3At;	//!<	�����_
	D3DXVECTOR3 _vec3Up;	//!<	�A�b�v�x�N�g��
	D3DXMATRIXA16 _matView;	//!<	�r���[�}�g���N�X
	D3DXMATRIXA16 _matPose;	//!<	�p���}�g���N�X
	bool  _bUpdateFlg;		//!<	�X�V�t���O
	float _fZOffset;		//!<	�J�����̉��s���̃I�t�Z�b�g
	float _fZRotDef;		//!<	�J�����y���ł̉�]����
	float _fAngle;			//!<	�ړ�����]�P��
};
//EOF