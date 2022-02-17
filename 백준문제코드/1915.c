#include <stdio.h>
#include <stdlib.h>

int min(int x, int y, int z)
{
    if ((x <= y) && (x <= z))
    {
        return x;
    }
    else if ((y <= x) && (y <= z))
    {
        return y;
    }
    else if ((z <= x) && (z <= y))
    {
        return z;
    }
}

int main()
{
    int n, m, i, j;
    unsigned long long **dp;
    unsigned long long max;
    char num;

    scanf("%d %d", &n, &m);
    getchar();

    dp = (unsigned long long **)malloc(sizeof(unsigned long long *) * n);
    max = 0;

    for (i = 0; i < n; i++)
    {
        dp[i] = (unsigned long long *)malloc(sizeof(unsigned long long) * m);
        for (j = 0; j < m; j++)
        {
            scanf("%c", &num);
            if (num == '0')
            {
                dp[i][j] = 0;
            }
            else if (num == '1')
            {
                max = 1;
                dp[i][j] = 1;
            }
        }
        getchar();
    }

    for (i = 1; i < n; i++)
    {
        for (j = 1; j < m; j++)
        {
            if (dp[i][j] != 0)
            {
                dp[i][j] = dp[i][j] + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
                if (max < dp[i][j])
                {
                    max = dp[i][j];
                }
            }
        }
    }
    printf("%llu", max * max);
}