#include <bits/stdc++.h>
using namespace std;
int n;
const int N=2010;
int color[N];
int nextpos[N][55];
int leftlen[N];
int leftcolor[N];
bool seen[55];
int search_left(int r)
{
	memset(seen,false,sizeof(seen)); 
	int cnt=0;
	for(int i=r;i>=1;i++)
	{
		int c=color[i]; 
		if(!seen[c])
		{
			cnt++;
			seen[c]=true;
			leftlen[cnt]=r-i+1;
			leftcolor[cnt]=c;
		}
	}
	return cnt;
}
int main()
{
	cin>>n;
	int id=1;
	set<string>s;
	map<string,int>mp;
	for(int i=1;i<=n;i++)
	{
		string s1;
		cin>>s1;
		if(s.find(s1)==s.end())
		{
			color[i]=id;
			mp[s1]=id;
			id++;
			s.insert(s1);
		}
		else
		{
			color[i]=mp[s1];
		}
	}
	int colornum=id-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=50;j++)
		{
			nextpos[i][j]=-1;
		}
	}
	nextpos[n][color[n]]=n;
	int res=2020; 
	for(int i=n-1;i>=1;i--)
	{
		for(int j=1;j<=50;j++)
		{
			nextpos[i][j]=nextpos[i+1][j];
		}
		nextpos[i][color[i]]=i;
	}
	for(int r=1;r<n;r++)
	{
		int res1=2020;
		int num=search_left(r);
		for(int s=r+1;s<=n;s++)
		{
			int right=-1;
			bool ok=false;
			for(int c=1;c<=colornum;c++)
			{
				if(!seen[c])
				{
					if(nextpos[s][c]==-1)
					{
						ok=true;
						break;
					}
					right=max(right,nextpos[s][c]);
				}
			}
			if(ok)
			continue;
			if(num==colornum)
			right=s;
			res1=min(res1,right-s+1+leftlen[num]);
			for(int k=num-1;k>=1;k--)
			{
				int last_color= leftcolor[k+1];
				if(nextpos[s][last_color]==-1)
				break;
				right=max(right,nextpos[s][last_color]);
				res1=min(res1,right-s+1+leftlen[k]);
			}
		}
		res=min(res1,res);
	}
	cout<<res;
	return 0;
 } 
