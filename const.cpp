/***********************************************************************/
/*! @file  const.cpp
 *  @brief íËêî
 *  
 *  @author êÏå¥Å@óCâÓ
 *  @date 
 */
/***********************************************************************/
#include"const.h"

const char* MESHPATH::YUKA(){	return "data/model/nanase_pose.x";}
const char* TEXPATH::FADEMASK(){return "data/texture/fademask.jpg";}



enum eTEXKEY{
	TEX_FADEMASK,
	TEX_SUM,
};
const uint TEXKEY::FADEMASK()	{	return TEX_FADEMASK;	}
const uint TEXKEY::SUM()		{	return TEX_SUM;		}



enum eMESHKEY
{
	MESH_YUKA,
	MESH_SUM,
};


const uint MESHKEY::YUKA()	{ return MESH_YUKA;}
const uint MESHKEY::SUM()	{ return MESH_SUM;}

const char* EFFECTPATH::NONE(){return "a";}
const char* EFFECTPATH::TOON(){return "A";}