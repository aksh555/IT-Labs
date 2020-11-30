//Binary Heap
#include<iostream>
#include<climits>
using namespace std;

void swap(int *x, int *y);

class maxheap
{
	int *harr;
	int *arr;
	int capacity;
	int hs;
public:

	maxheap(int cap)
	{
		hs = 0;
		capacity = cap;
		harr = new int[cap];
	}
	void buildheap()
	{
		int x=0,i;char c='y';
		harr = new int[capacity];
		while(true)
		{
				cout<<"Enter element ";
				cin>>harr[x++];
				cout<<"want to continue? ";
				cin>>c;
				hs=x;
				if(c!='y') break;
		}
	    int st = (hs / 2) - 1;
	    for (i = st; i >= 0; i--) {
	         maxheapify(i);
	    }
	}
	void maxheapify(int i)
	{
		int l = left(i);
		int r = right(i);
		int largest = i;
		if (l < hs && harr[l] > harr[i])
			largest = l;
		if (r < hs && harr[r] > harr[largest])
			largest = r;
		if (largest != i)
		{
			swap(&harr[i], &harr[largest]);
			maxheapify(largest);
		}
	}

	int parent(int i) { return (i-1)/2; }

	int left(int i) { return (2*i + 1); }

	int right(int i) { return (2*i + 2); }

	void decreaseKey(int i, int val)
	{
		harr[i] = val;
		while (i != 0 && harr[parent(i)] < harr[i])
		{
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
		}
	}
	int extractmax()
	{
		if (hs <= 0)
			return INT_MIN;
		if (hs == 1)
		{
			hs--;
			return harr[0];
		}

		int root = harr[0];
		harr[0] = harr[hs-1];
		hs--;
		maxheapify(0);

		return root;
	}

	int getmax() { return harr[0]; }

	void del(int i)
	{
		decreaseKey(i, INT_MIN);
		extractmax();
	}

	void insert(int k)
	{
		if (hs == capacity)
		{
			cout << "\nOverflow: Could not insertKey\n";
			return;
		}

		hs++;
		int i = hs - 1;
		harr[i] = k;
		while (i != 0 && harr[parent(i)] < harr[i])
		{
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
		}

}
void print()
{
    cout << "Array representation of heap is:\n";

    for (int i = 0; i < hs; ++i)
        cout << harr[i] << " ";
    cout << "\n";
}
void sorte()
{
	int n=hs;
while(hs>0){
	int root = harr[0];
	harr[0] = harr[hs-1];
	harr[hs-1]=root;
	hs--;
	maxheapify(0);}
	for(int i=0;i<n;i++) cout<<harr[i]<<' ';
}
};

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}



int main()
{
	maxheap h(10);
	int x,a,n;
	while(true){
	cout<<"Enter choice: 1 to insert, 2 to get max, 3 to extract max, 4 to build-heap, 5 to display, 6 to quit ";
	cin>>x;
	switch(x){
		case 1:{cout<<"Enter element "; cin>>a; h.insert(a); break;}
		case 2:{ cout<<h.getmax()<<" is max element"<<endl; break;}
		case 3:{cout<<h.extractmax()<<" removed"<<endl; break;}
		case 4:{h.buildheap(); h.print(); break;}
		case 5:{h.print(); break;}
		case 6: exit(0);
		case 7:{h.sorte();}
	}}
}
