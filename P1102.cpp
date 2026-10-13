#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
long long arr[N];
int main()
{
	int n;
	long long c;
	cin>>n>>c;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	long long x=arr[0]+c;
	int l=0,r=n-1;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(arr[mid]>=x)
		r=mid;
		else
		l=mid+1;
	}
	int id1=0;
	int id2=l;
	long long res=0;
	while(true)
	{
		if(arr[id2]-arr[id1]==c)
		{
			long long a=1;
			long long b=1;
			while(arr[id1+1]==arr[id1])
			{
				a++;
				id1++;
			}
			id1++;
			while(arr[id2+1]==arr[id2]&&id2<n-1)
			{
				b++;
				id2++;
			}
			if(id2<n-1)
			id2++;
			res+=a*b;
			cout<<res<<endl;
		}
		else if(arr[id2]-arr[id1]>c)
		{
			id1++;
			
		}
		else
		{
			if(id2<n-1)
			id2++;
			else
			{
				break;
			}
		}
		if(id1==n-1)
		break;
	}
	cout<<res;
	return 0;
}
