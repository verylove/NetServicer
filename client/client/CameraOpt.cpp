#include "StdAfx.h"
#include "CameraOpt.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"


DWORD WINAPI ThreadCapture(LPVOID lpParameter)
{
	CCameraOpt* opt= (CCameraOpt*)lpParameter;
	return opt->run();
}

CCameraOpt::CCameraOpt(void)
	:m_bStop(false)
	,m_pFrame(NULL)
	,m_hd(NULL)
	,m_hDemaphore(NULL)
{
	 InitializeCriticalSection(&m_cs);
}

CCameraOpt::~CCameraOpt(void)
{
	DeleteCriticalSection(&m_cs);
}

IplImage* CCameraOpt::GetImage()
{

	EnterCriticalSection(&m_cs);
	IplImage* pImage = NULL;
	if (m_pFrame)
	{
		pImage = cvCloneImage(m_pFrame);
	}
	LeaveCriticalSection(&m_cs);

	return pImage;
}
DWORD CCameraOpt::run()
{
	DWORD dw = 0;
	//获取摄像头  
	CvCapture* pCapture = cvCreateCameraCapture(-1);  
	if (pCapture == NULL)
	{
		dw = -1;
	}

	//显示视屏  
	while(!m_bStop)  
	{  
		EnterCriticalSection(&m_cs);
		m_pFrame = cvQueryFrame( pCapture ); 
		LeaveCriticalSection(&m_cs);
	
		if(!m_pFrame)break;  
	}  
	cvReleaseCapture(&pCapture);  
	return dw;
}

int CCameraOpt::CreateThread()
{
	int nRet = 0;
	m_hd = ::CreateThread(NULL,0,ThreadCapture,this,0,NULL);
	if (m_hd == NULL)
	{
		nRet = -1;
	}
	return nRet;
}

void CCameraOpt::DestoryThread()
{
	if (m_hd != NULL)
	{
		CloseHandle(m_hd);
		m_hd = NULL;
	}
}
