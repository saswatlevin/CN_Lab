#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

void main()
{

int sd,i=0,j=0,buf[2],mat[2][2],m=0,n=0;
char X;
struct sockaddr_in address;
//Create a socket
sd=socket(AF_INET,SOCK_DGRAM,0);
address.sin_family=AF_INET;
address.sin_addr.s_addr=inet_addr("172.16.58.100");
address.sin_port=htons(9704);

int len=sizeof(address);

//giving rows of matrix to buffer

while(1)
printf("\nPress X when Client ready");
scanf("%c",&X);
if(X=='X')
{

for(i=0;i<2;++i)
{

buf[i]=mat[i][0];
m=sendto(sd,buf[i],sizeof(buf[i]),0,(struct sockaddr *)&address,len);

}

}
}

//n=recvfrom(sd,buf,sizeof(buf),0,(struct sockaddr *)&address,&len);
//printf("\nThe server echo is\n");
printf("\nbuf=");
for(i=0;i<2;++i)
{
printf("%d",buf[i]);
}

}
