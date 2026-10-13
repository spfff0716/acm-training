#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> path;
vector<int> search1; 
void res()
{
	if(path.size()==n)
	{
		for(int i=0;i<n;i++)
		cout<<setw(5)<<path[i];
		cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
	
	if(search1[i]==0){
		search1[i]=1;
		path.push_back(i);
		res();
		path.pop_back();
		search1[i]=0;
	}}
}
int main()
{
	cin>>n;
	search1.resize(n+1,0); 
	res();
	return 0;
}
