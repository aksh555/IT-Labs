#include<stdio.h>
#include<stdlib.h>
 
int mutex=1,full=0,empty=5,x=0;

int wait(int s)
{
	return --s;
}
 
int signal(int s)
{
	return ++s;
}
 
void producer()
{
	mutex=wait(mutex);
	full=signal(full);
	empty=wait(empty);
	x++;
	printf("\nProducer produced the item %d",x);
	mutex=signal(mutex);
}
 
void consumer()
{
	mutex=wait(mutex);
	full=wait(full);
	empty=signal(empty);
	printf("\nConsumer consumed item %d",x);
	x--;
	mutex=signal(mutex);
} 
int main()
{
	int n;
	printf("Menu:\n");
	printf("1. To Produce \n2. To Consume\n3. To Exit");
	while(1)
	{
		printf("\nEnter your choice:");
		scanf("%d",&n);
		switch(n)
		{
			case 1:	if((mutex==1)&&(empty!=0))
						producer();
					else
						printf("The Buffer is full!!");
					break;
			case 2:	if((mutex==1)&&(full!=0))
						consumer();
					else
						printf("The Buffer is empty!!");
					break;
			case 3:
					printf("Exiting...\n");
					exit(0);
					break;
		}
	}
}
