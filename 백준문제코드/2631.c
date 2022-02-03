#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, j, max;
    int *Line, *LIS;

    scanf("%d", &N);

    Line = (int *)malloc(sizeof(int) * (N + 1));
    LIS = (int *)malloc(sizeof(int) * (N + 1));

    for (i = 1; i <= N; i++)
    {
        scanf("%d", Line + i);
    }

    LIS[1] = 1;

    for (i = 2; i <= N; i++)
    {
        LIS[i] = 1;
        for (j = 1; j < i; j++)
        {
            if (Line[i] > Line[j])
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

    printf("%d", N - max);
}