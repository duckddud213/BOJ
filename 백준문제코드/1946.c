#include <stdio.h>
#include <stdlib.h>

typedef struct score
{
    int a, b;
} score;

int compare(const void *x, const void *y)
{
    score a = *(score *)x;
    score b = *(score *)y;

    if (a.a > b.a)
    {
        return 1;
    }
    else if (a.a < b.a)
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
    int x, T, N, i, cnt, rank;
    score *apply;

    scanf("%d", &T);
    apply = (score *)malloc(sizeof(score) * 100000);

    for (x = 0; x < T; x++)
    {
        cnt = 1;
        scanf("%d", &N);
        for (i = 0; i < N; i++)
        {
            scanf("%d %d", &apply[i].a, &apply[i].b);
        }
        qsort(apply, N, sizeof(score), compare);

        rank = apply[0].b;
        for (i = 1; i < N; i++)
        {
            if (rank > apply[i].b)
            {
                cnt++;
                rank = apply[i].b;
            }
        }
        printf("%d\n", cnt);
    }
}