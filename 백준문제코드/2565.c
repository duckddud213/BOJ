#include <stdio.h>
#include <stdlib.h>

typedef struct line
{
    int A, B;
} Line;

int compare(const void *x, const void *y)
{
    Line a = *(Line *)x;
    Line b = *(Line *)y;

    if (a.A > b.A)
    {
        return 1;
    }
    else if (a.A < b.A)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int N, i, j, max;
    int *LIS;
    Line *connect;

    scanf("%d", &N);

    connect = (Line *)malloc(sizeof(Line) * N);
    LIS = (int *)malloc(sizeof(int) * N);

    for (i = 0; i < N; i++)
    {
        scanf("%d %d", &connect[i].A, &connect[i].B);
    }
    qsort(connect, N, sizeof(Line), compare);

    LIS[0] = 1;

    for (i = 1; i < N; i++)
    {
        LIS[i] = 1;
        for (j = 0; j < i; j++)
        {
            if ((connect[j].B < connect[i].B) && (LIS[j] + 1 > LIS[i]))
            {
                LIS[i] = LIS[j] + 1;
            }
        }
    }
    max = LIS[0];
    for (i = 1; i < N; i++)
    {
        if (LIS[i] > max)
        {
            max = LIS[i];
        }
    }
    printf("%d", N - max);
}