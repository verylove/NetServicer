// client.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "CameraOpt.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
int _tmain(int argc, _TCHAR* argv[])
{
	CCameraOpt* opt = new CCameraOpt;
	int nRet = opt->CreateThread();
		cvNamedWindow("video", 1);
	if (nRet == 0)
	{
		while (1)
		{
			IplImage* pImage = opt->GetImage();
			if (pImage)
			{
				std::cout<<"������ʾͼƬ"<<std::endl;
				cvShowImage("video",pImage);
				cvSaveImage("D:\\1.jpg",pImage);
				std::cout<<"��ʾͼƬ���"<<std::endl;
				cvReleaseImage(&pImage);
			}
		}

	}

	system("PAUSE"); 
	return 0;
}

