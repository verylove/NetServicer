#pragma once
#include <Winsock2.h>
#include "TypeDef.h"

//封装了通信的一些操作
class CCommunicationOpt
{
public:
	CCommunicationOpt(void);
	~CCommunicationOpt(void);

	int CreateSocket();	//初始化参数

	int Start();		//创建线程

	void CloseSocket();

	int Send(std::string str);
	int Send(const char* szBuf,int nSize);

	DWORD RecvMsg();
private:
	SOCKET m_st;		
	HANDLE m_hdRecv;	//接收线程句柄
	static const int nMax_Recv = 1024;
	listInfo m_ListInfo;
	CRITICAL_SECTION m_cs;
};

