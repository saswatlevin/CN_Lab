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

int sd;
struct sockaddr_in address;
//Create a socket
sd=socket(AF_INET,SOCK_DGRAM,0);
address.sin_family=AF_INET;
address.sin_addr.s_addr=inet_addr("172.16.58.100");
address.sin_port=htons(9704);
printf("\nEnter buffer\n");
char buf[25],buf1[25];
fgets(buf,25,stdin);
int len=sizeof(address);
int m=sendto(sd,buf,sizeof(buf),0,(struct sockaddr *)&address,len);
int n=recvfrom(sd,buf,sizeof(buf),0,(struct sockaddr *)&address,&len);
printf("\nThe server echo is\n");
puts(buf);

}

