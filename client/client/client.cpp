// client.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "CommunicationOpt.h"
int _tmain(int argc, _TCHAR* argv[])
{
	CCommunicationOpt* commOpt = new CCommunicationOpt;
	commOpt->CreateSocket();

	system("PAUSE"); 
	return 0;
}

