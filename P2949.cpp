#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct node
{
	ll ed,value;
};
bool cmp(node x,node y)
{
	if(x.ed==y.ed)
	return x.value>y.value;
	return x.ed<y.ed;
}
int main()
{
	int n;
	cin>>n;
	vector<node>arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].ed>>arr[i].value;
	 }
	sort(arr.begin(),arr.end(),cmp);
	priority_queue<ll,vector<ll>,greater<ll>>q;
	ll now=1;
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		if(now<=arr[i].ed)
		{
			now++;
			ans+=arr[i].value;
			q.push(arr[i].value);
		}
		else
		{
			ans+=arr[i].value;
			q.push(arr[i].value);
			ans-=q.top();
			q.pop();
		}
	}
	cout<<ans;
	return 0;
}
