#include <bits/stdc++.h>
using namespace std;
struct node
{
	long long start;
	long long last;
};
bool cmp(node x,node y)
{
	return x.start<y.start;
}
int main()
{
	int n;
	cin>>n;
	vector<node>arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].start>>arr[i].last;
	}
	sort(arr.begin(),arr.end(),cmp);
	long long n1=arr[0].start;
	long long n2=arr[0].last;
	long long res=0;
	for(int i=1;i<n;i++)
	{
		if(n2<arr[i].start)
		{
			res+=n2-n1;
			n1=arr[i].start;
			n2=arr[i].last;
		}
		else
		n2 = max(n2, arr[i].last);
	}
	res+=n2-n1;
	cout<<res;
	return 0;
 } 
