#pragma once
#include "opencv/cv.h"
#include "TypeDef.h"
//�������������ͷ������
class CCameraOpt
{
public:
	CCameraOpt(void);
	~CCameraOpt(void);
	
	IplImage* GetImage(); 

	int CreateThread();
	DWORD run();
	void DestoryThread();

private:
	IplImage* m_pFrame;  
	bool m_bStop;
	HANDLE m_hd;
	HANDLE m_hDemaphore;
	bool m_bCanRead;
	CRITICAL_SECTION m_cs;

};

