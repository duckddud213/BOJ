#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M, i, j, sum, num;
    int **board;

    scanf("%d %d", &N, &M);

    board = (int **)malloc(sizeof(int *) * N);

    for (i = 0; i < N; i++)
    {
        board[i] = (int *)malloc(sizeof(int) * M);
        for (j = 0; j < M; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }

    sum = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (i + 3 < N)
            {
                num = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 3][j]; //1번
                if (sum < num)
                {
                    sum = num;
                }
            }
            if (j + 3 < M)
            {
                num = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i][j + 3]; //2번
                if (sum < num)
                {
                    sum = num;
                }
            }
            if ((i + 1 < N) && (j + 1 < M))
            {
                num = board[i][j] + board[i + 1][j] + board[i][j + 1] + board[i + 1][j + 1]; //3번
                if (sum < num)
                {
                    sum = num;
                }
            }
            if ((i + 2 < N) && (j + 1 < M))
            {
                num = board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 2][j + 1]; //4번
                if (sum < num)
                {
                    sum = num;
                }
                num = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 2][j + 1]; //5번
                if (sum < num)
                {
                    sum = num;
                }
                num = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i][j + 1]; //6번
                if (sum < num)
                {
                    sum = num;
                }
                num = board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j + 1]; //7번
                if (sum < num)
                {
                    sum = num;
                }
                num = board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 2][j]; //19번
                if (sum < num)
                {
                    sum = num;
                }
            }
            if ((i + 1 < N) && (j + 2 < M))
            {
                num = board[i][j] + board[i + 1][j] + board[i][j + 1] + board[i][j + 2]; //8번
                if (sum < num)
                {
                    sum = num;
                }
                num = board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2]; //9번
                if (sum < num)
                {
                    sum = num;
                }
                num = board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 1][j + 2]; //10번
                if (sum < num)
                {
                    sum = num;
                }
                num = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 2]; //11번
                if (sum < num)
                {
                    sum = num;
                }
                num = board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i][j + 2]; //18번
                if (sum < num)
                {
                    sum = num;
                }
            }
            if ((i + 2 < N) && (j - 1 >= 0))
            {
                num = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 2][j - 1]; //12번
                if (sum < num)
                {
                    sum = num;
                }
                num = board[i][j] + board[i + 1][j] + board[i + 1][j - 1] + board[i + 2][j - 1]; //13번
                if (sum < num)
                {
                    sum = num;
                }
                num = board[i][j] + board[i + 1][j] + board[i + 1][j - 1] + board[i + 2][j]; //17번
                if (sum < num)
                {
                    sum = num;
                }
            }
            if ((i - 1 >= 0) && (j + 2 < M))
            {
                num = board[i][j] + board[i][j + 1] + board[i - 1][j + 1] + board[i - 1][j + 2]; //14번
                if (sum < num)
                {
                    sum = num;
                }
                num = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i - 1][j + 2]; //15번
                if (sum < num)
                {
                    sum = num;
                }
                num = board[i][j] + board[i][j + 1] + board[i - 1][j + 1] + board[i][j + 2]; //16번
                if (sum < num)
                {
                    sum = num;
                }
            }
        }
    }
    printf("%d", sum);
}
