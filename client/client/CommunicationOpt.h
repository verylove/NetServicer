#pragma once
#include <Winsock2.h>
#include <string.h>
#include <iostream>
//��װ��ͨ�ŵ�һЩ����

class CCommunicationOpt
{
public:
	CCommunicationOpt(void);
	~CCommunicationOpt(void);

	int CreateSocket();	//��ʼ������

	int Start();		//�����߳�

	void CloseSocket();

	int Send(std::string str);
	int Send(const char* szBuf,int nSize);

	DWORD RecvMsg();
private:
	SOCKET m_st;		
	HANDLE m_hdRecv;	//�����߳̾��
	static const int nMax_Recv = 1024;

};

