#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
    int W, V;
} Items;

int bigger(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

int main()
{
    int N, K, i, j;
    int **dp;
    Items *bag;

    scanf("%d %d", &N, &K);
    // dp[N][K] : 용량이 K인 가방에 N번째 물건까지 넣었을때 최대 가치의 합
    dp = (int **)malloc(sizeof(int *) * (N + 1));
    bag = (Items *)malloc(sizeof(Items) * (N + 1));

    for (i = 1; i <= N; i++)
    {
        scanf("%d %d", &bag[i].W, &bag[i].V);
    }

    for (i = 0; i <= N; i++)
    {
        dp[i] = (int *)malloc(sizeof(int) * (K + 1));
        dp[i][0] = 0;
        for (j = 1; j <= K; j++)
        {
            if (i == 0)
            {
                dp[i][j]=0;
            }
            else
            {
                if (j - bag[i].W >= 0)
                {
                    dp[i][j] = bigger(dp[i - 1][j], dp[i - 1][j - bag[i].W] + bag[i].V);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    printf("%d", dp[N][K]);
}