#include <stdio.h>
#include <iostream>
#include <sstream> 
#include <vector>
using namespace std;

int main()
{
	 ios::sync_with_stdio(false);  
    cin.tie(nullptr);
	int val[1000010]; 
	int n,q;
	cin>>n>>q;
	
	 for(int x=0;x<q;x++)
	 {
	 	int op;
	 	cin>>op;
	 	if(op==1)
	 	{
	 		int i,j,k;
	 		
	 		cin>>i>>j>>k;
	 		int id=i*100001+j;
			
			 	val[id]=k;
		}
			
		 
		else
		{
			int i,j;
			cin>>i>>j;
			int id=i*100001+j;
			cout<<val[id]<<'n';
		}
	 }
	
	
	return 0;
	
 } 
