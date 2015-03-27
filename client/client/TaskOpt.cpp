#include "StdAfx.h"
#include "TaskOpt.h"
#include <Psapi.h>   
#pragma comment(lib,"Psapi.lib")

CTaskOpt::CTaskOpt(void)
{
}


CTaskOpt::~CTaskOpt(void)
{
}

int CTaskOpt::GetTask(vtStr& str)const
{
	int nCount = 0;
	DWORD PID[1024];
	DWORD needed;
	EnumProcesses(PID,sizeof(PID),&needed);
	nCount = needed/sizeof(DWORD);
	wchar_t FilePatch[MAX_PATH] = {0};

	for (int i=0;i<nCount;i++)
	{
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS | PROCESS_VM_READ,FALSE,PID[i]);
		if (hProcess)
		{
			GetModuleFileNameEx(hProcess,NULL,FilePatch,sizeof(FilePatch));
			str.push_back(wchat_tTochar(FilePatch));
		}
		CloseHandle(hProcess);
	}
	return str.size();

}

int CTaskOpt::GetTask(mapStr& str)const
{
	int nCount = 0;
	DWORD PID[1024];
	DWORD needed;
	EnumProcesses(PID,sizeof(PID),&needed);
	nCount = needed/sizeof(DWORD);
	wchar_t FilePatch[MAX_PATH] = {0};

	for (int i=0;i<nCount;i++)
	{
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS | PROCESS_VM_READ,FALSE,PID[i]);
		if (hProcess)
		{
			GetModuleFileNameEx(hProcess,NULL,FilePatch,sizeof(FilePatch));
			str.insert(std::map<int,std::string>::value_type((int)PID[i], wchat_tTochar(FilePatch)));
		}
		CloseHandle(hProcess);
	}
	return str.size();
}

int CTaskOpt::KillTask(const std::string& str)
{
	DWORD PID[1024];
	DWORD needed;
	if (EnumProcesses(PID,sizeof(PID),&needed) != TRUE)
	{
		return -1;
	}
	
	int nCount = needed/sizeof(DWORD);
	wchar_t FilePatch[MAX_PATH] = {0};

	for (int i=0;i<nCount;i++)
	{
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS | PROCESS_VM_READ,FALSE | PROCESS_TERMINATE,PID[i]);
		if (hProcess)
		{
			GetModuleFileNameEx(hProcess,NULL,FilePatch,sizeof(FilePatch));
			if ( _tcscmp( FilePatch, charTowchat_t(str.c_str())) == 0)
			{
				BOOL bRet = TerminateProcess( hProcess, 4 );
				if ( !bRet )
				{
					return -1;
				}
			}
		}
		CloseHandle(hProcess);
	}
	return 0;

}