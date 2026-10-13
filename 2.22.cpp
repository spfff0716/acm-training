#include <bits/stdc++.h>
using namespace std;
int main()
{
	int p1,p2,p3;
	int flag=0;
	char ch='a';
	cin>>p1>>p2>>p3;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string str;
	getline(cin,str);
	for(int i=0;i<str.length();i++)
	{
		if(str[i]=='-')
		{
			
			for(int j=flag;j<=(i-1);j++)
			{
				cout<<str[j];
			}
			flag=i+1;
			if(isdigit(str[i-1])&&isdigit(str[i+1]))
			{
				int x=str[i+1]-str[i-1];
				if(x>1)
				{
					if(p1==3)
					{
						for(int k=0;k<(x-1);k++)
						{
							for(int j=0;j<p2;j++)
							cout<<"*";
						}
					}
					else
					{
						for(int k=0;k<(x-1);k++)
						{
							if(p3==1)
							{
								int num=str[i-1]-'0'+1; 
								for(int j=0;j<p2;j++)
								cout<<num+k;
								
							}
							if(p3==2)
							{
								int num=str[i+1]-'0'-1;
								for(int j=0;j<p2;j++)
								cout<<num-k;
								
							}
						}
					}
				}
				else if(x<1)
				cout<<"-";
				
			}
			else if(isalpha(str[i-1])&&isalpha(str[i+1]))
			{
				int x=str[i+1]-str[i-1];
				if(x>1)
				{
					if(p1==1)
					{
						for(int k=0;k<(x-1);k++)
						{
							if(p3==1)
							ch=str[i-1]+k+1;

							if(p3==2)
							ch=str[i+1]-k-1;
							for(int j=0;j<p2;j++)
								cout<<ch;
						}
					}
					if(p1==2)
					{
						for(int k=0;k<(x-1);k++)
						{
							if(p3==1)
							ch=str[i-1]-'a'+'A'+k+1;

							if(p3==2)
							ch=str[i+1]-'a'+'A'-k-1;
							for(int j=0;j<p2;j++)
								cout<<ch;
						}
					}
					if(p1==3)
					{
						for(int k=0;k<(x-1);k++)
						{
							for(int j=0;j<p2;j++)
							cout<<"*";
						}
					}
				}
				else if(x<1)
				cout<<"-";
			}
			else
			{
				cout<<"-";
			}
		}
	}
	for(int i=flag;i<str.length();i++)
	cout<<str[i];
	return 0;
}
