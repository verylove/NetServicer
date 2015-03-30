#ifndef _WDD_SERVERMANAGE_H
#define _WDD_SERVERMANAGE_H

#include <list>
class wddSocket;

//服务器用户管理
class ServerManager
{
public:
	ServerManager();
	~ServerManager();
	typedef std::list<int> listUser;

	//start
	int Start();

	//close
	int Close();

	//restart
	int Restart();

private:
	int InitSocket();

	int RecvMsg();


private:
	wddSocket* m_wddSocket;
	listUser m_listUser;
	bool m_bServerRunning;
	pthread_t m_recvthread;
};
#endif