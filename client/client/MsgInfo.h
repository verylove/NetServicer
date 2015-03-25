#ifndef _WDD_MSGINFO_H_
#define _WDD_MSGINFO_H_

//���巢����Ϣ��ʽ
enum enControlType
{
	en_MSG_DiskFile,	//��ȡָ���̷����ļ��б�
	en_MSG_PathFile,	//��ȡָ��·�����ļ��б�
	en_MSG_File,		//��ȡ�ƶ��ļ�
	en_MSG_OpenCmaera,	//������ͷ
	en_MSG_CloseCmaera,	//�ر�����ͷ
	en_MSG_OpenProgram,	//��ָ������
	en_MSG_ClosePorgram,//�ر�ָ������
	en_MSG_TaskManager,	//��ȡ����������б�
	en_MSG_Win,			//windows��
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
	en_MSG_UP,				//�����
	en_MSG_DOWN,
	en_MSG_LEFT,
	en_MSG_RIGHT,
	en_MSG_MOUSE_LEFT,		//��갴��
	en_MSG_MOUSE_RIGHT,
	en_MSG_MOUSE_MINDLE,
	en_MSG_Inval
};
struct MsgInfo 
{
	enControlType enType;	//��������
	int nSendSocket;		//���Ͷ�socket id
	int nRecvSocket;		//���ն�socket id
	char strSendName[64];	//���Ͷ�����
	char strRecvName[64];	//���ն�����
	char strMsg[512];		//������Ϣ
	char strContext[128];	//������Ϣ
	bool bFinish;			//��Ϣȫ���Ƿ���
	MsgInfo()
	{
		enType = en_MSG_Inval;	//��������
		nSendSocket = -1;		//���Ͷ�socket id
		nRecvSocket = -1;		//���ն�socket id
		strSendName[64] = {0};	//���Ͷ�����
		strRecvName[64] = {0};	//���ն�����
		strMsg[512] = {0};		//������Ϣ
		strContext[128] = {0};	//������Ϣ
		bFinish = true;			//��Ϣȫ���Ƿ���
	}
};

#endif