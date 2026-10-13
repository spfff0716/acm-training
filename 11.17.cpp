#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cnt = 0;
    char character[10000];
    scanf("%s", character);        

    
    while (character[cnt]) ++cnt;

    char need;
    scanf(" %c", &need);            

    int m = 0;
    for (int i = 0; i < cnt; i++)
        if (character[i] == need) m++;

    printf("%d\n", m);
    return 0;
}

