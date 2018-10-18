#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
int main()
{
 int sd;
 int nrow,ncol;
 sd = socket (AF_INET,SOCK_DGRAM,0);
 struct sockaddr_in sadd, cadd;
 sd = socket (AF_INET,SOCK_DGRAM,0);
 sadd.sin_family=AF_INET;
 sadd.sin_addr.s_addr=inet_addr("172.16.59.14");
 sadd.sin_port=htons(6969);
 int result = bind(sd,(struct sockaddr *)&sadd,sizeof(sadd));
 int len =  sizeof(cadd);
 int m = recvfrom(sd,&nrow,sizeof(int),0,(struct sockaddr*)&cadd,&len);//received the number of rows
 m = recvfrom(sd,&ncol,sizeof(int),0,(struct sockaddr*)&cadd,&len);//received the number of columns which is the length of each array
 int matrix[nrow][ncol];
 int message[ncol];//message is sent in form of array of ncol length
 for (int i = 0;i<nrow;i++)
 {
   m = recvfrom(sd,&message,ncol*sizeof(int),0,(struct sockaddr*)&cadd,&len);
   for (int j = 0;j<ncol;j++)
   {
    matrix[i][j]=message[j];//receiving in matrix from the client
   }
 }
 printf("The server was sent this :\n");
 for (int i = 0;i<nrow;i++)
 {
   //m = recvfrom(sd,&message,ncol*sizeof(int),0,(struct sockaddr*)&cadd,&len);
   for (int j = 0;j<ncol;j++)
   {
    printf("%d ",matrix[i][j]);//standard printing shit
   }
   printf("\n");
 }
 
 int n = sendto(sd,matrix,nrow*ncol*sizeof(int),0,(struct sockaddr*)&cadd,len);
 return 0;
}

