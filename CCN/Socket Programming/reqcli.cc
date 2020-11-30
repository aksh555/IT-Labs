//file transfer client program:fileclient.cc

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<stdlib.h>
#define SERV_PORT 5576
int main(int argc,char **argv)
{
int i,j;
ssize_t n;
char comm[80],recvline[256];
struct sockaddr_in servaddr;
int sockfd;
sockfd=socket(AF_INET,SOCK_STREAM,0);
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(SERV_PORT);
inet_pton(AF_INET,argv[1],&servaddr.sin_addr);
connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
printf("enter the command: ");
scanf("%s",comm);
write(sockfd,comm,sizeof(comm));
printf("\ndata from server: \n");
while(read(sockfd,recvline,256)!=0)
{
fputs(recvline,stdout);
}
close(sockfd);

}