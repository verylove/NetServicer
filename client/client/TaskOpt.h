#pragma once

#include "TypeDef.h"
//进程控制类
class CTaskOpt
{
public:
	CTaskOpt(void);
	~CTaskOpt(void);

	int GetTask(vtStr& str)const;

	int KillTask(const std::string& str); 

	int GetTask(mapStr& str)const;

	HANDLE OpenProcessByID(const DWORD& id)
	{
		return OpenProcess(PROCESS_ALL_ACCESS,FALSE,id);
	}


};

