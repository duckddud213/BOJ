#include <stdio.h>
#include <stdlib.h>
int main()
{
    int N, K, i, j, x, sum;
    int **dp;

    scanf("%d %d", &N, &K);

    dp = (int **)malloc(sizeof(int *) * (N + 1));

    for (i = 0; i <= N; i++)
    {
        dp[i] = (int *)malloc(sizeof(int) * (K + 1));
        for (j = 0; j <= K; j++)
        {
            dp[i][j] = 0;
        }
        dp[i][1] = 1;
        if (i == 0)
        {
            for (j = 0; j <= K; j++)
            {
                dp[i][j] = 1;
            }
        }
    }

    //dp[i][j]=dp[i-1][j]+dp[i-1][j-1]+...+dp[i-1][0];

    for (i = 1; i <= N; i++)
    {
        for (j = 2; j <= K; j++)
        {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 1000000000;
        }
    }

    printf("%d", dp[N][K]);
}