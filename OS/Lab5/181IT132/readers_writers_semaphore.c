// Execution: gcc readers_writers_semaphore.c -o output -pthread && clear && ./output

#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t mutex,wrt;
int data = 0,rcount = 0;

void *reader(void *arg)
{
  int f;
  f = ((int)arg);
  sem_wait(&mutex);
  rcount = rcount + 1;
  if(rcount==1)
   sem_wait(&wrt);
  sem_post(&mutex);
  printf("Data read by reader %d is %d\n",f,data);
  sleep(1);
  sem_wait(&mutex);
  rcount = rcount - 1;
  if(rcount==0)
   sem_post(&wrt);
  sem_post(&mutex);
}

void *writer(void *arg)
{
  int f;
  f = ((int) arg);
  sem_wait(&wrt);
  data++;  
  printf("Data writen by the writer %d is %d\n",f,data);
  sleep(1);
  sem_post(&wrt);
}

int main()
{
  int i,b; 
  printf("Initial value of data is %d\n",data);
  pthread_t rtid[5],wtid[5];
  sem_init(&mutex,0,1);
  sem_init(&wrt,0,1);
  for(i=0;i<=2;i++)
  {
    pthread_create(&wtid[i],NULL,writer,(void *)i);
    pthread_create(&rtid[i],NULL,reader,(void *)i);
  }
  for(i=0;i<=2;i++)
  {
    pthread_join(wtid[i],NULL);
    pthread_join(rtid[i],NULL);
  }
  return 0;
}