#ifndef _WDD_SOCKET_H_
#define _WDD_SOCKET_H_

#define  MAXBUFF 4096
class wddSocket
{
public:
	wddSocket();
	~wddSocket();

	enum SocketType
	{
		en_OK,
		en_Err_Socket,
		en_Err_CreatSocketErr,
		en_Err_BindErr,
		en_Err_ListenErr,
		en_Err_AcceptErr,
		en_Err_RecvErr,
		en_Err_RecvEmptyErr,
		en_Err_SendErr,
		en_Err_CloseSocketErr,
		en_Err_SocketInValid
	};

	//create socket
	SocketType CreateSocket();

	//bind
	SocketType Bind(int nPort);

	//Listen
	SocketType Listen();

	//Accept
	SocketType Accept(int& nSocket);

	//CloseSocket
	SocketType CloseSocket();

	//ivalid
	SocketType IsValid();

	//recv message
	SocketType RecvMsg(void* pData);

	//send message
	SocketType SendMsg(void* pData,int nSize);

	//close server
	SocketType StopServer();

	//open server
	SocketType OpenServer();
private:
	int m_nSocket; 

};
#endif