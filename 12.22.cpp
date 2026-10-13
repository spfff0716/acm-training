#include <bits/stdc++.h>
using namespace std;
struct contest
{
	int start;
	int end;
}con[1000010];
bool cmp(con a,con b)
{
	return a.start<b.start;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>con.start>>con.end;
	}
	sort(con,con+n,cmp);
	int cnt=0,i=0;
	int now;
	while(true)
	{
		if(i==n-2)
		{
			if(con[i].end<=con[i+1].start)
			cnt+=2;
			else
			cnt++;
			break;
		}
		if(i==n-1)
		{
			cnt++;
			break;
		}
		if(con[i].end>con[i+2].start)
	    i+=2;
		else
		i++;
		cnt++;
	}
}



