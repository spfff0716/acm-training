#include <bits/stdc++.h>
using namespace std;
struct s{
	int price;
	int a;
};
bool cmp(s x,s y)
{
	return x.price<y.price;
}
int main()
{
	int n;
	int m;
	cin>>n>>m;
	vector<s>arr(m);
	for(int i=0;i<m;i++)
	{
		cin>>arr[i].price>>arr[i].a;
	}
	sort(arr.begin(),arr.end(),cmp);
	int sum=0;
	long long ans=0;
	for(int i=0;i<m;i++)
	{
		if(arr[i].a>=(n-sum))
		{
			ans+=(n-sum)*arr[i].price;
			break;
		}
		else
		{
			ans+=arr[i].a*arr[i].price;
			sum+=arr[i].a;
		}
	}
	cout<<ans;
	return 0;
}
