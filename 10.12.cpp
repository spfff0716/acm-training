#include <stdio.h>

int main(void)
{
    int  n;
    char ch;

  
    printf("请输入数字：");
    scanf("%d", &n);

   
    getchar();              
    printf("请输入一个字符：");
    scanf("%c", &ch);
    
   

    printf("你输入的数字是%d，你输入的字符是'%c\n'", n, ch);
    return 0;
}

