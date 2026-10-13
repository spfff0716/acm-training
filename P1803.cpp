#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct node
{
	int st;
	int ed;
}arr[N];
bool cmp(node x,node y)
{
	return x.ed<y.ed;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].st>>arr[i].ed;
	}
	sort(arr,arr+n,cmp);
	int res=1;
	int end=arr[0].ed;
	for(int i=1;i<n;i++)
	{
		if(arr[i].st>=end)
		{
			res++;
			end=arr[i].ed;
		}
	}
	cout<<res;
	return 0;
}
