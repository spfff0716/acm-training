#include <bits/stdc++.h>
using namespace std;
int time(vector<int>&s,int n)
{
	if(n==1)
	return s[0];
	if(n==2)
	return max(s[0],s[1]);
	sort(s.begin(),s.end());
	reverse(s.begin(),s.end());
	int left=s[0];
	int right=s[1];
	for(int i=2;i<n;i++)
	{
		if(left<right)
		left+=s[i];
		else
		right+=s[i];
	}
	return max(left,right);
	
}
int main()
{
	int s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	vector<int>t1(s1),t2(s2),t3(s3),t4(s4);
	for(int i=0;i<s1;i++)
	{
		cin>>t1[i];
	}
	for(int i=0;i<s2;i++)
	{
		cin>>t2[i];
	}
	for(int i=0;i<s3;i++)
	{
		cin>>t3[i];
	}
	for(int i=0;i<s4;i++)
	{
		cin>>t4[i];
	}
	int res=time(t1,s1)+time(t2,s2)+time(t3,s3)+time(t4,s4);
	cout<<res;
	return 0;
}
