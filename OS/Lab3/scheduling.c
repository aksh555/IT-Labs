#include<stdio.h>

int bt[10]={0},at[10]={0},tat[10]={0},wt[10]={0},ct[10]={0},time_quantum,rt[10];
int n,sum=0;
float totalTAT=0,totalWT=0;

void fcfs()
{
    //calculate completion time of processes 	

	for(int j=0;j<n;j++)
	{
		sum+=bt[j];
		ct[j]+=sum;
	}

	//calculate turnaround time and waiting times 

	for(int k=0;k<n;k++)
	{
		tat[k]=ct[k]-at[k];
		totalTAT+=tat[k];
	}

	
	for(int k=0;k<n;k++)
	{
		wt[k]=tat[k]-bt[k];
		totalWT+=wt[k];
	}
	
}

void sjf()
{

}

void rr()
{
	int count,j,time,remain,flag=0;
	remain = n;
	int wait_time=0,turnaround_time=0;
	printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
	for(time=0,count=0;remain!=0;) 
  { 
    if(rt[count]<=time_quantum && rt[count]>0) 
    { 
      time+=rt[count]; 
      rt[count]=0; 
      flag=1; 
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(rt[count]==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]); 
      wait_time+=time-at[count]-bt[count]; 
      turnaround_time+=time-at[count]; 
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(at[count+1]<=time) 
      count++; 
    else 
      count=0; 
  } 
   printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n); 

}

void display()
{
   printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
	
	for(int i=0;i<n;i++)
	{
		printf("P[%d]\t|\t%d\t|\t%d\n",i+1,tat[i],wt[i]); 
		//printf("P%d\t %d\t %d\t %d\t %d\t %d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
	}
		
	printf("\n\nAverage Turnaround Time = %f\n",totalTAT/n);
	printf("Average WT = %f\n\n",totalWT/(float)n);
}

int main()
{

	printf("Enter number of processes ");
	scanf("%d",&n);
    printf("Enter arrival time and burst times\n");
    for(int i=0;i<n;i++)
	{

		printf("Arrival time of process[%d] ",i+1);
		scanf("%d",&at[i]);
		
		printf("Burst time of process[%d] ",i+1);
		scanf("%d",&bt[i]);
		rt[i]=bt[i];
		printf("\n");
	}

    printf("FCFS\n");	
	fcfs(); display();
    //printf("SJF\n");	
	//sjf(); display();
    printf("RR\n");	
    printf("Enter Time Quantum:"); 
  	scanf("%d",&time_quantum); 
	rr();
}
