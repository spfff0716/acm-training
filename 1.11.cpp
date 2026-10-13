#include <bits/stdc++.h>
using namespace std;
int isprime(int n)
{
	if(n<2)
	return 0;
	if(n==2)
	return 1;
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0)
		return 0;
	}
	return 1;
 } 
 int main()
 {
 	vector<int>a(24,0);
 	string s;
 	cin>>s;
 	for(int i=0;i<s.size();i++)
 	{
 		int num=s[i]-'a';
 		a[num]++;
	 }
	 int max=0;
	 int min=102;
	 for(int i=0;i<24;i++)
	 {
	 	if(a[i]>max)
	 	max=a[i];
	 	if(a[i]<min&&a[i]>0)
	 	min=a[i];
	 }
	 int res=max-min;
	 cout<<res;
	 if(isprime(res))
	 {
	 	cout<<"Lucky Word"<<endl;
	 	cout<<res;
	 }
	 else
	 {
	 	cout<<"No Answer"<<endl;
	 	cout<<"0";
	 }
	 return 0;
 }
