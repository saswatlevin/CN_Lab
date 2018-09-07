#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define PORTNO 10200


int main()
{
int sockfd,newsockfd,portno,clilen,n=1;
char buf[256];
struct sockaddr_in seraddr,cliaddr;
sockfd=socket(AF_INET,SOCK_STREAM,0);
seraddr.sin_family=AF_INET;
seraddr.sin_addr.s_addr=inet_addr("172.16.58.89");
seraddr.sin_port=htons(PORTNO);
bind(sockfd,(struct sockaddr *)&seraddr,sizeof(seraddr));

//Create a connection queue, ignore child exit threats and wait for clients
listen(sockfd,5);

while(1){
  //Accept the connection
  clilen=sizeof(clilen);
  newsockfd=accept(sockfd,(struct sockaddr *)&cliaddr,&clilen);
  //Fork to create a process for this client and perform a test to see whether you're the parent or the child

if(fork()==0){
n=read(newsockfd,buf,sizeof(buf));
close(newsockfd);
exit(0);
}
//Otherwise,you must be the parent and your work for this client is finished

else
    close(newsockfd);

}
return 0;
}

