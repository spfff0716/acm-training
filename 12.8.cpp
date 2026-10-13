#include <stdio.h>
#include <stdlib.h>
#define col 5
void zero(int i,char a[][col])
{
	for(int j=0;j<col;j++)
	{
		a[i][j]='X';
		
		a[i+2][j]='X';
	}
	a[i+1][0]='.';
	for(int j=1;j<col-1;j++)
	{
		a[i+1][j]='X';
	}
	a[i+1][col]='.';
}

void one(int i,char a[][col])
{
	for(int j=0;j<col;j++)
	{
		a[i][j]='.';
		a[i+1][j]='.';
		a[i+2][j]='X';
	}
	
}
void two(int i,char a[][col])
{
	for(int j=0;j<col;j++)
	{
		if(j==1)
		a[i][j]='.';
		else
		a[i][j]='X';
	}
	for(int j=0;j<col;j++)
	{
		if(j==1||j==3)
		a[i+1][j]='.';
		else
		a[i+1][j]='X';
	}
	for(int j=0;j<col;j++)
	{
		if(j==3)
		a[i][j]='.';
		else
		a[i][j]='X';
	}
	
}
void three(int i,char a[][col])
{
	for(int j=0;j<col;j++)
	{
		if(j==1||j==3)
		a[i][j]='.';
		else
		a[i][j]='X';
	}
	for(int j=0;j<col;j++)
	{
		if(j==1||j==3)
		a[i+1][j]='.';
		else
		a[i+1][j]='X';
	}
	for(int j=0;j<col;j++)
	{
		
		a[i][j]='X';
	}
	
}
void four(int i,char a[][col])
{
	for(int j=0;j<col;j++)
	{
		if(j==3||j==4)
		a[i][j]='.';
		else
		a[i][j]='X';
	}
	for(int j=0;j<col;j++)
	{
		if(j==2)
		a[i+1][j]='X';
		else
		a[i+1][j]='.';
	}
	for(int j=0;j<col;j++)
	{
		
		a[i][j]='X';
	}
	
}
void five(int i,char a[][col])
{
	for(int j=0;j<col;j++)
	{
		if(j==3)
		a[i][j]='.';
		else
		a[i][j]='X';
	}
	for(int j=0;j<col;j++)
	{
		if(j==1||j==3)
		a[i+1][j]='.';
		else
		a[i+1][j]='X';
	}
	for(int j=0;j<col;j++)
	{
		if(j==1)
		a[i][j]='.';
		else
		a[i][j]='X';
	}
	
}
void six(int i,char a[][col])
{
	for(int j=0;j<col;j++)
	{
		
		a[i][j]='X';
	}
	for(int j=0;j<col;j++)
	{
		if(j==1)
		a[i+1][j]='.';
		else
		a[i+1][j]='X';
	}
	for(int j=0;j<col;j++)
	{
		if(j==1)
		a[i][j]='.';
		else
		a[i][j]='X';
	}
	
}
void seven(int i,char a[][col])
{
	for(int j=0;j<col;j++)
	{
		if(j==0)
		a[i][j]='X';
		else
		a[i][j]='.';
	}
	for(int j=0;j<col;j++)
	{
		if(j==0)
		a[i+1][j]='X';
		else
		a[i+1][j]='.';
	}
	for(int j=0;j<col;j++)
	{
	
		a[i][j]='X';
	}
	
}void eight(int i,char a[][col])
{
	for(int j=0;j<col;j++)
	{
		
		a[i][j]='X';
	}
	for(int j=0;j<col;j++)
	{
		if(j==1||j==3)
		a[i+1][j]='.';
		else
		a[i+1][j]='X';
	}
	for(int j=0;j<col;j++)
	{
		
		a[i][j]='X';
	}
	
}
void nine(int i,char a[][col])
{
	for(int j=0;j<col;j++)
	{
		if(j==3)
		a[i][j]='.';
		else
		a[i][j]='X';
	}
	for(int j=0;j<col;j++)
	{
		if(j==1||j==3)
		a[i+1][j]='.';
		else
		a[i+1][j]='X';
	}
	for(int j=0;j<col;j++)
	{
	
		a[i][j]='X';
	}
	
}

int main()
{
	int n;
	scanf("%d",&n);
	getchar();   
	char num[n];
	scanf("%s",num);
	char a[4*n-1][col];
	int i=0;
	for(int j=0;j<n;j++)
	{
		if(num[j]=='0')
		zero(i,a);
		if(num[j]=='1')
		one(i,a);
		if(num[j]=='2')
		two(i,a);
		if(num[j]=='3')
		three(i,a);
		if(num[j]=='4')
		four(i,a);
		if(num[j]=='5')
		five(i,a);
	    if(num[j]=='6')
		six(i,a);
		if(num[j]=='7')
		seven(i,a);
		if(num[j]=='8')
		eight(i,a);
		if(num[j]=='9')
		nine(i,a);
		if(j<n-1)
		{
		for(int k=0;k<col;k++)
		{
			a[i+3][k]='.';
		}}
		i=i+4;
	}
	for(int j=0;j<4*n-1;j++)
	{
		for(int k=0;k<col;k++)
		{
			printf("%c",a[k][j]);
		}
		printf("\n");
	}
	return 0;
	
}



