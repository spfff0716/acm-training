#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][3];
int random(int left,int right)
{
	return(a[rand()%(right-left+1)+left][2]);
}
void sort(int left,int right)
{
	if(left>=right)
	return;
	int p=random(left,right);
	int l=left-1;
	int r=right+1;
	int i=left;
	while(i<r)
	{
		if(a[i][2]<p)
		{
			swap(a[i],a[++l]);
			i++;
		}
		else if(a[i][2]==p)
		i++;
		else
		{
			swap(a[i],a[--r]);
		}
	}
	sort(left,l);
	sort(r,right);
	return;
}
int main()
{
	srand(time(0));
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<3;j++)
		cin>>a[i][j];
	}
	sort(1,n);
	double sum=0.0;
	for(int i=1;i<n;i++)
	{
		int dx=a[i+1][0]-a[i][0];
		int dy=a[i+1][1]-a[i][1];
		int dz=a[i+1][2]-a[i][2];
		double l=sqrt(pow(dx,2)+pow(dy,2)+pow(dz,2));
		sum=sum+l;
	}
	printf("%.3f",sum);
	return 0;
	
}
