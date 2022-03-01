#include <stdio.h>
#include <stdlib.h>

typedef struct greet
{
    int stamina, joy;
} Greet;

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
    int N, i, j;
    Greet *people;
    int **dp;

    scanf("%d", &N);

    people = (Greet *)malloc(sizeof(Greet) * (N + 1));
    dp = (int **)malloc(sizeof(int *) * (N + 1));

    for (i = 1; i <= N; i++)
    {
        scanf("%d", &people[i].stamina);
    }
    for (i = 1; i <= N; i++)
    {
        scanf("%d", &people[i].joy);
    }

    for (i = 0; i <= N; i++)
    {
        dp[i] = (int *)malloc(sizeof(int) * 100);
        dp[i][0] = 0;
        for (j = 1; j < 100; j++)
        {
            if (i == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                if (j - people[i].stamina >= 0)
                {
                    dp[i][j] = bigger(dp[i - 1][j], dp[i - 1][j - people[i].stamina] + people[i].joy);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    printf("%d", dp[N][99]);
}