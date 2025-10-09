// 输入一个整数 n，再输入 n 个数，输出它们的平均值（保留两位小数）。
#include <stdbool.h>
#include <stdio.h>

int
main ()
{
    int n;
    printf ("how many num want:");
    scanf ("%d", &n);
    int arry[n];
    while (true)
        {
            int i;
            double sum;
            for (i = 0; i < n; i++)
                {
                    scanf ("%d", &arry[i]);
                }
            for (i = 0; i < n; i++)
                {
                    sum = sum + arry[i];
                }
            printf ("avg is:%.2f", (sum / n));
        }
}
