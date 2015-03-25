#ifndef _WDD_MSGINFO_H_
#define _WDD_MSGINFO_H_

//定义发送消息格式
enum enControlType
{
	en_MSG_DiskFile,	//获取指定盘符的文件列表
	en_MSG_PathFile,	//获取指定路径的文件列表
	en_MSG_File,		//获取制定文件
	en_MSG_OpenCmaera,	//打开摄像头
	en_MSG_CloseCmaera,	//关闭摄像头
	en_MSG_OpenProgram,	//打开指定程序
	en_MSG_ClosePorgram,//关闭指定程序
	en_MSG_TaskManager,	//获取任务管理器列表
	en_MSG_Win,			//windows键
	en_MSG_ESC,			
	en_MSG_Q,
	en_MSG_W,
	en_MSG_E,
	en_MSG_R,
	en_MSG_T,
	en_MSG_Y,
	en_MSG_U,
	en_MSG_I,
	en_MSG_O,
	en_MSG_P,
	en_MSG_A,
	en_MSG_S,
	en_MSG_D,
	en_MSG_F,
	en_MSG_G,
	en_MSG_H,
	en_MSG_J,
	en_MSG_K,
	en_MSG_L,
	en_MSG_Z,
	en_MSG_X,
	en_MSG_C,
	en_MSG_V,
	en_MSG_B,
	en_MSG_N,
	en_MSG_M,
	en_MSG_SPACE,
	en_MSG_BACKSPACE,
	en_MSG_ENTER,
	en_MSG_SHIFT,
	en_MSG_1,
	en_MSG_2,
	en_MSG_3,
	en_MSG_4,
	en_MSG_5,
	en_MSG_6,
	en_MSG_7,
	en_MSG_8,
	en_MSG_9,
	en_MSG_0,
	en_MSG_F1,
	en_MSG_F2,
	en_MSG_F3,
	en_MSG_F4,
	en_MSG_F5,
	en_MSG_F6,
	en_MSG_F7,
	en_MSG_F8,
	en_MSG_F9,
	en_MSG_F10,
	en_MSG_F11,
	en_MSG_F12,
	en_MSG_UP,				//方向键
	en_MSG_DOWN,
	en_MSG_LEFT,
	en_MSG_RIGHT,
	en_MSG_MOUSE_LEFT,		//鼠标按键
	en_MSG_MOUSE_RIGHT,
	en_MSG_MOUSE_MINDLE,
	en_MSG_Inval
};
struct MsgInfo 
{
	enControlType enType;	//操作类型
	int nSendSocket;		//发送端socket id
	int nRecvSocket;		//接收端socket id
	char strSendName[64];	//发送端名称
	char strRecvName[64];	//接收端名称
	char strMsg[512];		//发送消息
	char strContext[128];	//附加消息
	bool bFinish;			//消息全部是否发送
	MsgInfo()
	{
		enType = en_MSG_Inval;	//操作类型
		nSendSocket = -1;		//发送端socket id
		nRecvSocket = -1;		//接收端socket id
		strSendName[64] = {0};	//发送端名称
		strRecvName[64] = {0};	//接收端名称
		strMsg[512] = {0};		//发送消息
		strContext[128] = {0};	//附加消息
		bFinish = true;			//消息全部是否发送
	}
};

#endif