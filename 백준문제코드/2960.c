#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int N, K, i, j, cnt;
    int *arr;

    scanf("%d %d", &N, &K);
    arr = (int *)malloc(sizeof(int) * (N + 1));

    for (i = 2; i <= N; i++)
    {
        arr[i] = i;
    }

    cnt = 0;
    for (i = 2; i <= N; i++)
    {
        if (arr[i] != -1)
        {
            for (j = 1; i * j <= N; j++)
            {
                if (arr[i * j] != -1)
                {
                    cnt++;
                    arr[i * j] = -1;
                }
                if (cnt == K)
                {
                    printf("%d", i * j);
                    return 0;
                }
            }
        }
    }
}