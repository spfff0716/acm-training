#include<bits/stdc++.h>
using namespace std;
int res[5000],a[5000],b[5000];
int len=1;
void p()
{
	int carry=0;
	for(int i=0;i<len;i++)
	{
		res[i]=a[i]+b[i]+carry;
		carry=res[i]/10;
		res[i]=res[i]%10;
	}
	if(carry>0)
	{
		res[len]=carry;
		len++;
	}
	
}
int main()
{
	a[0]=1;
	b[0]=1;
	res[0]=1;
	int n,m;
	cin>>m>>n;
	int r=n-m+1;
	for(int i=3;i<=r;i++)
	{
		p();
		memcpy(a,b,sizeof(b));
		memcpy(b,res,sizeof(res));
	}
	for(int i=len-1;i>=0;i--)
	{
		cout<<res[i];
	}
	return 0;
	
}
