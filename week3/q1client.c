#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
	int len,result,sockfd,n=1;
	struct sockaddr_in address;
	int buf[256]={0};
	int k;
	
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	
	address.sin_family=AF_INET;
	address.sin_addr.s_addr=inet_addr("127.0.0.1");
	address.sin_port=htons(10200);
	len=sizeof(address);

	result=connect(sockfd,(struct sockaddr*)&address,len);
	if (result==-1)
	{
		perror("\nCLIENT ERROR");
		exit(1);
	}
	
	printf("\nEnter size of array: \t");
	scanf("%d",&buf[0]);
	printf("\nEnter array elements:\n");
	for(int i=1;i<=buf[0];i++)
		scanf("%d",&buf[i]);
	write(sockfd,buf,sizeof(buf));
	printf("Sorted array from server:\n");
	
		n=read(sockfd,buf,sizeof(buf));
		for(int i=1;i<=buf[0];i++)
			{
				printf("%d ",buf[i]);
			}
		
		printf("\n");
		
}

