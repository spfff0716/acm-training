#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
	int s=0,m=0;
	string arr;
	string result=""; 
	cin>>arr;
	
	for(int i=0;i<arr.size();i++)
	{
		if(arr[i]=='(')
		{
			result+='(';
			if(i+1>=arr.size()||arr[i+1]!=')')
			result+=')';
			
		 
		}
		else if(arr[i]==')')
		{
			if(i-1<0||arr[i-1]!='(')
			result+='(';
			result+=')';
		 }
		
		else if(arr[i]=='[')
		{
			result+='[';
			if(i+1>=arr.size()||arr[i+1]!=']')
			result+=']';
			
		 
		}
		else if(arr[i]==']')
		{
			if(i-1<0||arr[i-1]!='[')
			result+='[';
			result+=']';
		 }
	}
	cout<<result;
	return 0;
 } 
