#include <stdio.h>
#include <stdlib.h>
int main()
{
  char num[100];
  scanf("%s",num);
  
  for(int i=0;num[i];++i)
  if(num[i]>='a'&&num[i]<='z')
  num[i]-=32;
  printf("%s",num);
  return 0;
  } 
