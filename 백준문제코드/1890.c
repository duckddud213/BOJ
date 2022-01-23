#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, j;
    int **board;
    unsigned long long **dp;

    scanf("%d", &N);

    board = (int **)malloc(sizeof(int *) * N);
    dp = (unsigned long long **)malloc(sizeof(unsigned long long *) * N);

    for (i = 0; i < N; i++)
    {
        board[i] = (int *)malloc(sizeof(int) * N);
        dp[i] = (unsigned long long *)malloc(sizeof(unsigned long long) * N);
        for (j = 0; j < N; j++)
        {
            scanf("%d", &board[i][j]);
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (dp[i][j] == 0)
            {
                continue;
            }
            if ((i == N - 1) && (j == N - 1))
            {
                break;
            }
            if (i + board[i][j] < N)
            {
                //dp[i + board[i][j]][j]++;
                dp[i + board[i][j]][j] += dp[i][j];
            }
            if (j + board[i][j] < N)
            {
                //dp[i][j + board[i][j]]++;
                dp[i][j + board[i][j]] += dp[i][j];
            }
        }
    }
    printf("%llu", dp[N - 1][N - 1]);
}