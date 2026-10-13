#include <stdio.h>
#include <stdlib.h>
int main()
{unsigned int n;
scanf("%u",&n);
if(n<2)
return 0;
int i=1;
while(i*10<n)
i=i*10;
unsigned int b;
b=n-i*(n/i);
printf("%u",b);
return 0;
}
