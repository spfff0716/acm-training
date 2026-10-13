#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int a[N];
int temp[N];
int b[N];
int random(int left,int right)
{
	return a[rand()%(right-left+1)+left];
	}
void sort(int left,int right)
{
	if(left>=right)
	return;
	int l=left-1;
	int i=left;
	int r=right+1;
	int p=random(left,right);
	 while(i<r)
	 {
	 	if(a[i]>p)
	 	{
	 		swap(a[++l],a[i]);
	 		i++;
		 }
		else if(a[i]==p)
		{
			i++;
		}
		else
		{
			swap(a[--r],a[i]);
		}
	 }
	 sort(left,l);
	 sort(r,right);
	 return;
}
int main()
{
	int idex;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
		temp[a[i]]=i;
	}

	int sum=0;
	int n1=n;
	srand(time(0));
	sort(1,n);
	for(int i=1;i<=n;i++)
	{
		sum=sum+n1-temp[a[i]];
		n1--;
		for(int j=1;j<=n;j++)
		{
			if(a[i]==b[j])
			{
				idex=j;
				break;
			}
		}
		for(int k=idex+1;k<=n;k++)
		{
			temp[b[k]]--;
		}
	}
	cout<<sum;
	return 0;
}
