// client.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "CommunicationOpt.h"
int _tmain(int argc, _TCHAR* argv[])
{
	CCommunicationOpt* opt = new CCommunicationOpt();
	if (opt->Start() == 0)
	{
		while(1)
		{
			char  szbuf[256] = {0} ;
			std::cin>>szbuf;
			opt->Send(szbuf,256);
		}
	}


	
	//system("PAUSE"); 
	return 0;
}

