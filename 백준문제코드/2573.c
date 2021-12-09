#include <stdio.h>
#include <stdlib.h>

int year = 0;
int flag = 0;

typedef struct location
{
    int i, j;
} location;

int bigger(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

void isDivided(int **iceberg, int N, int M)
{
    location *que;
    location q;
    int i, j, idx, cnt, ins;
    int **isVisited;

    que = (location *)malloc(sizeof(location) * N * M);
    isVisited = (int **)malloc(sizeof(int *) * N);

    for (i = 0; i < N * M; i++)
    {
        que[i].i = -1;
        que[i].j = -1;
    }

    for (i = 0; i < N; i++)
    {
        isVisited[i] = (int *)malloc(sizeof(int) * M);
        for (j = 0; j < M; j++)
        {
            isVisited[i][j] = 0;
        }
    }

    idx = 0;
    cnt = 0;
    ins = 0;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            if ((iceberg[i][j] != 0) && (isVisited[i][j] == 0))
            {
                if (cnt != 0)
                {
                    flag = 1;
                    return;
                }

                que[ins].i = i;
                que[ins].j = j;
                ins++;
                cnt++;
                while ((que[idx].i != -1) && (que[idx].j != -1))
                {
                    q.i = que[idx].i;
                    q.j = que[idx].j;
                    isVisited[q.i][q.j] = 1;

                    if (q.i - 1 >= 0)
                    {
                        if ((iceberg[q.i - 1][q.j] != 0) && (isVisited[q.i - 1][q.j] == 0))
                        {
                            que[ins].i = q.i - 1;
                            que[ins].j = q.j;
                            ins++;
                            isVisited[q.i - 1][q.j] = 1;
                        }
                    }
                    if (q.i + 1 < N)
                    {
                        if ((iceberg[q.i + 1][q.j] != 0) && (isVisited[q.i + 1][q.j] == 0))
                        {
                            que[ins].i = q.i + 1;
                            que[ins].j = q.j;
                            ins++;
                            isVisited[q.i + 1][q.j] = 1;
                        }
                    }
                    if (q.j - 1 >= 0)
                    {
                        if ((iceberg[q.i][q.j - 1] != 0) && (isVisited[q.i][q.j - 1] == 0))
                        {
                            que[ins].i = q.i;
                            que[ins].j = q.j - 1;
                            ins++;
                            isVisited[q.i][q.j - 1] = 1;
                        }
                    }
                    if (q.j + 1 < M)
                    {
                        if ((iceberg[q.i][q.j + 1] != 0) && (isVisited[q.i][q.j + 1] == 0))
                        {
                            que[ins].i = q.i;
                            que[ins].j = q.j + 1;
                            ins++;
                            isVisited[q.i][q.j + 1] = 1;
                        }
                    }

                    idx++;
                }
            }
        }
    }

    free(que);
    for (i = 0; i < N; i++)
    {
        free(isVisited[i]);
    }
    free(isVisited);
}

void melting(int **beforeMelting, int **iceberg, int N, int M)
{
    int i, j, cnt;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            cnt = 0;
            if (beforeMelting[i][j] != 0)
            {
                if (i - 1 >= 0)
                {
                    if (beforeMelting[i - 1][j] == 0)
                    {
                        cnt++;
                    }
                }
                if (i + 1 < N)
                {
                    if (beforeMelting[i + 1][j] == 0)
                    {
                        cnt++;
                    }
                }
                if (j - 1 >= 0)
                {
                    if (beforeMelting[i][j - 1] == 0)
                    {
                        cnt++;
                    }
                }
                if (j + 1 < M)
                {
                    if (beforeMelting[i][j + 1] == 0)
                    {
                        cnt++;
                    }
                }
            }
            iceberg[i][j] = bigger(iceberg[i][j] - cnt, 0);
        }
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            beforeMelting[i][j] = iceberg[i][j];
        }
    }

    isDivided(iceberg, N, M);
}

int isAllMelt(int **iceberg, int N, int M)
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (iceberg[i][j] != 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int N, M, i, j;
    int **iceberg;
    int **beforeMelting;

    scanf("%d %d", &N, &M);

    iceberg = (int **)malloc(sizeof(int *) * N);
    beforeMelting = (int **)malloc(sizeof(int *) * N);

    for (i = 0; i < N; i++)
    {
        iceberg[i] = (int *)malloc(sizeof(int) * M);
        beforeMelting[i] = (int *)malloc(sizeof(int) * M);
        for (j = 0; j < M; j++)
        {
            scanf("%d", &iceberg[i][j]);
            beforeMelting[i][j] = iceberg[i][j];
        }
    }

    isDivided(iceberg, N, M);
    if (flag == 1)
    {
        printf("%d", 0);
    }
    else
    {
        while (flag == 0)
        {
            if (isAllMelt(iceberg, N, M))
            {
                printf("%d", 0);
                return 0;
            }
            melting(beforeMelting, iceberg, N, M);
            year++;
            if (flag != 0)
            {
                break;
            }
        }
        printf("%d", year);
    }
}