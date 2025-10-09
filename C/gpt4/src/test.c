// 输入一个整数 n，再输入 n 个数，输出它们的平均值（保留两位小数）。
#include <stdbool.h>
#include <stdio.h>

int
main (void)
{
    int n = 0;
    printf ("how many num want(enter 0 to exit):");
    while (true)
        {
            int arry[n];
            int i;
            double sum;
            scanf ("%d", &n);

            if (n == 0)
                {
                    return 0;
                }

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
