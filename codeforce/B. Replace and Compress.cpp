#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int cnt=1;
		bool flag1=false;
		bool flag2=false;
		for(int i=1;i<s.size()-1;i++)
		{
			if(s[i-1]!=s[i]&&s[i]!=s[i+1])
			{
				flag1=true;
			}
			else if(s[i-1]==s[i]&&s[i]==s[i+1])
			{
				flag2=true;
			}
			if(flag1&&flag2)
			break;
		}
		if(flag1)
		cnt++;
		if(flag2)
		cnt++;
		cout<<cnt<<endl;
	}
	return 0;
 } 
