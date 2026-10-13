#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) return 0;

    /* 1. 算出最高位权值 base */
    int base = 1;
    while (base * 10 <= n) base *= 10;

    /* 2. 从高到低逐位拆，正序输出奇数 */
    int first = 1;                 // 开关：第一次不补空格
    for (; base > 0; base /= 10) {
        int d = n / base % 10;     // 当前位
        if (d % 2) {               // 奇数才打印
            if (!first) printf(" ");
            printf("%d", d);       // 原样输出
            first = 0;
        }
    }

    if (first) printf("0");        // 一个奇数都没有
    printf("\n");
    return 0;
}

