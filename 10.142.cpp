#include <stdio.h>
#include <stdlib.h>
 #include <math.h> 
int main()
{double a=-10.0,b=10.0;
double x,f,f1,f2;
do{
x=(a+b)/2.0;
f=2*x*x*x-4*x*x+3*x-6;
f1=2*a*a*a-4*a*a+3*a-6;
f2 = 2*b*b*b - 4*b*b + 3*b - 6;
if (fabs(f1) < 1e-6 ) { x = a; break; }
if (fabs(f2) < 1e-6) { x = b; break; }
if (fabs(f) < 1e-6) { break; }
if(f*f1<0)
b=x;
else a=x;}
while(fabs(f) > 1e-6);

printf("%f",x);


return 0; } 
