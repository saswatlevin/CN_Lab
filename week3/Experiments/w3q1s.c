#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
int main()
{

int sockfd,newsockfd=0,clilen;
struct sockaddr_in a;
struct sockaddr_in cliaddr;

//Create a socket for the client
sockfd=socket(AF_INET,SOCK_STREAM,0);

//Name the socket as agreed with the server
a.sin_family=AF_INET;
a.sin_addr.s_addr=inet_addr("172.16.58.89 ");
a.sin_port=htons(10200);
int len=sizeof(a);
bind(sockfd,(struct sockaddr*)&a,sizeof(a));
listen(sockfd,5);

while(1){
        printf("\nBefore accept:\n");
        clilen=sizeof(cliaddr);
        newsockfd=accept(sockfd,(struct sockaddr*)&cliaddr,&clilen);
        printf("\nBefore Forking");
        if(fork()==0){
          int ans,x,size;
          x=read(newsockfd,&size,sizeof(size));
          printf(
        

