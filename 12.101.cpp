#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> prev(n+2),next(n+2);
	prev[0]=prev[n+1]=next[0]=next[n+1]=0;
	prev[1]=0; 
	next[1]=0;
	int head=1;
	int x,y;
	for(int i=2;i<=n;i++)
	{
		cin>>x>>y;
		if(y==0)
		{
			
			next[i]=x;
			prev[i]=prev[x];
			if(prev[x])
			{
				next[prev[i]]=i;
			}
			else
			{
				head=i;
			}
			prev[x]=i;
		}
		else
		{
			
			prev[i]=x;
			next[i]=next[x];
			if(next[x])
			{
				prev[next[i]]=i;
			}
			next[x]=i;
		}
	}
	int m;
	cin>>m; 
	while(m--)
	{
		cin>>x;
		if(prev[x])
		{
			next[prev[x]]=next[x];
		}
		if(x==head)
		head=next[x];
		else if(next[x])
		{
		prev[next[x]]=prev[x];}
		prev[x] = next[x] = 0;
		
	}
	for(int i=head;i!=0;i=next[i])
	{
		cout<<i<<" ";
	}
	return 0;
	
}
	
