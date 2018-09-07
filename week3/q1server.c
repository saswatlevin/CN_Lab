#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>

#define PORTNO 10200

void main()
{
	int sockfd, newsockfd, portno, clilen, n=1;
	int buf[256]={0};
	struct sockaddr_in seraddr, cliaddr;
	int i, value;
	int temp;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	
	seraddr.sin_family=AF_INET;
	seraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	seraddr.sin_port=htons(10200);
	bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
	
	listen(sockfd,5);
	while(1)
	{
		clilen=sizeof(clilen);
		newsockfd=accept(sockfd,(struct sockaddr *)&cliaddr,&clilen);
		if (fork()==0)
		{	
			n=read(newsockfd,buf,sizeof(buf));
			printf("\nArray from Client: \n");
			for(int i=1;i<=buf[0];i++)
			{
				printf("%d ",buf[i]);
			}
			printf("\n");
			for(int i=1;i<buf[0];i++)
			{
				for(int j=i;j<=buf[0];j++)
				{
					if(buf[i]>buf[j])
					{
						temp=buf[i];
						buf[i]=buf[j];
						buf[j]=temp;
					}
				}
			}
			printf("\nSorted Array: \n");
			for(int i=1;i<=buf[0];i++)
			{
				printf("%d ",buf[i]);
			}
			printf("\n");
			printf("\nProcess ID : %d\n\n\n", getpid());
			n=write(newsockfd,buf,sizeof(buf));
			close(newsockfd);
			exit(0);
		}
	}
}



