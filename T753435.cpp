#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x,y,z;
	cin>>x>>y>>z;
	if(z==0)
	{
		if(x==0)
		cout<<y;
		else
		{
			cout<<y+1;
		}
		return 0;
	}
	int sum=0;
	sum+=1;
	z--;
	sum+=y*2;
	if(x==0)
	{
		sum+=z*2;
	}
	else
	{
		if(z>=x-1)
		{
			sum+=(x-1)*3+2;
			sum+=(z-x+1)*2;
		}
		else
		{
			sum+=z*3+2;
			if(x>=2)
			sum+=1;
		}
	}
	cout<<sum;
	return 0;
}
