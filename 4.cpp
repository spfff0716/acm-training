#include<stdio.h>
#include<stdlib.h>
int main()
{double a,b;
scanf("%lf",&a);
if(a<10)
b=0.1*a;
 else if(a>=10&&a<20)
 b=10*0.1+(a-10)*0.07;
 else if(a>=20&&a<40)
  b=10*0.1+10*0.07+(a-20)*0.05;
  else if(a>=40&&a<60)
  b=10*0.1+10*0.07+20*0.05+(a-40)*0.03;
   else if(a>=60&&a<100)
    b=10*0.1+10*0.07+20*0.05+20*0.03+(a-60)*0.015;
     else if(a>=100)
      b=10*0.1+10*0.07+20*0.05+20*0.03+40*0.015+(a-100)*0.01;
printf("%lf\n",b);
      return 0;
}
