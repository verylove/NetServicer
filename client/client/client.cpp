// client.cpp : 定义控制台应用程序的入口点。
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

