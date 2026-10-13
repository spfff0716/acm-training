#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct node
{
	ll time,ed;
};
bool cmp(node x,node y)
{
	return x.ed<y.ed;
}
int main()
{
	int n;
	cin>>n;
	vector<node>arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].time>>arr[i].ed;
	}
	sort(arr.begin(),arr.end(),cmp);
	priority_queue<ll,vector<ll>>q;
	ll now=0;
	for(int i=0;i<n;i++)
	{
		now+=arr[i].time;
		q.push(arr[i].time);
		while(now>arr[i].ed)
		{
			now-=q.top();
			q.pop();
		}
	}
	cout<<q.size();
	return 0;
 } 
