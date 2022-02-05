#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, j;
    long long *btn;

    scanf("%d", &N);

    if (N <= 6)
    {
        printf("%d", N);
        return 0;
    }

    btn = (long long *)malloc(sizeof(long long) * (N + 1));

    for (i = 1; i <= 6; i++)
    {
        btn[i] = i;
    }

    for (i = 7; i <= N; i++)
    {
        btn[i] = i;
        for (j = 3; j < i; j++)
        {
            if (btn[i] < btn[i - j] * (2 + j - 3))
            {
                btn[i] = btn[i - j] * (2 + j - 3);
            }
        }
    }
    printf("%lld", btn[N]);
}