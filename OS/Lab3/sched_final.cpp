#include<iostream> 
using namespace std;
int mat[10][6];

void findWT(int processes[], int n, int bt[], int wt[], int at[]) { 
	int service_time[n]; 
	service_time[0] = 0; 
	wt[0] = 0; 
	for (int i = 1; i < n ; i++) 
	{ 
		service_time[i] = service_time[i-1] + bt[i-1]; 
		wt[i] = service_time[i] - at[i]; 
		if (wt[i] < 0) 
			wt[i] = 0; 
	} 
} 
void findTAT(int processes[], int n, int bt[], int wt[], int tat[]) { 
	for (int i = 0; i < n ; i++) 
		tat[i] = bt[i] + wt[i]; 
} 
float fcfs(int processes[], int n, int bt[], int at[]) { 
	int wt[n], tat[n]; 
	findWT(processes, n, bt, wt, at); 
	findTAT(processes, n, bt, wt, tat); 
	cout<<"FCFS"<<endl;
	cout << "Processes " << " Burst Time " << " Arrival Time " << " Waiting Time " << " Turn-Around Time " << " Completion Time \n"; 
	int total_wt = 0, total_tat = 0; 
	for (int i = 0 ; i < n ; i++) 
	{ 
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i]; 
		int compl_time = tat[i] + at[i]; 
		cout << " " << i+1 << "\t\t" << bt[i] << "\t\t" << at[i] << "\t\t" << wt[i] << "\t\t " << tat[i] << "\t\t " << compl_time << endl; 
	} 
	cout << "Average waiting time = " << (float)total_wt / (float)n << endl; 
		cout<<"------------------------------------------------------------------------------------------------------";

	return (float)total_wt / (float)n;
}
void swap(int *a, int *b) 
{ 
	int temp = *a; 
	*a = *b; 
	*b = temp; 
} 
void arrangeArrival(int num, int mat[][6]) 
{ 
	for(int i=0; i<num; i++) 
	{ 
		for(int j=0; j<num-i-1; j++) 
		{ 
			if(mat[j][1] > mat[j+1][1]) 
			{ 
				for(int k=0; k<5; k++) 
				{ 
					swap(mat[j][k], mat[j+1][k]); 
				} 
			} 
		} 
	} 
} 
void completionTime(int num, int mat[][6]) 
{ 
	int temp, val; 
	mat[0][3] = mat[0][1] + mat[0][2]; 
	mat[0][5] = mat[0][3] - mat[0][1]; 
	mat[0][4] = mat[0][5] - mat[0][2]; 
	
	for(int i=1; i<num; i++) 
	{ 
		temp = mat[i-1][3]; 
		int low = mat[i][2]; 
		for(int j=i; j<num; j++) 
		{ 
			if(temp >= mat[j][1] && low >= mat[j][2]) 
			{ 
				low = mat[j][2]; 
				val = j; 
			} 
		} 
		mat[val][3] = temp + mat[val][2]; 
		mat[val][5] = mat[val][3] - mat[val][1]; 
		mat[val][4] = mat[val][5] - mat[val][2]; 
		for(int k=0; k<6; k++) 
		{ 
			swap(mat[val][k], mat[i][k]); 
		} 
	} 
} 
void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum) 
{ 
	int rem_bt[n]; 
	for (int i = 0 ; i < n ; i++) 
		rem_bt[i] = bt[i]; 
	int t = 0; 
	while (1) 
	{ 
		bool done = true; 
		for (int i = 0 ; i < n; i++) 
		{ 
			if (rem_bt[i] > 0) 
			{ 
				done = false; 
				if (rem_bt[i] > quantum) 
				{ 
					t += quantum; 
					rem_bt[i] -= quantum; 
				} 
				else
				{ 
					t = t + rem_bt[i]; 
					wt[i] = t - bt[i]; 
					rem_bt[i] = 0; 
				} 
			} 
		} 
		if (done == true) 
		break; 
	} 
} 
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) 
{ 
	for (int i = 0; i < n ; i++) 
		tat[i] = bt[i] + wt[i]; 
} 
float rr(int processes[], int n, int bt[], int quantum) 
{ 
	int wt[n], tat[n], total_wt = 0, total_tat = 0; 
	findWaitingTime(processes, n, bt, wt, quantum); 
	findTurnAroundTime(processes, n, bt, wt, tat); 
	cout<<"RR"<<endl;
	cout << "Processes "<< " Burst time "<< " Waiting time " << " Turn around time\n";
	for (int i=0; i<n; i++) 
	{ 
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i]; 
		cout << " " << i+1 << "\t\t" << bt[i] <<"\t " << wt[i] <<"\t\t " << tat[i] <<endl; 
	} 
	cout << "Average waiting time = "<< (float)total_wt / (float)n << endl; 
		cout<<"------------------------------------------------------------------------------------------------------";

	return (float)total_wt / (float)n;
} 
float sjfn(int num, int mat[][6]){
	int sum=0;
	arrangeArrival(num, mat); 
	completionTime(num, mat); 
	cout<<"SJFN"<<endl;
	cout<<"Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n"; 
	for(int i=0; i<num; i++) 
	{ 
		cout<<mat[i][0]<<"\t\t"<<mat[i][1]<<"\t\t"<<mat[i][2]<<"\t\t"<<mat[i][4]<<"\t\t"<<mat[i][5]<<"\n";
		sum+=mat[i][4];
	}
	cout << "Average waiting time = " << (float)sum / (float)num << endl;
		cout<<"------------------------------------------------------------------------------------------------------";

	return (float)sum / (float)num;
}
void findWaitTime(int pid[], int arr[], int bur[], int n, int wt[]) { 
	int rt[n]; 
	for (int i = 0; i < n; i++) 
		rt[i] = bur[i]; 
	int complete = 0, t = 0, minm = 10000; 
	int shortest = 0, finish_time; 
	bool check = false;  
	while (complete != n) { 
		for (int j = 0; j < n; j++) { 
			if ((arr[j] <= t) && 
			(rt[j] < minm) && rt[j] > 0) { 
				minm = rt[j]; 
				shortest = j; 
				check = true; 
			} 
		} 
		if (check == false) { 
			t++; 
			continue; 
		} 
		rt[shortest]--;  
		minm = rt[shortest]; 
		if (minm == 0) 
			minm = 10000; 
		if (rt[shortest] == 0) { 
			complete++; 
			check = false; 
			finish_time = t + 1;  
			wt[shortest] = finish_time - bur[shortest] - arr[shortest]; 

			if (wt[shortest] < 0) 
				wt[shortest] = 0; 
		} 
		t++; 
	} 
} 
void findturnaroundtime(int bur[], int n, int wt[], int tat[]) { 
	for (int i = 0; i < n; i++) 
		tat[i] = bur[i] + wt[i]; 
} 
float sjfp(int pid[], int arr[], int bur[], int n) { 
	int wt[n], tat[n], total_wt = 0, total_tat = 0;
	findWaitTime(pid, arr, bur, n, wt); 
	findturnaroundtime(bur, n, wt, tat); 
	cout<<"SJFP"<<endl;
	cout << "Processes "<< " Burst time "<< " Waiting time "<< " Turn around time\n"; 
	for (int i = 0; i < n; i++) { 
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i]; 
		cout << " " << pid[i] << "\t\t"<< bur[i] << "\t\t " << wt[i]<< "\t\t " << tat[i] << endl; 
	} 
	cout << "Average waiting time = "	<< (float)total_wt / (float)n<<endl; 
	cout<<"------------------------------------------------------------------------------------------------------";
	return (float)total_wt / (float)n;
}
int main() 
{ 
	int num, temp, quantum; 
	int a, b, c, d;
	
	cout<<"Enter number of Process: "; 
	cin>>num; 
	
	cout<<"Enter the process ID:\n"; 
	for(int i=0; i<num; i++) 
	{ 
		cout<<"Enter Process Id: "; 
		cin>>mat[i][0]; 
		cout<<"Enter Arrival Time: "; 
		cin>>mat[i][1]; 
		cout<<"Enter Burst Time: "; 
		cin>>mat[i][2]; 
	}
	cout<<"Enter Time  Quantum for Round Robin: ";
	cin>>quantum;
	int arr[num], bur[num], pid[num];
	cout<<"Process ID\tArrival Time\tBurst Time\n"; 
	for(int i=0; i<num; i++) 
	{ 
		cout<<mat[i][0]<<"\t\t"<<mat[i][1]<<"\t\t"<<mat[i][2]<<"\n"; 
		pid[i]=mat[i][0];
		arr[i]=	mat[i][1];
		bur[i]=	mat[i][2];
	} 
	a = fcfs(pid, num, bur, arr);
	cout<<"\n";
	b = sjfn(num, mat);
	cout<<"\n";
	c = sjfp(pid, arr, bur, num);
	cout<<"\n";
	d = rr(pid, num, bur, quantum);
	cout<<"\n";
	float min = 10000;
	if(a<min)
		min = a;
	if(b<min)
		min = b;
	if(c<min)
		min = c;
	if(d<min)
		min = d;
	if(min == a)
		cout<<"FCFS performs best"<<endl;
	else if(min == b)
		cout<<"SJFNP  performs best"<<endl;
	else if(min == c)
		cout<<"SJFP performs best"<<endl;
	else
		cout<<"RR  performs best"<<endl;
} 
