#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, K, i, j;
    int **dp;

    scanf("%d %d", &N, &K);

    dp = (int **)malloc(sizeof(int *) * (N + 1));
    dp[0] = (int *)malloc(sizeof(int) * 1);
    dp[0][0] = 1;

    for (i = 1; i <= N; i++)
    {
        dp[i] = (int *)malloc(sizeof(int) * (i + 1));
        dp[i][0] = 1;
        dp[i][1] = i;
        dp[i][i] = 1;
    }

    if (N <= 2)
    {
        printf("%d", dp[N][K]);
    }
    else
    {
        for (i = 3; i <= N; i++)
        {
            for (j = 2; j < i; j++)
            {
                if (i != j)
                {
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1])%10007;
                }
            }
        }

        // for (i = 0; i <= N; i++)
        // {
        //     for (j = 0; j <= i; j++)
        //     {
        //         printf("%d ", dp[i][j]);
        //     }
        //     printf("\n");
        // }
        printf("%d", dp[N][K]);
    }
}