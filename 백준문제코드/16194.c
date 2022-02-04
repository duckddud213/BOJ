#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, j;
    int *pack, *dp;

    scanf("%d", &N);

    pack = (int *)malloc(sizeof(int) * (N + 1));
    dp = (int *)malloc(sizeof(int) * (N + 1));

    for (i = 1; i <= N; i++)
    {
        scanf("%d", pack + i);
    }
    dp[1] = pack[1];

    for (i = 2; i <= N; i++)
    {
        dp[i] = pack[i];
        for (j = 1; j < i; j++)
        {
            if (dp[i] > dp[i - j] + pack[j])
            {
                dp[i] = dp[i - j] + pack[j];
            }
        }
    }
    printf("%d", dp[N]);
}