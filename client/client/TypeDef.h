#ifndef _WDD_TYPEDEF_H_ 
#define _WDD_TYPEDEF_H_

#include <windows.h> 
#include <string.h>
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include "MsgInfo.h"

typedef std::vector<int> vtInt;
typedef std::vector<std::string> vtStr;
typedef std::map<int,std::string> mapStr;
typedef	std::list<MsgInfo> listInfo;

//�����ֽ�char*ת��Ϊ���ֽ�wchar_t*
inline wchar_t* charTowchat_t( const char* szStr )
{
	int nLen = MultiByteToWideChar( CP_ACP, MB_PRECOMPOSED, szStr, -1, NULL, 0 );
	if (nLen == 0)
	{
		return NULL;
	}
	wchar_t* pResult = new wchar_t[nLen];
	MultiByteToWideChar( CP_ACP, MB_PRECOMPOSED, szStr, -1, pResult, nLen );
	return pResult;
}

//�����ֽ�wchar_t*ת��Ϊ���ֽ�char*
inline char* wchat_tTochar( const wchar_t* szStr )
{
	int nLen = WideCharToMultiByte( CP_ACP, 0, szStr, -1, NULL, 0, NULL, NULL );
	if (nLen == 0)
	{
		return NULL;
	}
	char* pResult = new char[nLen];
	WideCharToMultiByte( CP_ACP, 0, szStr, -1, pResult, nLen, NULL, NULL );
	return pResult;
}

#endif