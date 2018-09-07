#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <netinet/in.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#define PORTNO 10200

int main()
{
int sockfd,newsockfd,portno,clilen,n=1;
struct sockaddr_in seraddr,cliaddr;
int i,value;

//create an unnamed socket for the sever

sockfd=socket(AF_INET,SOCK_STREAM,0);

//Name the socket

seraddr.sin_family=AF_INET;
seraddr.sin_addr.s_addr=inet_addr("172.16.58.115");
seraddr.sin_port=htons(PORTNO);
bind(sockfd, (struct sockaddr*)&seraddr, sizeof(seraddr));

//Create a connection and listen
listen(sockfd,5);

while(1){
char buf[256];
printf("\nServer waiting\n");

//Accept a connection

clilen=sizeof(clilen);
newsockfd=accept(sockfd,(struct sockaddr*)&cliaddr, &clilen);

while(n)
{
char buf[256],ch[256];
n=read(newsockfd,buf,sizeof(buf));
printf("\nMessage from client is:%s\n",buf);
printf("\nThe client ip is :%d\n",seraddr.sin_addr.s_addr);
printf("\nThe ephemeral port number is=%d\n",seraddr.sin_port);
int i;
for(i=0;i<strlen(buf);++i)
ch[i]=toupper(buf[i]);

ch[strlen(ch)]='\0';
n=write(newsockfd,ch,sizeof(ch));
}
}





return 0;
}







