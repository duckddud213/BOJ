#include <stdio.h>
#include <stdlib.h>

int cnt, sum;

typedef struct Queue
{
    int num, val;
} Queue;

int compare(const void *x, const void *y)
{
    int a = *(int *)x;
    int b = *(int *)y;

    if (a > b)
    {
        return 1;
    }
    else if (a < b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void backTracking(int *arr, Queue *que, int N, int S, int depth)
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        if (depth == 0)
        {
            if (que[0].val != 100001)
            {
                sum -= que[0].val;
            }
            que[0].val = arr[i];
            que[0].num = i;
            sum += arr[i];
        }
        else
        {
            for (j = 0; j < depth; j++)
            {
                if (que[j].num >= i)
                {
                    break;
                }
            }

            if (j == depth)
            {
                if (que[depth].val != 100001)
                {
                    sum -= que[depth].val;
                }
                que[depth].val = arr[i];
                que[depth].num = i;
                sum += arr[i];
            }
            else
            {
                continue;
            }
        }

        if (depth == N - 1)
        {
            if (sum == S)
            {
                cnt++;
            }
        }
        else
        {
            if (sum == S)
            {
                cnt++;
            }
            backTracking(arr, que, N, S, depth + 1);
            if (que[depth + 1].val != 100001)
            {
                sum -= que[depth + 1].val;
            }
            que[depth + 1].val = 100001;
        }
    }
}

int main()
{
    int N, S, i;
    int *arr;
    Queue *que;

    scanf("%d %d", &N, &S);

    arr = (int *)malloc(sizeof(int) * N);
    que = (Queue *)malloc(sizeof(Queue) * N);

    for (i = 0; i < N; i++)
    {
        scanf("%d", arr + i);
        que[i].val = 100001;
    }
    qsort(arr, N, sizeof(int), compare);

    cnt = 0;
    sum = 0;

    backTracking(arr, que, N, S, 0);

    printf("%d", cnt);
}