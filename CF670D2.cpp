#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct node
{
	ll used,num,left;
 };
bool cmp(node x,node y)
{
	return x.num<y.num;
}
int main()
{
	ll n,k;
	cin>>n>>k;
	vector<node>brr(n);
	for(int i=0;i<n;i++)
	{
		cin>>brr[i].used;
	}
	for(int i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		brr[i].num=x/brr[i].used;
		brr[i].left=x%brr[i].used;
	}
	sort(brr.begin(),brr.end(),cmp);
	ll ans=brr[0].num;
	ll nowid=0;
	ll sum=0;
	while(k>0&&nowid<n)
	{
		ll cnt1=brr[nowid].num-ans;
		if(k<=cnt1*sum)
		{
			if(sum!=0)
			ans+=k/sum;
			break; 
		}
		else
		{
			k-=cnt1*sum;
			ans+=cnt1;
		}
		ll cost=sum; 
		while(nowid<n)
		{
			if(brr[nowid].num>ans)
			break;
			cost+=brr[nowid].used-brr[nowid].left;
			sum+=brr[nowid].used;
			nowid++;
		}
		k-=cost;
		if(k>=0)
		ans++;
	}
	if(nowid == n && k > 0)
	{
	    ans += k / sum;
	}
	cout<<ans;
	return 0;
}
