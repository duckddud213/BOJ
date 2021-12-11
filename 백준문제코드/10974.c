#include <stdio.h>
#include <stdlib.h>

void backTracking(int *que, int N, int depth)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        if (depth == 0)
        {
            que[0] = i + 1;
        }
        else
        {
            for (j = 0; j < depth; j++)
            {
                if (que[j] == i + 1)
                {
                    break;
                }
            }

            if (j == depth)
            {
                que[depth] = i + 1;
            }
            else
            {
                continue;
            }
        }

        if (depth == N - 1)
        {
            for (j = 0; j < N; j++)
            {
                printf("%d ", que[j]);
            }
            printf("\n");
        }
        else
        {
            backTracking(que, N, depth + 1);
        }
    }
}

int main()
{
    int N;
    int *que;

    scanf("%d", &N);

    que = (int *)malloc(sizeof(int) * N);

    backTracking(que, N, 0);
}