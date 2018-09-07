#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <netinet/in.h>
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
Take better screenshots.

Take, save and share screenshots — without leaving Firefox.
printf("\nServer waiting\n");

//Accept a connection

clilen=sizeof(clilen);
newsockfd=accept(sockfd,(struct sockaddr*)&cliaddr, &clilen);



//Send time to client
time_t t1;
struct tm *timeinfo;
time(&t1);
timeinfo=localtime(&t1);
char* asc_time=asctime(timeinfo);
printf("\nSending time to client\n");
n=write(newsockfd, asctime, strlen(asctime)+1);
}
return 0;
}





