#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	cin>>a;
	int k;
	cin>>k;
	int flag=1;
	int flag1=1;
	int n=a.size();
	vector<int>arr(n+1);
	for(int i=1;i<=n;i++)
	{
		arr[i]=a[i-1]-'0';
	}
	int idex=1;
	int now;
	while(true)
	{
		int min=10;
		for(int i=idex;i<=idex+k;i++)
		{
			if(arr[i]<min)
			{
				min=arr[i];
				now=i;
			}
		}
		k=k-(now-idex);
		if(arr[now]>0)
		{
			cout<<arr[now];
			flag=0;
			flag1=0;
		}
		idex=now+1;
		if((n-now)==k)
		break;
		if(k==0)
		{
			for(int i=idex;i<=n;i++)
			{
				if(flag==0)
				cout<<arr[i];
				else
				{
					if(arr[i]>0)
					{
						cout<<arr[i];
						flag=0;
						flag1=0;
					}
					if(arr[i]==0)
					continue;
				}
				
				
			}
			break;
		}
		
		
	 } 
	 if(flag)
	 cout<<"0";

	return 0;
	
 } 
