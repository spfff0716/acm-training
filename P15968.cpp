#include <bits/stdc++.h>
using namespace std;
struct node
{
	long long f;
	long long people;
};
bool cmp(node x,node y)
{
	return x.f<y.f;
};
int main()
{
	long long n,now,y;
	long long w;
	cin>>n>>now>>y>>w;
	vector<node>arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].f>>arr[i].people;
	}
	sort(arr.begin(),arr.end(),cmp);
	long long min=arr[0].f;
	long long id=0;
	long long time=0;
	long long left=w;
	while(id<n)
	{
		time+=abs(now-min);
		now=min;
		if(left<arr[id].people)
		{
			time+=2*abs(y-min);
			arr[id].people-=left;
			left=w;
	
		}
		if(left<arr[id].people)
		{
			long long k;
			if(arr[id].people%left==0)
			{
				k=arr[id].people/left-1;
			}
			else
			k=arr[id].people/left;
			arr[id].people-=k*left;
			time+=2*k*abs(y-min);
			left=w;
		}
		else
		{
			left-=arr[id].people;
			if(id==n-1)
			{
				time+=abs(y-now);
				break;
			}
			min=arr[++id].f;
		}
		
		
	}
	cout<<time;
	return 0;
 } 
