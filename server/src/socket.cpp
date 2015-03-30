#include "../include/socket.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

wddSocket::wddSocket()
{

}
wddSocket::~wddSocket()
{
	CloseSocket();
}
//create socket
SocketType wddSocket::CreateSocket()
{
	if( (m_nSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1 ){
		return en_Err_CreatSocketErr;
	}
	return en_OK;
}

//bind
SocketType wddSocket::Bind(int nPort)
{
	struct sockaddr_in     servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(nPort);

	if (IsValid()!=en_OK)
	{
		return en_Err_Socket;
	}

	if( bind(m_nSocket, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
		return en_Err_BindErr;
	}
	return en_OK;
}

//Listen
SocketType wddSocket::Listen()
{
	if (IsValid()!=en_OK)
	{
		return en_Err_Socket;
	}
	if( listen(m_nSocket, MAXBUFF) == -1){
		return en_Err_ListenErr;
	}
	return en_OK;
}

//Accept
SocketType wddSocket::Accept(int& nSocket)
{
	if (IsValid()!=en_OK)
	{
		return en_Err_Socket;
	}
	if( (nSocket = accept(m_nSocket, (struct sockaddr*)NULL, NULL)) == -1)
	{
		return en_Err_AcceptErr;
	}
	return en_OK;
}

//CloseSocket
SocketType wddSocket::CloseSocket()
{
	if(IsValid())
		close(m_nSocket);
}

//ivalid
SocketType wddSocket::IsValid()
{
	if (-1 == m_nSocket)
	{
		return en_Err_Socket
	}
	return en_OK;
}

//close server
SocketType wddSocket::StopServer()
{

}

//open server
SocketType wddSocket::OpenServer()
{

}

//recv message
SocketType wddSocket::RecvMsg(void* pData)
{
	if (IsValid()!=en_OK)
	{
		return en_Err_Socket;
	}
	pData = new char[MAXBUFF];
	int numberRead=::recv(m_nSocket,pData,MAXBUFF,0);
	if(numberRead==-1)
	{
		return en_Err_RecvErr;
	}
	else if(numberRead==0)
	{
		return en_Err_RecvEmptyErr;
	}
	else
	{
		return en_OK;
	}
	return en_OK;
}

//send message
SocketType wddSocket::SendMsg(void* pData,int nSize)
{
	if (IsValid()!=en_OK)
	{
		return en_Err_Socket;
	}
	int result = send(m_nSocket,pData,nSize,MSG_NOSIGNAL);
	if(-1 == result)
	{
		return en_Err_SendErr;
	}
	return en_OK;
}