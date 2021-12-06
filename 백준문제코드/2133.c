#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, j;
    int *dp;

    scanf("%d", &N);
    dp = (int *)malloc(sizeof(int) * (N + 1));

    for (i = 0; i <= N; i++)
    {
        dp[i] = 0;
    }

    if (N % 2 != 0)
    {
        printf("%d", 0);
    }
    else if (N == 2)
    {
        printf("%d", 3);
    }
    else
    {
        dp[2] = 3;
        for (i = 4; i <= N; i += 2)
        {
            dp[i] += dp[i - 2] * 3;
            for (j = 4; j <= i; j += 2)
            {
                dp[i] += (dp[i - j] * 2);
            }
            dp[i] += 2;
        }
        printf("%d", dp[N]);
    }
}