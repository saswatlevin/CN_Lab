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
  int sd,nrow,ncol;
  struct sockaddr_in address;
  sd = socket(AF_INET,SOCK_DGRAM,0);
  address.sin_family=AF_INET;
  address.sin_addr.s_addr=inet_addr("172.16.59.14");
  address.sin_port = htons(6969);
  int len = sizeof(address);
  printf("Enter the number of rows: ");
  scanf("%d",&nrow);
  int m = sendto(sd,&nrow,sizeof(int),0,(struct sockaddr*)&address,len);
  printf("Enter the number of columns: ");
  scanf("%d",&ncol);
  m = sendto(sd,&ncol,sizeof(int),0,(struct sockaddr*)&address,len);
  //int len = sizeof(address);
  //int m = sendto(sd,buf,sizeof(buf),0,(struct sockaddr*)&address,len);
  int message[ncol];
   printf("Enter the matrix: ");
  for (int i = 0;i<nrow;i++)
  {
   // m = recvfrom(sd,&message,ncol*sizeof(int),0,(struct sockaddr*)&cadd,&len);
    for (int j = 0;j<ncol;j++)
    {
     scanf("%d",&message[j]);
    }
    m = sendto(sd,&message,ncol*sizeof(int),0,(struct sockaddr*)&address,len);
  } 
  int matrix[nrow][ncol];
  int n = recvfrom(sd,&matrix,nrow*ncol*sizeof(int),0,(struct sockaddr*)&address,&len);
  printf("\n The echo from the server is \n");
  for (int i = 0;i<nrow;i++)
  {
   for (int j = 0;j<ncol;j++)
   {
    printf("%d ",matrix[i][j]);//standard printing shit
   }
    printf("\n");
  }
  return 0;
}

