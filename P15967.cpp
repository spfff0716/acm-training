#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<int>lufei(n-1);
	for(int i=0;i<n-1;i++)
	{
		cin>>lufei[i];
	}
	int id=0;
	long long res=0;
	while(k--)
	{
		int x;
		cin>>x;
		if(m>x)
		{
			res+=x;
			m-=x;
		}
		else
		{
			res+=m;
			break;
		}
		m-=lufei[id];
		if(m<=0)
		break;
		id++;
		
	}
	cout<<res;
	return 0;
}
