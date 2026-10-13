#include <stdio.h>
#include <stdlib.h>
int main(){
int n,j,i;
scanf("%d",&n);
int first=1;
for(i=2;i<=n;i++){

for(j=2;j<i;j++)
if(i%j==0)
break;
if(i==j&&n%i==0){

if(!first)printf(" ");
printf("%d",i);
first=0;}
}
printf("\n");

return 0;}
