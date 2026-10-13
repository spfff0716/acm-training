#include <bits/stdc++.h>
using namespace std;
const int N=1000;
int a[N],b[N],res[N];
int l=1;
void p()
{
	int carry=0;
	for(int i=0;i<l;i++)
	{
		res[i]=a[i]+b[i]+carry;
		carry=res[i]/10;
		res[i]=res[i]%10;
	}
	if(carry)
	{
		res[l]=carry;
		l++;
	}
}
void sum(int n)
{
	a[0]=1;
	b[0]=2;
	for(int i=3;i<=n;i++)
	{
		p();
		copy(begin(b),end(b),begin(a));
		copy(begin(res),end(res),begin(b));
	 } 
		
 } 
 int main()
 {
 	int n;
 	cin>>n;
 	if(n==1)
 	cout<<"1";
 	else if(n==2)
 	cout<<"2";
	else 
 	{
 		sum(n);
 		for(int i=l-1;i>=0;i--)
 		{
 			cout<<res[i];
		 }
	 }
 	return 0;
 }
