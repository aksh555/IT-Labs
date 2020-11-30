//server for file transfer:fileserver.cc
#include<bits/stdc++.h>
#define SERV_PORT 5576
int main(int argc,char **argv)
{
int i,j;
ssize_t n;
FILE *fp;
char s[80],f[80];
struct sockaddr_in servaddr,cliaddr;
int listenfd,connfd;
socklen_t clilen;
listenfd=socket(AF_INET,SOCK_STREAM,0); //0 for proto typt
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(SERV_PORT);
bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
listen(listenfd,1); //1 indicates no. of active clients in que
clilen=sizeof(cliaddr);
connfd=accept(listenfd,(struct sockaddr*)&cliaddr,&clilen);
printf("\n clinet connected");
read(connfd,f,80);
fp=fopen(f,"r");
printf("\n name of the file: %s",f);
while(fgets(s,80,fp)!=NULL)
{
printf("%s",s);
write(connfd,s,sizeof(s));
}
close(listenfd);
fclose(fp); }
