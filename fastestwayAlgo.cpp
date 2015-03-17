
#include<iostream>
using namespace std;
void FastestWayAlgo(int e1,int e2,int *a1,int *a2,int x1,int x2,int *f1,int *f2,int *L1,int *L2,int &L,int *t1,int *t2,int n)
{
	f1[1]=e1+a1[1]; //Entrance time and time at first station in line 1
	f2[1]=e2+a2[1]; //Entrance time and time at first station in line 2
	int i;
	for(i=2;i<n;i++) //loop from station 2 to last station of Line 1
	{
		if(f1[i-1]+a1[i]<f2[i-1]+a1[i]+t2[i-1])
		{
			f1[i]=f1[i-1]+a1[i];
			L1[i]=1;
		}
		else
		{
			f1[i]=f2[i-1]+a1[i]+t2[i-1];
			L1[i]=2;
		}
		if(f2[i-1]+a2[i]<f1[i-1]+a2[i]+t1[i-1]) //loop from station 2 to last station of Line 2
		{
			f2[i]=f2[i-1]+a2[i];
			L2[i]=2;
		}
		else
		{
			f2[i]=f1[i-1]+a2[i]+t1[i-1];
			L2[i]=1;
		}
	}
	
	if(f1[n-1]+x1<f2[n-1]+x2)
	{
		f1[n]=f1[n-1]+x1;
		L=1;
	}
	else
	{
		f1[n]=f2[n-1]+x2;
		L=2;
	}

}
//
void fasttime(int *L1,int *L2,int L,int n,int *f1)
{
	int i=L;
	
	cout<<"Station Number = "<<n<<" is on line = "<<i<<endl;
	int j;
	for(j=n;j>=2;j--)
	{
		if(i==1)
		{
			i=L1[j];
		}
		else
		{
			i=L2[j];
		}
		cout<<"Station Number = "<<j-1<<" is on line = "<<i<<endl;
		//<<"Fastest Time = "<<f1[length+1]<<endl;
	}
	cout<<"Fastest Time = "<<f1[n+1]<<endl;
}
int main()
{
	int e1=6,e2=7,x1=4,x2=1;
	int a1[8]={1,2,3,4,5,6,7,1};
	int a2[8]={7,6,5,4,3,2,1,1};
	int t1[7]={9,8,7,6,5,4,1};
	int t2[7]={8,6,4,2,1,3,1};
	int f1[9],f2[9],L1[9],L2[9],L;
	FastestWayAlgo(e1,e2,a1,a2,x1,x2,f1,f2,L1,L2,L,t1,t2,7);
	fasttime(L1,L2,L,6,f1);
	return 0;
}
