//server for file transfer:fileserver.cc
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<stdlib.h>
#define SERV_PORT 5576
int main(int argc,char **argv)
{
int i,j;
ssize_t n;
char co[80];
struct sockaddr_in servaddr,cliaddr;
int listenfd,connfd;
socklen_t clilen;
listenfd=socket(AF_INET,SOCK_STREAM,0);
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(SERV_PORT);
bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
listen(listenfd,1);
clilen=sizeof(cliaddr);
connfd=accept(listenfd,(struct sockaddr*)&cliaddr,&clilen);
printf("\n clinet connected");
read(connfd,co,80);
printf("\n Command entered: %s",co);
system(co);
FILE *com = popen(co, "r");
char buf[256];
while (fgets(buf, sizeof(buf), com) != NULL) {
//printf("%s",buf);
write(connfd,buf,sizeof(buf));
}
pclose(com);

close(listenfd);
 }