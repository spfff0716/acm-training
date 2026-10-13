#include <bits/stdc++.h>
using namespace std;
int s[15][2];
int n;
int minest=INT_MAX;
void dfs(int pos,int acidsum,int ksum)
{
	if(pos==n)
	{
		if(ksum!=0)
		minest=min(minest,abs(acidsum-ksum));
		return; 
	}
	dfs(pos+1,acidsum,ksum);
	int newacid=acidsum*s[pos][0];
	int newk=ksum+s[pos][1];
	dfs(pos+1,newacid,newk);
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i][0]>>s[i][1];
	}
	dfs(0,1,0);
	cout<<minest;
	return 0;
 } 
