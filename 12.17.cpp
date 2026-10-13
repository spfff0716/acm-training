#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m[10][10];
	char ch;
	int jx,jy,cx,cy;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			cin>>ch;
			if(ch=='.')
			m[i][j]=1;
			else if(ch=='*')
			m[i][j]=0;
			else if(ch=='F')
			{
			m[i][j]=1;
			jx=i;
			jy=j;
		}
			else
			{
			m[i][j]=1;
			cx=i;
			cy=j;
		}
		}
		
	}
	int djx=-1;
	int dcx=-1;
	int djy=0;
	int dcy=0;
	int cnt=0;
	while(true)
	{
		int nejx=jx+djx;
		int nejy=jy+djy;
		int necx=cx+dcx;
		int necy=cy+dcy;
		if(nejx<0||nejx>=10||nejy<0||nejy>=10||m[nejx][nejy]==0)
		{
			int t=djx;
			djx=djy;
			djy=-t;
			
		}
		else
		{
			jx=nejx;
			jy=nejy;
		}
		if(necx<0||necx>=10||necy<0||necy>=10||m[necx][necy]==0)
		{
			int t=dcx;
			dcx=dcy;
			dcy=-t;
			
		}
		else
		{
			cx=necx;
			cy=necy;
		}
		cnt++;
		if((jx==cx&&jy==cy)||cnt>100000)
		break;
	}
	if(cnt<=100000)
	cout<<cnt;
	else
	cout<<"0";
	return 0;
}
