#pragma once
#include "opencv/cv.h"
#include "TypeDef.h"
//相机操作（摄像头操作）
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

