#include "StdAfx.h"
#include "CommunicationOpt.h"
#pragma comment(lib, "ws2_32.lib")

DWORD WINAPI ThreadRecv(LPVOID lpParameter)
{
	CCommunicationOpt* opt= (CCommunicationOpt*)lpParameter;
	return opt->RecvMsg();
}

CCommunicationOpt::CCommunicationOpt(void)
{
	InitializeCriticalSection(&m_cs);
}


CCommunicationOpt::~CCommunicationOpt(void)
{
	CloseSocket();
	DeleteCriticalSection(&m_cs);
}

int CCommunicationOpt::CreateSocket()
{
	WORD wVersionRequested;
	WSADATA wsaData;

	wVersionRequested = MAKEWORD( 1, 1 );

	int nRet = WSAStartup( wVersionRequested, &wsaData );
	if ( nRet != 0 ) {
		return -1;
	}

	if ( LOBYTE( wsaData.wVersion ) != 1 ||
		HIBYTE( wsaData.wVersion ) != 1 ) {
			WSACleanup( );
			return -1;
	}
	m_st = socket(AF_INET,SOCK_STREAM,0);

	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr=inet_addr("192.168.46.32");
	addrSrv.sin_family=AF_INET;
	addrSrv.sin_port=htons(9876);
	nRet = connect(m_st,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));
	if (nRet<0)
	{
		return -1;
	}
	return 0;
}

int CCommunicationOpt::Start()
{
	m_hdRecv = ::CreateThread(NULL,0,ThreadRecv,this,0,NULL);
	if (m_hdRecv == NULL)
	{
		return -1;
	}
	return CreateSocket();
}

void CCommunicationOpt::CloseSocket()
{
	if (NULL != m_hdRecv)
		CloseHandle(m_hdRecv);
	closesocket(m_st);
	WSACleanup( );
}

int CCommunicationOpt::Send(std::string str)
{
	return send(m_st,str.c_str(),str.length()+1,0);
}

int CCommunicationOpt::Send(const char* szBuf,int nSize)
{
	return send(m_st,szBuf,nSize,0);
}

DWORD CCommunicationOpt::RecvMsg()
{
	while (true)
	{
		char* p = NULL;
		recv(m_st,p,sizeof(MsgInfo),0);
		MsgInfo msg;
		memcpy(&msg,p,sizeof(MsgInfo));

		EnterCriticalSection(&m_cs);
		m_ListInfo.push_back(msg);
		LeaveCriticalSection(&m_cs);
	}
}