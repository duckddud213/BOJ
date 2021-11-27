#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M, i, j, s, e, sum;
    int *arr;
    int *total;

    scanf("%d %d", &N, &M);
    arr = (int *)malloc(sizeof(int) * N);
    total = (int *)malloc(sizeof(int) * N);

    for (i = 0; i < N; i++)
    {
        scanf("%d", arr + i);
        if (i == 0)
            total[i] = arr[i];
        else
        {
            total[i] = total[i - 1] + arr[i];
        }
    }

    for (i = 0; i < M; i++)
    {
        sum = 0;
        scanf("%d %d", &s, &e);
        if (s == 1)
        {
            printf("%d\n", total[e - 1]);
        }
        else
        {
            printf("%d\n", total[e - 1] - total[s - 2]);
        }
    }
}