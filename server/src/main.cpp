#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<vector>

#define MAXLINE 4096
typedef std::vector<int> vtUser;
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
    while(1){
		printf("inti accept!");
		if( (connfd = accept(listenfd, (struct sockaddr*)NULL, NULL)) == -1)
		{
			printf("accept socket error: %s(errno: %d)",strerror(errno),errno);
			continue;
		}
		vtUser.push_back(connfd);
		printf("client -%d- connect!\nTotal:%d",connfd,vtUser.size());
		n = recv(connfd, buff, MAXLINE, 0);
		buff[n] = '\0';
		printf("recv msg from client: %s\n", buff);
		if (send(connfd,"<?xml version=\"1.0\"?><cross-domain-policy><site-control permitted-cross-domain-policies=\"all\"/><allow-access-from domain=\"*\" to-ports=\"*\"/></cross-domain-policy>",164,0) == -1)
		{
			printf("Send Failed!\n");
		}
    }
    close(listenfd);
}

