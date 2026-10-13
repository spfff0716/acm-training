#include <bits/stdc++.h>
using namespace std;
int best;
void dfs(int pos,int left,int right,vector<int>&time)
{
	if(pos==time.size())
	{
		best=min(best,max(left,right));
	}
	if(max(left,right)>best)
	return;
	dfs(pos+1,left+time[pos],right,time);
	dfs(pos+1,left,right+time[pos],time);
}
int res(vector<int>&t)
{
	best=2000;
	dfs(0,0,0,t);
	return best;
}
int main()
{
	int s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	vector<int>a(s1),b(s2),c(s3),d(s4);
	for(int &x:a) cin>>x;
	for(int &x:b) cin>>x;
	for(int &x:c) cin>>x;
	for(int &x:d) cin>>x;
	int ans=res(a)+res(b)+res(c)+res(d);
	cout<<ans;
	return 0;
	
 } 
