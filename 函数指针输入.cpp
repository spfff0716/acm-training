#include <stdio.h>
#include <stdlib.h>

/*
 * 功能：一直读到 EOF 或非法字符，返回长度并把首地址填到 *arr
 * 参数：arr 是“指向指针的指针”，原因见下方④
 * 返回：实际元素个数
 */
int input(int **arr)          // ④ int **arr 解释见下
{
    int cap = 4;              // 初始容量
    int cnt = 0;              // 当前已存个数
    int x;                    // 临时读入值
    int *v = (int*)malloc(cap * sizeof *v); // ⑤ 先申请 4 个 int 空间
    if (!v) return 0;         // 申请失败直接结束

    while (scanf("%d", &x) == 1) {    // ⑥ 能读到一个整数就继续
        if (cnt == cap) {             // ⑦ 坐满了就扩容
            cap *= 2;                 //   容量翻倍
            v = (int *)realloc(v, cap * sizeof *v);
            if (!v) return 0;         //   扩容失败也结束
        }
        v[cnt++] = x;                 // ⑧ 存数+计数
    }

    *arr = v;                         // ⑨ 把首地址写回给调用者
    return cnt;                       // ⑩ 返回实际长度
}

int main(void)
{
    int *a;       // ① 将来指向“动态数组”
    int n;        // ② 将来保存长度

    n = input(&a);                  // ③ 把 a 的地址传进去，函数内部会改 a 的值
    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);        // ⑪ 像普通数组一样用

    free(a);                        // ⑫ 有 malloc 就要 free
    return 0;
}

