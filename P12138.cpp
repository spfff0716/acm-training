#include <bits/stdc++.h>
using namespace std;
bool isprime(int n)
{
	if(n==2||n==3)
	return true;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		return false;
	}
	return true;
}
int main()
{
	int cnt=0;
	int i=2;
	while(true)
	{
		if(isprime(i))
		{
			cnt++;
		}
		if(cnt==2025)
		break;
		i++;
	}
	cout<<i;
	return 0;
}
