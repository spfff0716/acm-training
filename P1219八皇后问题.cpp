#include <bits/stdc++.h>
using namespace std;
vector<int>res;
int used[20];
int zheng[40];
int xie[40];
int cnt=0;
void dfs(int n,int row)
{
	if(res.size()==n)
	{
		if(cnt<3)
		{
			for(int i=0;i<n;i++)
		{
			cout<<res[i]<<" ";
		}
		cout<<endl;
		}
		cnt++;
	}
	for(int i=1;i<=n;i++)
	{
		if(used[i]==0&&zheng[row+i]==0&&xie[row-i+n]==0)
		{
			used[i]=1;
			zheng[row+i]=1;
			xie[row-i+n]=1;
			res.push_back(i);
			dfs(n,row+1);
			used[i]=0;
			zheng[row+i]=0;
			xie[row-i+n]=0;
			res.pop_back();
		}
	}
}
int main()
{
	int n;
	cin>>n;
	dfs(n,1);
	cout<<cnt;
	return 0;
	
 } 
