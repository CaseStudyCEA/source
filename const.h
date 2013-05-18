/***********************************************************************/
/*! @file  const.h
 *  @brief
 *  
 *  @author 
 *  @date 
 */
/***********************************************************************/
#ifndef ___CONST___
#define ___CONST___

#include"common.h"

class MESHPATH
{
public:
	static const char* YUKA();
};

class TEXPATH
{
public:
	static const char* FADEMASK();
};

class TEXKEY
{
public:
	static const uint FADEMASK();
	static const uint SUM();
};

class MESHKEY
{
public:
	static const uint YUKA();
	static const uint SUM();
};

class EFFECTPATH
{
public:
	static const char* NONE();
	static const char* TOON();
};

#endif