/***********************************************************************/
/*! @file  CInputMouse.h
 *  @brief
 *  
 *  @author 
 *  @date 
 */
/***********************************************************************/
/***********************************************************************/
//	�t�@�C����	
//	�T�v			
//	�����		
//	�X�V����		
/***********************************************************************/
//===================================================================
//	�C���N���[�h�K�[�h
//===================================================================
//===================================================================
//	�C���N���[�h
//===================================================================
#include"d3d9.h"
#include"d3dx9.h"
#define DIRECTINPUT_VERSION 0x0800		// �x���Ώ�
#define INITGUID
#include"dInput.h" 
#include"common.h"
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib,"dInput8.lib")
//===================================================================
//	�}�N����`
//===================================================================
//===================================================================
//	�񋓒�`
//===================================================================
//===================================================================
//	�N���X��`
//===================================================================
class CInputMouse
{
	//===========================================
	//	�R���X�g���N�^	
	//===========================================
public:
	CInputMouse();

	//===========================================
	//	�f�X�g���N�^		
	//===========================================
public:
	~CInputMouse();

	//===========================================
	//	�����o�֐�		
	//===========================================
public:
	void init(LPDIRECTINPUT8 pDInput);
	void update();
	void release();
	/***********************************************************************/
	/*! @brief 
	 * 
	 *  @retval LPDIRECTINPUTDEVICE8 
	 */
	/***********************************************************************/
	LPDIRECTINPUTDEVICE8 getDiDMouse(){return _pDIDMouse;}	///<�}�E�X
	BYTE getPrsMouseButton(short sButton);
	BYTE getPrevMouseButton(short sButton);
	BYTE getTrgMouseButton(short sButton);
	BYTE getRlsMouseButton(short sButton);
	BYTE getPrsMouseButton(short sButton)const;
	BYTE getPrevMouseButton(short sButton)const;
	BYTE getTrgMouseButton(short sButton)const;
	BYTE getRlsMouseButton(short sButton)const;
	POINT getPrevPoint();
	POINT getPoint();
	POINT getPointWindow();
	POINT getPointWindowPrev();
	POINT getPrevPoint()const;
	POINT getPoint()const;
	POINT getPointWindow()const;
	POINT getPointWindowPrev()const;
	LONG getMouselX();
	LONG getMouselY();
	BOOL getDragFlg();
protected:
private:

	//===========================================
	//	�����o�ϐ�		
	//===========================================
protected:
private:
	LPDIRECTINPUTDEVICE8 _pDIDMouse;	///<�}�E�X
	DIMOUSESTATE2	_MouseState;		///< �}�E�X���z��
	DIMOUSESTATE2	_MouseStatePrev;	///< ���O�}�E�X���z��
	DIMOUSESTATE2	_MouseStateTrg;		///< �g���K�[�}�E�X���z��
	DIMOUSESTATE2	_MouseStateRls;		///< �����[�X�}�E�X���z��
	POINT			_MousePos;			///< �}�E�X���W
	POINT			_MousePosPrev;		///< �}�E�X���W
	POINT			_MousePosWindow;			///< �}�E�X���W
	POINT			_MousePosWindowPrev;		///< �}�E�X���W
	BOOL			_DragFlg;			///< �h���b�O�t���O
};
//EOF