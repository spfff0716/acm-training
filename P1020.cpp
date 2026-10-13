#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int high[N];
int find1(int x,vector<int>&a)
{
	int l=0;
	int r=a.size();
	while(l<r)
	{
		int mid=(l+r)/2;
		if(x>a[mid])
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	return l;
}
int find2(int x,vector<int>&a)
{
	int l=0;
	int r=a.size();
	while(l<r)
	{
		int mid=(l+r)/2;
		if(x<=a[mid])
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	return l;
}

int main()
{
	int n=0;
	int x=0;
	while(cin>>x)
	{
		high[n]=x;
		n++;
	}
	vector<int>arr;
	vector<int>brr;
	for(int i=0;i<n;i++)
	{
		int now=high[i];
		int id1=find1(now,arr);
		int id2=find2(now,brr);
		if(id1==arr.size())
		arr.push_back(now);
		
		else
		arr[id1]=now;
		if(id2==brr.size())
		brr.push_back(now);
		else
		brr[id2]=now;
	}
	cout<<arr.size()<<endl<<brr.size();
	return 0;
	
}
