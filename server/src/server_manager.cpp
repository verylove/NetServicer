#include "../include/server_manager.h"
#include "../include/socket.h"
#include "../include/MsgInfo.h"


ServerManager::ServerManager()
	:m_wddSocket(NULL)
	,m_bServerRunning(false)
{

}
ServerManager::~ServerManager()
{

}
//start
int ServerManager::Start()
{

}

//close
int ServerManager::Close()
{

}

//restart
int ServerManager::Restart()
{

}


int ServerManager::InitSocket()
{
	m_wddSocket = new wddSocket();
	if (m_wddSocket->CreateSocket() != wddSocket::en_OK)
	{
		return -1;
	}

	if (m_wddSocket->Bind(9876) != wddSocket::en_OK)
	{
		return -1;
	}

	if (m_wddSocket->Listen() != wddSocket::en_OK )
	{
		return -1;
	}

	//create thread for recv 
	if((pthread_create(&m_recvthread,NULL,(void*)(&RecvMsg),NULL))!=0){  
		printf("create thread error!\n");  
		exit(1);  
	}  

	//Accept
	while (m_bServerRunning)
	{
		int nSocket = -1;
		if (m_wddSocket->Accept(nSocket) != wddSocket::en_Err_AcceptErr)
		{
			continue;
		}

		//线程同步，共享资源访问

		m_listUser.push_back(nSocket);

	}
	
	return 0;
}

int ServerManager::RecvMsg()
{
	while(m_bServerRunning)
	{
		void* pData = NULL;
		if (m_wddSocket->RecvMsg(pData) != wddSocket::en_OK)
		{
			continue;
		}
		//将消息转换成指定结构体
		MsgInfo* pInfo = new MsgInfo;
		memcpy(pInfo,pData,sizeof(MsgInfo));

		//处理消息,注意共享资源
		if (pInfo)
		{
			if (m_wddSocket->SendMsg())
			{
			}
		}
	}

}