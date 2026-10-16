#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	set<string>a;
	while(n--)
	{
		string s;
		cin>>s;
		a.insert(s);
	}
	int m;
	cin>>m;
	vector<string>book(m+1);
	set<string>b;
	int res1=0;
	int l=0;
	int r=0;
	map<string,int>now;
	for(int i=0;i<m;i++)
	{
		string s;
		cin>>s;
		book[i]=s;
		if(a.find(s)!=a.end())
		{
			b.insert(s);
		}
	}
	res1=b.size();
	int cnt=0;
	b.clear();
	while(true)
	{
		string s=book[r];
		if(a.find(s)!=a.end())
		{
			if(b.find(s)==b.end())
			{
				cnt++;
				b.insert(s);
				now[s]=1;
			}
			else
			now[s]++;
		}
		if(cnt==res1)
		break;
		r++;
	}
	int res2=r-l+1;
	bool ok=false;
	while(true)
	{
		while(l<r)
		{
			string s=book[l];
			if(a.find(s)==a.end())
			{
				l++;
				continue;
			}
			else
			{
				if(now[s]==1)
				break;
				else
				{
					now[s]--;
					l++;
				}
			}
		}
		res2=min(res2,r-l+1);
		if(ok)
		break;
		while(r<m)
		{
			r++;
			if(r==m)
			{
				ok=true;
				break;
			}
			string s=book[r];
			if(a.find(s)!=a.end())
			{
				now[s]++;
				if(s==book[l])
				break;
			}
		}
	}
	cout<<res1<<endl<<res2;
	return 0;
}
