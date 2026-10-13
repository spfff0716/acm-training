#include <bits/stdc++.h>
using namespace std;
void dfs(string pre,string in)
{
	if(pre.empty())
	return;
	char root=pre[0];
	int pos=in.find(root);
	dfs(pre.substr(1,pos),in.substr(0,pos));
	dfs(pre.substr(pos+1),in.substr(pos+1));
	cout<<root;
	return;
}
int main()
{
	string pre,in;
	cin>>in>>pre;
	dfs(pre,in);
	return 0;
}
