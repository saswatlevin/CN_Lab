#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<unistd.h>
#define PORTNO 9000

int main()
{        
	int len,result,sockfd, n=1;
	struct sockaddr_in address;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORTNO);
	len = sizeof(address);
	result = connect(sockfd,(struct sockaddr*)&address,len);
	if(result == -1)
	{
	        perror("CLIENT ERROR");
                return 0;
	}
	int n1,n2,x,ans=0;
	char op;

	printf("Enter operand: ");
	scanf("%c",&op);
	
	x=write(sockfd,&op,sizeof(op));
	printf("Enter first number: ");
	scanf("%d",&n1);
	printf("Enter second number: ");
	scanf("%d",&n2);
	x=write(sockfd,&n1,sizeof(n1));
	x=write(sockfd,&n2,sizeof(n2));
	
	x=read(sockfd,&ans,sizeof(ans));
	printf("Answer : %d\n",ans);
	close(sockfd);
	return 0;
	         
}
