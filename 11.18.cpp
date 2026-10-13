#include <stdio.h> 
#include <stdlib.h>
int fun(char b[],int sum);
int main() 
{
   char a[1000];
   scanf("%s",a);
   int cnt=0;
   while(a[cnt])
   ++cnt;
   fun(a,cnt);
   printf("%s",a);
   return 0;
}
   
   
   
   
   
   int fun(char b[],int sum){
   
   int m=0;
   int i;
   int j;
   int lead=1;
   for(i=0,j=0;i<sum;i++)
   {
   if(lead&&b[i]=='*')
   b[j++]=b[i];
   else if(b[i]!='*')
   {b[j++]=b[i];
   lead=0;
   }
   }
   b[j]='\0';
   return j;
   
   }




