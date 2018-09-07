#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORTNO 9000

int main()
{
	int sockfd,x;
	char buf[200];
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{
		perror("Error while creating");
		return 0;
	}
	struct sockaddr_in serveraddr;
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port = htons(PORTNO);
	serveraddr.sin_addr.s_addr=INADDR_ANY;
	int err=bind(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	if(err<0)
	{
		perror("Error while binding");
		return 0;
	}
	int lis = listen(sockfd,5);
	if(lis<0)
	{
		perror("Error while listening");
		return 0;
	}
	struct sockaddr_in cliaddr;
	int newsockfd;
	int clilen=0;
	int n1,n2;
	char op;
	int ans;
	while(1)
	{
		clilen=sizeof(cliaddr);
		newsockfd=accept(sockfd,(struct sockaddr*)&cliaddr,&(clilen));
		if(fork()==0)
		{
			x=read(newsockfd,&op,sizeof(op));
			x=read(newsockfd,&n1,sizeof(n1));
			x=read(newsockfd,&n2,sizeof(n2));
			printf("Got from client:\t");
			printf("%d %c %d \n",n1,op,n2);
			if(op=='+')
				ans=n1+n2;
			if(op=='-')
				ans=n1-n2;
			if(op=='*')
				ans=n1*n2;
			if(op=='/')
				ans=n1/n2;
			printf("At server side %d",ans);
			x=write(newsockfd,&ans,sizeof(ans));
		}
		else
			close(newsockfd);
	}
	close(sockfd);
	return 0;
}
