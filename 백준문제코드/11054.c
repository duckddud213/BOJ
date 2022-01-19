#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, j, tmp;
    int *arr, *LIS, *r_LIS;

    scanf("%d", &N);

    arr = (int *)malloc(sizeof(int) * (N + 1));
    LIS = (int *)malloc(sizeof(int) * (N + 1));
    r_LIS = (int *)malloc(sizeof(int) * (N + 1));

    for (i = 1; i <= N; i++)
    {
        scanf("%d", arr + i);
    }

    LIS[1] = 1;
    r_LIS[N] = 1;

    for (i = 2; i <= N; i++)
    {
        tmp = 0;
        for (j = 1; j < i; j++)
        {
            if ((arr[j] < arr[i]) && (LIS[j] > tmp))
            {
                tmp = LIS[j];
            }
        }
        LIS[i] = tmp + 1;
    }

    for (i = N - 1; i >= 1; i--)
    {
        tmp = 0;
        for (j = N; j > i; j--)
        {
            if ((arr[j] < arr[i]) && (r_LIS[j] > tmp))
            {
                tmp = r_LIS[j];
            }
        }
        r_LIS[i] = tmp + 1;
    }

    tmp = LIS[1] + r_LIS[1];
    for (i = 2; i <= N; i++)
    {
        if (tmp < LIS[i] + r_LIS[i])
        {
            tmp = LIS[i] + r_LIS[i];
        }
    }
    printf("%d", tmp - 1);
}