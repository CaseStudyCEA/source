/***********************************************************************/
/*! @file  CSceneBase.cpp
 *  @brief	�V�[���N���X�x�[�X
 *  
 *  @author �쌴�@�C��
 *  @date	2013/04/30
 */
/***********************************************************************/
#include"CSceneBase.h"


/***********************************************************************/
/*! @brief �R���X�g���N�^
 */
/***********************************************************************/
CSceneBase::CSceneBase(
	)
	:_UpdateFlg(TRUE),
	_DrawFlg(TRUE),
	_EndFlg(FALSE)
{
}


/***********************************************************************/
/*! @brief �f�X�g���N�^
 */
/***********************************************************************/
CSceneBase::~CSceneBase()
{
}

/***********************************************************************/
/*! @brief �X�V�����t���OOFF
 */
/***********************************************************************/
void CSceneBase::updateFlgOFF(){_UpdateFlg = FALSE;}


/***********************************************************************/
/*! @brief �`�揈���t���OOFF
 */
/***********************************************************************/
void CSceneBase::drawFlgOFF(){ _DrawFlg = FALSE;}


/***********************************************************************/
/*! @brief �X�V�����t���OON
 */
/***********************************************************************/
void CSceneBase::updateFlgON(){ _UpdateFlg = TRUE;}


/***********************************************************************/
/*! @brief �`�揈���t���OON
 */
/***********************************************************************/
void CSceneBase::drawFlgON(){ _DrawFlg = TRUE;}


/***********************************************************************/
/*! @brief �X�V�����t���O�擾
 * 
 *  @retval const BOOL �X�V�����t���O
 */
/***********************************************************************/
const BOOL CSceneBase::getUpdateFlg(){return	_UpdateFlg;}	//	�X�V�����t���O�擾


/***********************************************************************/
/*! @brief �`�揈���t���O�擾
 * 
 *  @retval const BOOL �`�揈���t���O
 */
/***********************************************************************/
const BOOL CSceneBase::getDrawFlg(){return	_DrawFlg;}


/***********************************************************************/
/*! @brief �폜�����t���O�擾
 * 
 *  @retval const BOOL �폜�����t���O
 */
/***********************************************************************/
const BOOL CSceneBase::getEndFlg(){return _EndFlg;}