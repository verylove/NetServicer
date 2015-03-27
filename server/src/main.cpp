#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <map>
#include <pthread.h>
#include "../include/MsgInfo.h"

#define MAXLINE 4096
typedef std::map<int,int> mapUser; //连接的用户 int： connectId， threadID
vtUser userList;

void Send(int nSocket,void* Data)
{

}

void CreateConnectThread(void* nConnect)
{
	char    buff[4096];
	while (true)
	{
		int nRecv = recv((int)(*nConnect), buff, MAXLINE, 0);
		if (n>0)
		{
			Send();
		}
	}

	
}
int main(int argc, char** argv)
{
    if ((1 == argc) || ((argc > 1) && (0 != strcmp("debug", argv[argc-1])))) 
    {
        daemon(1, 1);
    }
    int    listenfd, connfd;
    struct sockaddr_in     servaddr;
    char    buff[4096];
    int     n;

    if( (listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1 ){
		printf("create socket error: %s(errno: %d)\n",strerror(errno),errno);
		exit(0);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(9876);

    if( bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
		printf("bind socket error: %s(errno: %d)\n",strerror(errno),errno);
		exit(0);
    }

    if( listen(listenfd, MAXLINE) == -1){
		printf("listen socket error: %s(errno: %d)\n",strerror(errno),errno);
		exit(0);
    }

    printf("======waiting for client's request======\n");
    while(1)
	{
		printf("inti accept!");
		if( (connfd = accept(listenfd, (struct sockaddr*)NULL, NULL)) == -1)
		{
			printf("accept socket error: %s(errno: %d)",strerror(errno),errno);
			continue;
		}
		vtUser.push_back(connfd); //add user to list
		pthread_t nAccept;
		if((pthread_create(&nAccept,NULL,(void*)(&CreateConnectThread),&connfd))!=0){  
			printf("create thread error!\n");  
			exit(1);  
		}  
		userList.insert(std::map<int,int>::value_type(connfd, nAccept));
    }
    close(listenfd);
}

