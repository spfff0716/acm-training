#include <stdio.h>
#include <stdlib.h>
double benjin(double a,int b);

void print0(double a,int b);
int main()
{double s;
int n;
scanf("%lf %d",&s,&n);
print0(s,n);
return 0;


}

double benjin(double a,int b)
{if(b==1)
return a*1.053;
else
return benjin(a,b-1)+a*0.053;

}
 void print0(double a,int b)
 {int i=1;
 while(i<=b)
 {printf("%d %.2f %.2f\n",i,a*0.053,benjin(a,i));
 i++;
 }}
 
