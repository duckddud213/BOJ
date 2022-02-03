#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, j, max, tmp, idx;
    int *arr, *LIS, *new_arr;

    scanf("%d", &N);

    arr = (int *)malloc(sizeof(int) * (N + 1));
    LIS = (int *)malloc(sizeof(int) * (N + 1));

    for (i = 1; i <= N; i++)
    {
        scanf("%d", arr + i);
    }

    LIS[1] = 1;

    for (i = 2; i <= N; i++)
    {
        LIS[i] = 1;
        for (j = 1; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                if (LIS[i] < LIS[j] + 1)
                {
                    LIS[i] = LIS[j] + 1;
                }
            }
        }
    }

    max = LIS[1];
    for (i = 2; i <= N; i++)
    {
        if (max < LIS[i])
        {
            max = LIS[i];
        }
    }

    printf("%d\n", max);
    new_arr = (int *)malloc(sizeof(int) * (max + 1));
    idx = 1;
    tmp = max;
    for (i = N; (i >= 1) && (tmp > 0); i--)
    {
        if (LIS[i] == tmp)
        {
            new_arr[idx] = arr[i];
            tmp--;
            idx++;
        }
    }

    for (i = max; i >= 1; i--)
    {
        printf("%d ", new_arr[i]);
    }
}