#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   int len,result,sockfd,n=1;
   struct sockaddr_in address;
   char buf[256],ch[256];
   
   //Create a socket for the client
   sockfd=socket(AF_INET,SOCK_STREAM,0);
   //Name the socket as agreed with the server
   address.sin_family=AF_INET;
   address.sin_addr.s_addr=inet_addr("172.16.58.115");
   address.sin_port=htons(10200);
   len=sizeof(address);
   //Connect your socket to the server's socket
   result=connect(sockfd, (struct sockaddr*)&address, len);
   if (result==1)
   {
      
      perror("\nClient Error");
      exit(1);
   
   }
   
   printf("\nEnter String");
   gets(ch);
   ch[strlen(ch)]='\0';
   write(sockfd,ch,strlen(ch));
   printf("String sent back from server is:");
   
   while(n)
   {
   n=read(sockfd,buf,sizeof(buf));
   puts(buf);
   }

   
  return 0;
}

